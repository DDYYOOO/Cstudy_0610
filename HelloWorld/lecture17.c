/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-07-11
	�н���ǥ : �����Ϳ� ���� ���� 
*/

// �������� ����
// (������ Ÿ��) * �̸�; 

// �����Ͷ�
// �����ͺ���, ���ϴ� ��(�ּ�)�� ����

// �޸𸮸� ���ϴ� ������ : �ּ� ������ &
// & ���� : ������ ���� �����ϰ� ���� �տ� ���. (&���� : ������ ������ �ִ� �ּҸ� ��ȯ)

// �ּҸ� 16���� 8�� or 16�� ��Ʈ ������ ����ؼ� �޸� �ּ� ǥ��
// �ּҸ� ǥ���� �� [16���� 4��Ʈ]
// 0xABCE0202 <- �ּ�(32��Ʈ)
// 0x00000000 ABCE020 <- �ּ�(64��Ʈ)

// �޸� �ּ� ����
// int* numPointer;(���� �� numPtr) 
// ������ ������ ����

// 



#include"lectures.h"

void lectures17()
{
	int num;
	scanf_s("%d", &num);
	printf("num�� �� ��� : %d\n", num);

	// �������� �ͼ�
	// ������ * ��ġ�� �������
	int* numPtr = &num;  // int* numPtr(������ ������ ����� �ʱ�ȭ) 
	int * numPtr2 = &num;
	int *numPtr3 = &num;
	// �����͸� ����ϸ� 16���� �ּҰ� ��µ�
	printf("%p\n",numPtr);
	printf("%p\n", numPtr2);
	printf("%p\n", numPtr3);
	
	// �ּҿ� ����� ���� ����ϴ� ���
	// ������ ������ 
	// '*' ���� ������ : ���ϱ�
	// ���� ������ : �̹� ����� �����ͺ��� �տ� *numPtr
	// numPtr ����Ű�� �ִ� ���� ����

	printf("%d\n", *numPtr);
	printf("%d\n", *numPtr2);
	printf("%d\n", *numPtr3);



	// �ǽ� ���� int number 20�� �Ҵ� ������ ������ ���� numberPtr ���� �� number�� �ִ� �ּҸ� �Ҵ�
	// printf�� ����ؼ� numberPtr�� �ִ� ���� ���( *������ ���)
	// ���� -> �� + �ּ�
	int number = 20;	// ���� number �ȿ��� 20�� ���� �ּҰ��� ���� �ִ� 

	// 1. ������ ������ �����ϴ� ��� : int*
	int* numberPtr;

	// 2. ������ �ּҸ� ��ȯ�ϴ� ������ (�ּ� ������ &)
	numberPtr = &number;
	printf("numberPtr �ȿ� �ִ� �ּҰ� : %p\n", numberPtr); // numberPtr�� �ּ� ��

	// 3. ������ ������ ����Ű�� �ִ� ����(������)�� ��ȯ�ϴ� ������ '*'
	printf("numberPtr �ȿ� �ִ� �� : %d\n", *numberPtr); // numberPtr�� ����(������) ��

	// ������ �ּҰ� ������ ��
	// �ּҸ� �̿��ؼ� ���� �����ϴ� �۾� (�ͼ��ؾ� ��)
	printf("���� number�� �� : %d\n", number);
	*numberPtr = 30;
	printf("number�� �� : %d\n", number);


	// ����
	// 1. ���� num1 = 10;			������ Ư¡ : �޸� �ּҸ� ���� ���� �������ų� ������ �� �ִ�.
	// 2. �ּ� ������ : ������ �޸� �ּҸ� ���ϴ� ������ (&num1 : �����κ��� �ּҸ� ���� �� ����)
	// 3. ������ ������ : '*' ������ ������ �����ϰ� �ִ� (�޸� �� ����Ű���ִ�) ���� ���� �� �� �ִ�.
	
	// int* numPtr << ������ ���� ����
	// *numPtr << ������ ���� ���� ���� ȣ��(������), numPtr�� ������ �����̴�.
	// *numPtr = 30;  << �����Ͱ� ����Ű�� �ִ� ���� ���� ����. 

	int a_num = 10;
	int* a_numPtr = &a_num;
	int* b_numPtr = a_numPtr;

	(*a_numPtr)++;
	(*b_numPtr)++;
	printf("%d\n", a_num);

	// ����
	// ���� �̸� e_num1, e_num2 ���� �� ���� 10, 20 �Ҵ�
	//  e_num1, e_num2�� ����Ű�� ������e_num1Ptr, e_num2Ptr�� ���� �� ����
	// int* temp�����͸� �ϳ� ����
	// temp�� e_num1Ptr����, e_num2 -> e_num1, e_num2 temp�� �޾ƿ���
	int e_num1 = 10, e_num2 = 20;
	int* e_num1Ptr = &e_num1;
	int* e_num2Ptr = &e_num2;
	printf("%d %d\n", *e_num1Ptr, *e_num2Ptr); // ������ �� ���

	// swap ����
	int* temp;
	temp = e_num1Ptr;
	e_num1Ptr = e_num2Ptr;
	e_num2Ptr = temp;
	printf("%d %d\n", *e_num1Ptr, *e_num2Ptr); // ������ �� ���

	// ����
	int exam_num1 = 50, exam_num2 = 30;
	int* temp_num = NULL;
	int* exam_num1Ptr = &exam_num1;
	int* exam_num2Ptr = &exam_num2;
	printf("%d %d\n", *exam_num1Ptr, *exam_num2Ptr);

	temp_num = exam_num1Ptr;
	exam_num1Ptr = exam_num2Ptr;
	exam_num2Ptr = temp_num;
	printf("%d %d\n", *exam_num1Ptr, *exam_num2Ptr);

}
