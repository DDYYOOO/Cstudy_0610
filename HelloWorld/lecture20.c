/*
	�ۼ��� : �̵���
	�ۼ��� : 2027-07-16
	�н� ��ǥ : �������� ���ڸ� �Լ��� ���, Call by Value�� Call by Reference�� ���� ����
*/

// �迭�� �Ű� ������ ���� ���� ������ ����

// �迭�� �����ϴ� �� : int Arr[10]; ó�� ������ �� ũ����� ����� ��� ��.
// ���� �� ũ�⿡ ���� ���Ѵ�.
// ������ �� ���� �ʱ�ȭ����� �Ѵ�.
void AddArrayElement(int* arr, int len, int add)	// �迭 ����� ���� n��ŭ ���ϴ� �Լ��� ����
{
	for (int i = 0; i < len; i++)
	{
		arr[i] += add;
		printf("%d ", arr[i]);
	}
}

// Call by Value vs Call by Reference
// �Լ��� ����� �� ���� ��ȯ
// return  - �� �������� �Լ��� �����Ű�� �Լ��� ȣ���� ������ ���ư�
// return 0  - �Լ��� �����ϴ� �������� 0�� ��ȯ

// ��ȯ���� ���� ��� : void
// ��ȯ���� �ִ� ��� : ��ȯ �ϰ� ���� ���������� �Է�

void Call_by_Value(int _num)
{
	_num += 10;
}

void Call_by_Reference(int* _numPtr)
{
	*_numPtr += 10;
}

// Call_by_Value ���� ���� ȣ�� : �Լ� ȣ�� �� �⺻������ �ܺο� ������ ���� ����
// �����ʹ� ������ �����ڸ� ����Ͽ� �ܺ� �ּҸ� �����ؼ� ���� ������ �� �ִ�.


#include"lectures.h"

void SquareByValue_20(int num)
{
	num = num * num;
	printf("�Լ� �ȿ��� ����� �� : %d\n", num);
}

void SquareByRef_20(int* numPtr)
{
	*numPtr *= *numPtr;
}

void ChangeElement_Value(int a, int b, int c)
{
	int temp;
	temp = a;
	a = b;
	b = c;
	c = temp;
	printf("Call_by_Value �� : %d %d %d \n", a, b, c);

}

void ChangeElement_Ref(int* a, int* b, int* c)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = *c;
	*c = temp;
	// a -> b, b -> c, c -> a ���� �����ϴ� �Լ�
}

// �������� : 
// �������� : { }(����) �ȿ� �ۼ��Ǵ� ����, { }�� ����� �� ���� �Ҹ�

int global_val_l20 = 30;	// ex) ����, ���� ó��

void DoublePointerCallByRef(int** ref)
{

	*ref = &global_val_l20;
}

void DecimalToBinaray(int num)
{
	int binaray[20] = {0};		
	int pos = 0;

	while (1)
	{
		binaray[pos] = num % 2;
		num = num / 2;
		pos++;
		
		if (num == 0)
			break;
	}

	for (int i = pos - 1; i >= 0; --i)
	{
		printf("%d ", binaray[i]);
	}
}

void lectures20()
{
	int Arr[3] = {1, 2, 3};
	AddArrayElement(Arr, 3, 5);
	printf("\n");

	int num = 10;
	int* numPtr = &num;

	Call_by_Value(num);
	printf("Call_by_Value num�� �� : %d\n", num);
	Call_by_Reference(numPtr);
	printf("Call_by_Reference num�� �� : %d\n", num);

	printf("���� 1\n");
	int b = 3;
	int* bPtr = &b;
	SquareByValue_20(b);		// ���� ���� �ȵ�
	printf("b�� �� : %d\n", b);
	SquareByRef_20(bPtr);	// ���� ������ �Ǽ� ���
	printf("b�� �� : %d\n", b);

	printf("���� 2\n");
	int t1 = 10, t2 = 20, t3 = 30;
	ChangeElement_Value(t1, t2, t3);
	ChangeElement_Ref(&t1, &t2, &t3);
	printf("%d %d %d\n", t1, t2, t3);

	printf("���� ������\n");		// ������(�ּ�)���� - �ּ�

	int p1 = 10;
	int p2 = 20;
	int* p1Ptr = &p1;
	int* p2Ptr = &p2;
	int* p3Ptr = NULL;

	// ���� ������ : �ּҷ� ����Ű�� �ִ� ������ �ּ� 
	p3Ptr = &global_val_l20;
	DoublePointerCallByRef(&p1Ptr);
	printf("%d\n", *p1Ptr);

	printf("���� 3\n");
	// 10������ 2������ ��ȯ�ؼ� ����ϴ� �Լ��� ���� ��
	int input;
	scanf_s("%d", &input);

	DecimalToBinaray(input);

	// 11�� 2������ ����� ��
	// 11/2 = 5 + 1
	// 5/2 =  2 + 1
	// 2/2 = 1 + 0
	// 1/2 = 0 + 1
	// 1011(2) = 1 + 2 + 0 + 8 = 11

}