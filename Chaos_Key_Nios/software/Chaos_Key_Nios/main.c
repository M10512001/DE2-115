/*
 * M10512001
 * Create: 2018/3/12
 */

#include <system.h>
#include <stdio.h>
#include <unistd.h>
#include <altera_avalon_pio_regs.h>

int main() {
	int num;
	float shift;
	unsigned u;
	// 檢視 Chaos_Key Generator 的狀態
	printf("step %d\n", IORD_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_STEP_BASE));
	printf("reset %d\n", IORD_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_RESET_BASE));
	printf("shift %X\n", IORD_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_SHIFT_BASE));
	printf("done %d\n", IORD_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_DONE_BASE));
	// 取得要計算的 STEP 次數，以及 SHIFT 值
	printf("Insert Number of Chaos Key Steps\n");
	scanf("%d", &num);
	printf("Insert Shift of Chaos Key\n");
	scanf("%f", &shift);
	// 將 SHFIT 的 Float 值轉為 16 進制值使 Chaos_Key Generator 可以辨識
	u = *(unsigned*)&shift;
	printf("%x\n", u);
	// 重置 Chaos_Key Generator 的狀態
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_STEP_BASE, 0);
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_RESET_BASE, 1);
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_RESET_BASE, 0);
	// 檢視 Chaos_Key Generator 的狀態
	printf("step %d\n", IORD_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_STEP_BASE));
	printf("reset %d\n", IORD_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_RESET_BASE));
	printf("done %d\n", IORD_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_DONE_BASE));
	// 向 Chaos_Key Generator 指定 SHIFT 值
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_SHIFT_BASE, u);
	// 檢視指定給 Chaos_Key Generator 的 SHIFT 值是否正確
	printf("shift %x\n", IORD_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_SHIFT_BASE));
	// 啟動 Chaos_Key Generator
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_STEP_BASE, 1);
	// 創建愈接收數量金鑰的動態陣列
	alt_u8 *list = malloc(num * sizeof(alt_u8));
	alt_32 i = 0;
	// 循環啟動 Chaos_Key Generator 運算金鑰，並存入動態陣列
	while(1) {
		if(IORD_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_DONE_BASE) == 0)
			continue;
		list[i] = IORD_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_X_BASE);
		i ++;
		if(i == num)
			break;
		list[i] = IORD_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_Y_BASE);
		i ++;
		if(i == num)
			break;
		list[i] = IORD_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_Z_BASE);
		i ++;
		if(i == num)
			break;
		list[i] = IORD_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_W_BASE);
		i ++;
		if(i == num)
			break;
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_STEP_BASE, 0);
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_STEP_BASE, 1);
	}
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_STEP_BASE, 0);
	printf("done\n");
	// 列出最後 4 個金鑰
	printf("%u, ", list[num-4]);
	printf("%u, ", list[num-3]);
	printf("%u, ", list[num-2]);
	printf("%u, ", list[num-1]);
	free(list);
	return 0;
}
