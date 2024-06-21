/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-06-19

	ù��° �н���ǥ : �ڵ�� 2���� 10���� 16���� �ۼ��ؼ� �����ͷ� �Ѱ��ֱ�
*/

// 2����, 8���� 16������ ǥ���ϴ� ��
// 2���� : "0b"2������ ǥ�� : 0b(+)1010; -> 10(2������ 10�� ǥ��)
// 8���� : "0"17 8������ ǥ�� 17 <- 1�� �ڸ����� 8�� ����ؼ� 8 + 7 = 15
// 10���� : 10�������� ǥ�� 0 <- 10�������� ǥ���Ѱ�
// 16���� : "0x"A 16������ ǥ��

// printf�� 8���� ǥ��(%o), 16���� ǥ��(%x)

// float �Ǽ�(�Ҽ���)

// �Ҽ��� ǥ���ϴ� ���
// ù��° ��� : ��Ʈ�� n : m���� ������ �� , n��ŭ ������ ����ϰ�, m��ŭ �Ҽ� �κ����� ���
// ������ : �Ҽ��� �ڼ��� ǥ���ϰ��� �ҷ���, ������ ǥ���� ������ �ʹ� ��������.
// �ذ��� : �Ҽ��� ����ǥ��������� ������� ����, 2e-1(2��-1��), 2e-2 �ڸ����� 0 �Ǵ� 1 ���� ���ؼ� ǥ���ϴ� ��� ����
// ���� �Ҽ���(Fixed Point)��� : ������ ǥ���ϴ� ��Ʈ ���� �Ҽ��� ǥ���ϴ� ��Ʈ ���� �������Ѽ� ǥ��
// �ε� �Ҽ���(Float Point) ��� : �Ҽ��� ǥ���ϴ� �������, ���� �κа� �Ҽ� �κ��� ������ ���� �Ҽ����� ����ϴ� ��ġ�� �����ϴ� ���

// 8.625�� �Ǽ��� ǥ��.  0b100.101
// 6.625555555555;

// ��Ʈ ǥ�� ���
// ��Ʈ ��ȣ : &, |, ^, ~
// ��Ʈ �̵�(shift) ��ȣ : >>, <<

// a & b : AND���� (1 = true, 0 = false)
//		   1 & 0 = 0;
//		   0 & 1 = 0;
//		   0 & 0 = 0;
//		   1 & 1 = 1;

// a | b : OR����
//		   1 | 0 = 1;
//		   0 | 1 = 1;
//		   0 | 0 = 0;
//		   1 | 1 = 1;

// a ^ b : XOR����
//		   0b1000
//		   0b1100
//		   0b0100

// a ~ : ���� (������� 0b0001 -> 0b1110)
// int num;
// num = ~num; ��Ʈ�� ������Ų��

// ��Ʈ ���� �̵� ������
// 8 << 2;
//	char	0b00000100; << 2	8 << 2(2e2) = 4 -> 32
//			0b00010000;
// 32 >> 3;
//			0b00010000; >> 3
//			0b00000010;			32 >> 3 -> 4



#include"lectures.h"

void lectures8()
{
	// ���� �̸� ����(int)a_num ������ ��, ���� 15 �־ ���
	int a_num = 15;
	printf("a_num�� �� : %d\n", a_num);

	a_num = 0b1111;
	printf("a_num�� 2���� ǥ������ 10������ ��� : %d\n", a_num);

	a_num = 017;
	printf("a_num�� 8���� ǥ������ 10������ ��� : %d\n", a_num);

	a_num = 0xF;
	printf("a_num�� 16���� ǥ������ 10������ ��� : %d\n", a_num);

	//%d ���, %o(8����), %x(16����) ����غ���

	a_num = 15;
	printf("a_num�� 8���� ǥ������ 10������ ��� : %o\n", a_num);

	a_num = 15;
	printf("a_num�� 16���� ǥ������ 10������ ��� : %x\n", a_num);


	// ���� 1. -255(2������ ǥ��)
	int b_num = -255; // 255�� 2�� ������ ��
					  // 255�� 2�������� ǥ�� 0b 00000000 00000000 00000000 11111111
					  // 255�� ǥ���� ����    0b 11111111 11111111 11111111 00000001
	b_num = 0b11111111111111111111111100000001;
	printf("b_num�� �� : %d\n", b_num);


	float a_float = 0.25;
	printf("a_float�� �� : %f\n", a_float);

	//0.1 + 0.2�� 0.3�� ������ ���� �����ڷ� ǥ��
	//true�� 1�� ���, false�� 0�� ���
	//int Bool; ���� ���� 0.1 + 0.2�� 0.3�� ������

	printf("�ε��Ҽ��� ����\n");

	int bool = (0.1 + 0.2) == 0.3; // 0.1 + 0.2 = 0.3�� �ƴϴ�
	printf("���̸� 1 �����̸� 0�� ��� : %d\n", bool);

	float c_num = 0.0;

	for (int number = 0; number < 30; number++)
		c_num += 0.1; // c_num = c_num + 0.1;
	
	printf("c_num�� 0.1�� 30�� ���� ���� �����ΰ��� : %f\n", c_num);


	printf("��Ʈ ���� ����\n");

	//�� ���� ���� ������ 2���� ǥ���� ���� �ִ�. d�� e�� ��Ʈ ���� ����� ��ȣ�� ������� �ʰ� ���
	int d = 0b0001111;
	int e = 0b0010010;
	int my_int = 0b0000010;
	int result = d & e;
	printf("���� ����� �� : %d, ���� �� : %d\n",my_int, result);

	d = 0b0001111;
	e = 0b0010010;
	my_int = 0b0011111;
	result = d | e;
	printf("���� ����� �� : %d, ���� �� : %d\n", my_int, result);

	d = 0b0001111;
	e = 0b0010010;
	my_int = 0b0011101;
	result = d ^ e;
	printf("���� ����� �� : %d, ���� �� : %d\n", my_int, result);

	char overFlowedValue = 0b01000000;
	//					   0b01000000; << 1
	//					   0b10000000; -128
	//					   0b01111111;
	//					   0b10000000;
	// 2�� ���� ���� + 1
	// char 1����Ʈ ũ�� ǥ���� �� �ִ� ���� ����
	// 1����Ʈ ���� ǥ���� �� �ִ� ���� ����, ��� ����
	// ���� ���� ���� : 0b[0][000][0000] ~ 0b[0][111][1111] : 0, 1 ~ 127
	// ���� ���� ���� : 0b[1][000][0000] ~ 0b[1][111][1111] : -128 ~ -1
	// -128 ~ 127 (-125 ~ 127) 256(2e8)

	//0b01000000 << 2;
	//overFlowedValue = 0b10000000; [0]
	//					0b00000100 >> 8; [0]

	overFlowedValue << 2; // � ���� ���ñ��?
	// printf ���
	printf("%d\n",overFlowedValue);

	overFlowedValue = 0b0000100;
	overFlowedValue << 5; // � ���� ���ñ��?
	// printf ���
	printf("%d\n", overFlowedValue);

	//10���� �ϳ� �Է� �޾Ƽ�, �ش� ���� 2�� ���� ���� ����ϴ� �ڵ带 �ۼ� (~)������ ���.
	int twocComplement;
	scanf_s("%d", &twocComplement);
	twocComplement = ~twocComplement + 1;
	printf("2�� ������ ���� ��� : %d\n", twocComplement);
	// ����Ʈ ����
	// 10���� �ϳ� �Է� �޾Ƽ�, �ش� ���� 8�� ���� �� 32�� ������ �ڵ带 x, /���� �ۼ�.
	// 8�� 32�� �ݵ�� �ڵ忡 ������ �ϰ� ��Ʈ ������ (>> , <<) ���.
	char shiftNum = 64; // 4
	//0b01000000;
	//scanf_s("%d", &shiftNum);
	//shiftNum <<= 3;
	//shiftNum = shiftNum << 3 >> 5; // 8�� ���� �� 32�� ������ -> 4�� ������.
	shiftNum = shiftNum << 3;
	shiftNum = shiftNum >> 5;
	printf("8�� ������ 12�� ���� �� : %d\n", shiftNum);
}