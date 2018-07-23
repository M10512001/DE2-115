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
	// �˵� Chaos_Key Generator �����A
	printf("step %d\n", IORD_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_STEP_BASE));
	printf("reset %d\n", IORD_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_RESET_BASE));
	printf("shift %X\n", IORD_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_SHIFT_BASE));
	printf("done %d\n", IORD_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_DONE_BASE));
	// ���o�n�p�⪺ STEP ���ơA�H�� SHIFT ��
	printf("Insert Number of Chaos Key Steps\n");
	scanf("%d", &num);
	printf("Insert Shift of Chaos Key\n");
	scanf("%f", &shift);
	// �N SHFIT �� Float ���ର 16 �i��Ȩ� Chaos_Key Generator �i�H����
	u = *(unsigned*)&shift;
	printf("%x\n", u);
	// ���m Chaos_Key Generator �����A
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_STEP_BASE, 0);
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_RESET_BASE, 1);
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_RESET_BASE, 0);
	// �˵� Chaos_Key Generator �����A
	printf("step %d\n", IORD_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_STEP_BASE));
	printf("reset %d\n", IORD_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_RESET_BASE));
	printf("done %d\n", IORD_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_DONE_BASE));
	// �V Chaos_Key Generator ���w SHIFT ��
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_SHIFT_BASE, u);
	// �˵����w�� Chaos_Key Generator �� SHIFT �ȬO�_���T
	printf("shift %x\n", IORD_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_SHIFT_BASE));
	// �Ұ� Chaos_Key Generator
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_CHAOS_STEP_BASE, 1);
	// �ЫطU�����ƶq���_���ʺA�}�C
	alt_u8 *list = malloc(num * sizeof(alt_u8));
	alt_32 i = 0;
	// �`���Ұ� Chaos_Key Generator �B����_�A�æs�J�ʺA�}�C
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
	// �C�X�̫� 4 �Ӫ��_
	printf("%u, ", list[num-4]);
	printf("%u, ", list[num-3]);
	printf("%u, ", list[num-2]);
	printf("%u, ", list[num-1]);
	free(list);
	return 0;
}
