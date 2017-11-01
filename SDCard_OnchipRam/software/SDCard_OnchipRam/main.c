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

int main() {
	alt_u8 filename[20];
	alt_32 len;
	while(1) {
		while(SD_Card_Init() == false)
			usleep(3 * 1000 * 1000);
		printf("Info: Enter the name of the file you want to load\n");
		scanf("%s", filename);
		len = Get_File_Len(filename);
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
				// 列出記憶卡根目錄下的檔案
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
	// 得到檔案大小
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
