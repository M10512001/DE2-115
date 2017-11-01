/*
 * main.c
 *
 *  Created on: 2017/10/26
 *      Author: M10512001
 */

#include <system.h>
#include <stdio.h>
#include <unistd.h>
#include <Altera_UP_SD_Card_Avalon_Interface.h>

bool SD_Card_Init();
void List_SD_Card_Files();
alt_32 Get_File_Len(alt_u8 *filename);
alt_u8 * File_Read_Into_List(alt_u8 *filename, alt_32 len);
void Write_BMP_Into_SD_Card(alt_u8 *list, alt_32 len);

int main() {
	alt_u8 filename[20];
	alt_32 len;
	alt_u8 *list;
	alt_32 i;
	while(1) {
		while(SD_Card_Init() == false)
			usleep(3 * 1000 * 1000);
		printf("Info: Enter the name of the file you want to load\n");
		scanf("%s", filename);
		len = Get_File_Len(filename);
		list = File_Read_Into_List(filename, len);
		for(i=0; i<57; i++)
			printf("%d,", list[i]);
		printf("\n");
		Write_BMP_Into_SD_Card(list, len);
		free(list);
		printf("\n");
	}
	return 0;
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