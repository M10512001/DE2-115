/*
 * main.c
 *
 *  Created on: 2017/11/3
 *      Author: M10512001
 */

#include <system.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <Altera_UP_SD_Card_Avalon_Interface.h>
#include <altera_up_avalon_video_pixel_buffer_dma.h>
#include <altera_avalon_uart_regs.h>

#define VGA_VL 640
#define VGA_HL 480
#define PACKET_LEN 2048

void Send_Mode();
void Receive_Mode();
bool SD_Card_Init();
void List_SD_Card_Files();
alt_32 Get_File_Len(alt_u8 *filename);
alt_u8 * File_Read_Into_List(alt_u8 *filename, alt_32 len);
void Write_BMP_Into_SD_Card(alt_u8 *list, alt_32 len);
bool Display_On_VGA(alt_u8 *list, alt_32 len);
bool Send_File(alt_u8 *list, alt_32 len);
alt_u8 * Receive_File(alt_32 *len);
alt_32 Get_Data_Len(alt_u8 *packet);
alt_32 Get_Packet_Len(alt_u8 *packet);

int main() {
	while (esp8266_init(true) == false)
		usleep(3 * 1000 * 1000);
	alt_16 reg;
	alt_u8 act;
	while(1) {
		while(SD_Card_Init() == false)
			usleep(3 * 1000 * 1000);
		Send_Mode();
		//Receive_Mode();
	}
	return 0;
}

void Send_Mode() {
	alt_u8 filename[20];
	alt_32 len;
	alt_u8 *list;
	alt_32 i;
	printf("Info: Enter the name of the file you want to load\n");
	scanf("%s", filename);
	len = Get_File_Len(filename);
	list = File_Read_Into_List(filename, len);
	for(i=0; i<57; i++)
		printf("%d,", list[i]);
	printf("\n");
	Display_On_VGA(list, len);
	Send_File(list, len);
	free(list);
	printf("\n");
}

void Receive_Mode() {
	alt_32 len;
	alt_u8 *list;
	list = Receive_File(&len);
	Display_On_VGA(list, len);
	Write_BMP_Into_SD_Card(list, len);
	free(list);
	printf("\n");
}

bool SD_Card_Init() {
	alt_up_sd_card_dev *sd_card_dev = alt_up_sd_card_open_dev(SD_CARD_NAME);
	if(sd_card_dev != 0) {
		if(alt_up_sd_card_is_Present()) {
			if(alt_up_sd_card_is_FAT16()) {
				printf("Info: Card is FAT16.\n");
				// �C�X�O�Хd�ڥؿ��U���ɮ�
				List_SD_Card_Files();
				return true;
			} else
				printf("Info: Card is not FAT16.\n");
		} else
			printf("Info: Please Insert the SD Card\n");
	}
	return false;
}

void List_SD_Card_Files() {
	alt_8 root_filename[20];
	printf("Info: SD Card Root List\n");
	alt_16 first_file_result = alt_up_sd_card_find_first("/.", root_filename);
	if(first_file_result == 0) {
		printf("    (Info) ./%s\n", root_filename);
		while(alt_up_sd_card_find_next(root_filename) != -1)
			printf("    (Info) ./%s\n", root_filename);
	} else if(first_file_result == -1)
		printf("    (Info) No files were found.\n");
	else
		printf("    (Info) Invalid Directory or Partition is not FAT16.\n");
}

alt_32 Get_File_Len(alt_u8 *filename) {
	alt_16 sd_fileh;
	alt_16 byte;
	alt_32 count = 0;
	// �o���ɮפj�p
	sd_fileh = alt_up_sd_card_fopen(filename, false);
	while(1) {
		byte = alt_up_sd_card_read(sd_fileh);
		if( byte != -1)
			count += 1;
		else
			break;
	}
	alt_up_sd_card_fclose(sd_fileh);
	printf("Info: %s is %d bytes.\n", filename, count);
	return count;
}

alt_u8 * File_Read_Into_List(alt_u8 *filename, alt_32 len) {
	alt_16 sd_fileh;
	alt_32 i;
	// ���ɮפj�p�ЫذʺA�}�C�A�ñN�ɮ�Ū�J�}�C
	alt_u8 *list = malloc(len * sizeof(alt_u8));
	if(!list)
		printf("Info: List create failed.\n");
	else {
		sd_fileh = alt_up_sd_card_fopen(filename, false);
		for(i=0; i<len; i++)
			list[i] = alt_up_sd_card_read(sd_fileh);
		alt_up_sd_card_fclose(sd_fileh);
	}
	// �N�ʺA�}�C�����Ц^��
	return list;
}

void Write_BMP_Into_SD_Card(alt_u8 *list, alt_32 len) {
	alt_16 sd_fileh;
	alt_32 i;
	printf("Info: Save as BMP File ...");
	sd_fileh = alt_up_sd_card_fopen("save.bmp", false);
	for(i=0; i<len; i++) {
		alt_up_sd_card_write(sd_fileh, list[i]);
	}
	// �|�b�ɮ׵����ɤW�@�� 0x0 �� Byte�A�G���ϥ�
	// alt_up_sd_card_fclose(sd_fileh);
	printf(" Done!\n");
}

bool Display_On_VGA(alt_u8 *list, alt_32 len) {
	// �T�{ BMP �ɬO�_�� 24-bits ��m
	if(list[28] == 24)
		printf("    (Info) It's 24-bits BMP.\n");
	else {
		printf("    (Info) It's not 24-bits BMP.\n");
		printf("    (Info) Program only support 24bits BMP.\n");
		return false;
	}
	// �q���Y�ɨ��o������ƶ}�l�e�������q�A�ιϤ����e��
	// ���׬����� BMP �����ѹϤ����C�̧ǩ��W�s�F���t�h�Ϥ�
	alt_32 pixel_offset = list[13];
	alt_32 width = list[21], height = list[25];
	alt_32 i;
	for(i=0; i<3; i++) {
		pixel_offset = pixel_offset << 8;
		pixel_offset = pixel_offset | list[12-i];
		width = width << 8;
		width = width | list[20-i];
		height = height << 8;
		height = height | list[24-i];
	}
	bool inverse = false;
	if(height < 0) {
		inverse = true;
		height = abs(height);
	}
	printf("    (Info) Header and Table is %d bytes.\n", pixel_offset);
	printf("    (Info) %d x %d\n", width, height);
	// BMP ���C�x�s�A�U�C��C���� 0x0(B) �ܦC���׬� 4*n Bytes ��
	// Ū���U�C�ɡA�ݸ��L����Ϊ� Align Bytes
	alt_32 row_align = 4 - ((width * 3) % 4);
	if(row_align == 4) {
		printf("    (Info) Row align bytes is 0.\n");
		row_align = 0;
	} else
		printf("    (Info) Row align bytes is %d.\n", row_align);
	// �]�w X, Y �y�аѼơA�N�p��ѪR�ת��Ϥ��ܤ��A�W�L�ѪR�ת��Ϥ��a�k�W���
	alt_32 x_i = 0, x_f = VGA_VL - 1;
	alt_32 y_i = 0, y_f = VGA_HL - 1;
	if(width < VGA_VL) {
		x_i = ((VGA_VL - width) / 2) - 1;
		x_f = x_i + width;
	}
	if(height < VGA_HL) {
		y_i = ((VGA_HL - height) / 2) - 1;
		y_f = y_i + height;
	}
	// �аO�Ϥ������e�O�_�W�L�ѪR��
	alt_32 x_over = 0, y_over = 0;
	if(width > VGA_VL) {
		x_over = 1;
		printf("    (Info) %d pixels out of Width range.\n", width - VGA_VL);
	}
	if(height > VGA_HL) {
		y_over = 1;
		printf("    (Info) %d pixels out of Height range.\n", height - VGA_HL);
	}
	// �ˬd VGA �~�]�s�b�P�_�A�è��o�~�]�Ѽ�
	alt_up_pixel_buffer_dma_dev *pixel_buf_dev = alt_up_pixel_buffer_dma_open_dev(PIXEL_BUFFER_DMA_NAME);
	if(pixel_buf_dev == NULL)
		printf("Info: Could not open Pixel Buffer Device.\n");
	else
		printf("Info: Pixel Buffer Device opened Success.\n");
	// �M�ŵe��
	alt_up_pixel_buffer_dma_clear_screen(pixel_buf_dev, 0);
	printf("Info: Clear the Pixel Buffer.\n");
	// �]�w R, G, B ����Ū������l��m�A�ø��L���פW�W�L�ѪR�ת�����
	alt_32 bp, gp, rp;
	if(!inverse)
		bp = ((((height - VGA_HL) * width) * 3) * y_over) + pixel_offset;
	else
		bp = pixel_offset;
	gp = bp + 1;
	rp = gp + 1;
	// �e�׶W�L�ѪR�׮ɡA���ܤU�C�� R, G, B ��m�������q
	alt_32 x_pass = ((((width - VGA_VL) + 1) * 3) * x_over) + row_align;
	// �� BMP ���ץ��t�Ƚվ�C��ܶ���
	alt_32 x, y, y_break;
	alt_32 step = -1;
	if(!inverse) {
		step = -1;
		y = y_f;
		y_break = y_i;
	} else {
		step = 1;
		y = y_i;
		y_break = y_f;
	}
	// �N R, G, B ��X���M X, Y �y���I�W
	alt_32 b, g, r, pix;
	while((y != y_break)) {
		y += step;
		for(x=x_i; x<x_f; x++) {
			b = list[bp];
			g = list[gp];
			r = list[rp];
			pix = (r << 16) + (g << 8) + b;
			bp += 3;
			gp += 3;
			rp += 3;
			alt_up_pixel_buffer_dma_draw(pixel_buf_dev, pix, x ,y);
		}
		bp += x_pass;
		gp += x_pass;
		rp += x_pass;
	}
	printf("Info: Refresh Display Done!\n");
	return true;
}

bool Send_File(alt_u8 *list, alt_32 len) {
	alt_u8 ip[20], port[10];
	alt_32 i, j = 0;
	alt_32 EOF_Byte = len - 1;
	alt_u8 packet[2048];
	bool success = false;
	alt_u8 cmd_buffer[2048];
	printf("Info: Enter the Receiver's IPv4 Address.\n");
	scanf("%s", ip);
	printf("\n");
	printf("Info: Enter the Receiver's Data Port.\n");
	scanf("%s", port);
	printf("    (Info) Receiver is %s:%s.\n", ip, port);
	// �إ� TCP �s�u
	sprintf(cmd_buffer, "AT+CIPSTART=\"TCP\",\"%s\",%s", ip, port);
	success = esp8266_send_command(cmd_buffer);
	if(!success) {
		printf("    (Info) Failed to Create Session.\n");
		return false;
	}
	// �i�������ݧY�N�ǰe���ɮפj�p
	sprintf(packet, "FILE_LEN-%d", len);
	alt_32 str_len = strlen(packet);
	sprintf(cmd_buffer, "AT+CIPSEND=%d", str_len);
	success = esp8266_send_command(cmd_buffer);
	success = esp8266_send_data(packet, str_len);
	if(!success) {
		printf("    (Info) Failed to Inform Data Size.\n");
		return false;
	}
	// �}�l�o�e�ʥ]
	for(i=0; i<len; i++) {
		packet[j] = list[i];
		j += 1;
		// �J�촫��r���ɵo�e�ʥ]
		if(list[i] == 10) {
			sprintf(cmd_buffer, "AT+CIPSEND=%d", j);
			success = esp8266_send_command(cmd_buffer);
			success = esp8266_send_data(packet, j);
			j = 0;
		}
		// �ʥ] Buffer ���ɵo�e�ʥ]
		if(j == PACKET_LEN) {
			sprintf(cmd_buffer, "AT+CIPSEND=%d", j);
			success = esp8266_send_command(cmd_buffer);
			success = esp8266_send_data(packet, j);
			j = 0;
		}
		// �J���ɮ׵����ɵo�e�ʥ]
		if(i == EOF_Byte) {
			sprintf(cmd_buffer, "AT+CIPSEND=%d", j);
			success = esp8266_send_command(cmd_buffer);
			success = esp8266_send_data(packet, j);
		}
		if(!success) {
			printf("    (Info) Failed to Send Packet.\n");
			return false;
		}
	}
	// �o�e�ɮ׵����ܷN�аO�A���_�}�s��
	sprintf(cmd_buffer, "AT+CIPSEND=%d", 6);
	success = esp8266_send_command(cmd_buffer);
	success = esp8266_send_data("EOFEOF", 6);
	success = esp8266_send_command("AT+CIPCLOSE");
	if(!success) {
		printf("    (Info) Failed to Disconnect Session.\n");
		return false;
	} else {
		printf("    (Info) File sent Successfully.\n");
		return true;
	}
}

alt_u8 * Receive_File(alt_32 *len) {
	bool success = false;
	alt_u8 port[10];
	alt_u8 cmd_buffer[30];
	alt_u8 *packet;
	alt_32 i;
	// ���o�����ݪ� IP
	esp8266_send_command("AT+CIFSR");
	// �}�Ҧh�s�u�Ҧ��A�ú�ť���w�� Port
	printf("Info: Enter the Port Number to receive Data.\n");
	scanf("%s", port);
	success = esp8266_send_command("AT+CIPMUX=1");
	if(success)
		printf("    (Info) Server started Successfully.\n", port);
	else
		printf("    (Info) Failed to startup Server.\n");
	sprintf(cmd_buffer, "AT+CIPSERVER=1,%s", port);
	success = esp8266_send_command(cmd_buffer);
	if(success)
		printf("    (Info) Port %s is on Listening.\n", port);
	else
		printf("    (Info) Failed to open Port %s.\n", port);
	// �q�i���ǰe�ɮ��`��j�p���ʥ]����
	while(1) {
		packet = esp8266_listen();
		if(strstr(packet, "FILE_LEN-") != NULL) {
			*len = Get_Data_Len(packet);
			break;
		}
	}
	printf("    (Info) The File Size to be received is %d Bytes.\n", *len);
	// �Ѩ��o���ɮ��`��j�p�إ߰ʺA�}�C
	alt_u8 *list = malloc(*len * sizeof(alt_u8));
	// �N�ʥ]���e�̧Ǽg�J�}�C
	alt_32 packet_len;
	i = 0;
	alt_32 j;
	while(1) {
		// �J��ǰe�������_�}�s���аO�A�h���X�j��
		if(strstr(packet, "0,CLOSED") != NULL)
			break;
		packet = esp8266_listen();
		packet_len = Get_Packet_Len(packet);
		packet = strstr(packet, ":");
		for(j=1; j<=packet_len; j++) {
			list[i] = packet[j];
			i++;
		}
	}
	if(i == *len)
		printf("    (Info) File received Successfully.\n");
	else
		printf("    (Info) File transfer Interrupted at %d Bytes.\n", i);
	// ������ť�ݤf�P���A���A�æ^�ǰʺA�}�C
	success = esp8266_send_command("AT+CIPSERVER=0");
	success = esp8266_send_command("AT+CIPMUX=0");
	if(success)
		printf("    (Info) Server closed Successfully.\n", port);
	else
		printf("    (Info) Failed to close Server.\n", port);
	return list;
}

alt_32 Get_Data_Len(alt_u8 *packet) {
	alt_32 packet_len = Get_Packet_Len(packet);
	alt_32 digits = packet_len - 9;
	alt_32 i;
	alt_32 base = 1;
	for(i=1; i<digits; i++)
		base = base * 10;
	alt_32 char_value;
	alt_32 len = 0;
	alt_u8 *number = strstr(packet, "-");
	for(i=1; i<=digits; i++) {
		char_value = number[i] - '0';
		len = len + (char_value * base);
		base = base / 10;
	}
	return len;
}

alt_32 Get_Packet_Len(alt_u8 *packet) {
	alt_32 i;
	alt_32 char_value;
	alt_32 len = 0;
	alt_32 base = 1000;
	alt_32 total_base = 10000;
	for(i=7; i<12; i++) {
		if(packet[i] != ':') {
			char_value = packet[i] - '0';
			len = len + (char_value * base);
		} else
			break;
		base = base / 10;
		total_base = total_base / 10;
	}
	len = len / total_base;
	return len;
}