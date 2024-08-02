/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-08-02
	�н� ��ǥ : 
*/

// void�� ���� ���� - (1)�Լ��� ��ȯ��, (2)void Pointer
// Enum�� ���� ���� - (1)Enum�� �� �ʿ�����

// �Լ����� ��ȯ���� � ��?
// void : �����ϴ�, ����ִ� (�Լ��� ��ȯ���� ���Ǹ� ��ȯ��(Return Type)�� ����)

// Swap(int* a, int* b)(int temp; temp, *a, *b) : �� ������ �ٸ� ������ �־ �����͸� ��ȯ�Ѵ�
// void Swap : ���ڷ� �Ѱ��ִ� a��b�� ���� �������ְ� ����
// int Compare() : ������ 0 Ʋ���� 1�� ��ȯ�ϵ��� �ϸ�, if���̶� ���� ��� 

#include"lectures.h"

void Add_one(int* a)
{
	*a = *a + 1;
}

// ��ȯ���� �����ϴ� ���� : �����Ϸ��� �� �ڵ带 ������ ũ�⸦ �̸� �������ִ� ���

// void�� �޸� ������ �󸶳� ����Ǵ��� �� �� ��� void�� ������ ���� �� �� ����
// void* ������ �޸� ������ �󸶳� ����Ǿ��ִ��� �� �� ������?
// void* �ҿ����� �����̴�
// �޸� ������ �󸶳� �����ϴ��� ũ�⸦ �˷��ش�.  ����, �Ǽ�, ����ü

// ����
// int* : �޸� ������ 4byte�� Ȯ���ϰ�, �� ������ int �������� �����͸� ����
// void* : �޸� ������ 8byte�� Ȯ�������� � �������� �� 
// void*���� ����
// IntSwap, DoubleSwap�� ������ Ÿ�Ը� �ٸ� ������ �Լ����� ���̰� �ִ�
// �� �Լ����� Ÿ���� �����ؼ� �����ִ� �Լ��� ����� �ϳ��� ǥ�� �� �� �ִ�?
// Ÿ���� �������ִ� ��� -> void Pointer

#define TYPEOFINT 1
#define TYPEOFDOUBLE 2
#define TYPEOFFLOAT 3

// define INT DOUBLE FLOAT
// ����� �ѹ��� ǥ���ϴ� ��� : enumŰ���� ����

// ������ ENUM ����ϴ� ����
// 1. �ڵ� ������ ���� : ����� ǥ���ϴ� ������ �̸��� ��Ȯ�� � �������� �ҿ���, enum ����� �̸����� �����ϴ� ������ ���� TYPE -> ���3��(float, int, double)
// 2. ���ӽ����̽� ���� ���� : ����� ���ڷ� enum type�� ����� �� �ִ�
// ���������� ������ : ���ӽ����̽� ������ ���� ������ �Ǿ������Ƿ� ���׸� ã�� ����
// Ÿ�� �������� ���� : ����� �����͸� ���� ������ �ʿ� ���� enum type�� �����ϸ� ��

typedef enum TYPE { TYPE_char, TYPE_int, TYPE_double, TYPE_long_int }TYPE;		// TYPE_char : 0, TYPE_int : 1, TYPE_double : 2

void SwapValue(void* ptr1, void* ptr2, TYPE type)
{
	switch(type)
	{
		case TYPE_char:
		{
			char temp;
			temp = (*(char*)ptr1);
			(*(char*)ptr1) = (*(char*)ptr2);
			(*(char*)ptr2) = temp;
			break;
		}
		case TYPE_int:
		{
			int temp;
			temp = (*(int*)ptr1);
			(*(int*)ptr1) = (*(int*)ptr2);
			(*(int*)ptr2) = temp;
			break;
		}
		case TYPE_double:
		{
			double temp;
			temp = (*(double*)ptr1);
			(*(double*)ptr1) = (*(double*)ptr2);
			(*(double*)ptr2) = temp;
			break;
		}
		default:
			printf("�ش��ϴ� Ÿ���� �����ϴ�\n");
	}
}


void lectures27()
{
	int num = 1;	// �����Ϸ��� �̸� �޸� ������ 4byte�� Ȯ���ϰ� 2������ �ۼ��� 0101�����ͷκ��� ������ ����
	// void some;   // �����Ϸ��� �޸� ������ �󸶳� �����ؾ��ϴ��� �� �� ����
	Add_one(&num);
	printf("%d\n", num);

	void* voidPtr;	// ������ ������ 64��Ʈ �ý����� ��, 8����Ʈ ũ�⸦ Ȯ��
	printf("voidPtr�� ũ�� : %d\n", sizeof(voidPtr));

	double a = 1.1;
	voidPtr = &a;

	// voidPtr�� double* �������� type��ȯ
	printf("voidPtr�� ����Ű�� �� : %lf\n", (*(double*)voidPtr));

	char c1 = 'a';
	char c2 = 'b';
	SwapValue(&c1, &c2, TYPE_char);
	printf("c1 : %c, c2 : %c\n", c1, c2);

	int a1 = 1;
	int a2 = 2;
	SwapValue(&a1, &a2, TYPE_int);
	printf("a1 : %d, a2 : %d\n", a1, a2);

	double d1 = 1.1;
	double d2 = 2.2;
	SwapValue(&d1, &d2, TYPE_double);
	printf("d1 : %lf, d2 : %lf\n", d1, d2);

}