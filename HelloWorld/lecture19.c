/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-07-15
	�н� ��ǥ :  �迭�� �������� ���� => "���"������ 
*/

// 1. �迭�� �������� ����
// sizeof(�迭), sizeof(������ ����) ������ ���� �ٸ��� ����
// �迭�� ��� �������̴�.

// 2. �����Ϳ� ���
// ����� ����Ű�� ������ pointer to constant
// ������ �� ��ü�� ��� constant pointer
// ����� ����Ű�� �� ��ü�� ����� ������ constantpointer to constant



#include"lectures.h"

void ShowData(const int* Ptr)
{
	const int* rPtr = Ptr;
	printf("%d\n", *rPtr);
	//*rPtr = 20;
}

voidShowAllData(int* const Arr, int len)
{
	//int* const tempArrPtr = Arr;
	for (int i = 0; i < len; i++)
	{
		printf("%d ", Arr[i]);
	}
	// for �ݺ������� arr�� ���� ��ŭ �迭��Ҹ� printf�Լ��� ����
}

void lectures19()
{
	const int s_num = 10;
	int* s_numPtr = &s_num;
	ShowData(s_numPtr);

	int s_Arr[4] = {1, 2, 3, 4};
	int* s_ArrPtr = s_Arr;
	voidShowAllData(s_ArrPtr, sizeof(s_Arr) / sizeof(int));  // sizeof(Arr) -> 4 * sizeof(int) / sizeof(int)

	printf("\n");

	// (1) sizeof ������
	int Arr[3] = {1, 2, 3};
	int* ArrPtr = Arr;   // int* ArrPtr = &Arr[0];

	printf("�迭�� ũ�� : %d\n", sizeof(Arr));		// sizeof(int) * 3 = 12
	printf("�������� ũ�� : %d\n", sizeof(ArrPtr));  // 64��Ʈ             8

	// �����ͷ� �ڵ带 �ۼ��ϸ� �Ǽ��� ���ɼ��� �������� �����ϱ⵵ ����
	// �޸𸮸� �ξ� ȿ�������� ����� �� �ִ�

	// ����� ����Ű�� ������ pointer to constant
	// num�� ���� �������� ���ϰ� ������
	// const int* ������ ������ �� ���� �������� ���Ѵ�. ������ ������ ���� ���ٲ۴�.
	const int num = 10;
	//num = 15;  // ����
	const int* numPtr = &num;  // in const* numPtr = &num;
	//*numPtr = 15; // ����

	// ������ �� ��ü�� ��� constant pointer
	int num1 = 20;
	int num2 = 30;
	int* const numCPtr = &num1;  // ��� �������� ����. �迭�� ��� ������.
	*numCPtr = 40;
	// numCPtr = &num2;          // ��� ������ . �ּҸ� �������� ���Ѵ�. 
								 // �迭�� ��� ������. �迭�� ���� �� �� �迭�� �ּҸ� ������ �� ����.
		
	// ����� ����Ű�� �� ��ü�� ����� ������ constantpointer to constant
	const int num3 = 40;
	const int num4 = 50;
	const int* const numCPtr2 = &num3;
	//*numCPtr2 = 50;          ����
	//numCPtr2 = &num4;        ����

	// ����
	// ������. ����
	// ���� - ��, �ּ�(&)
	// ������ - �ּ�, ��(*)

	// ������ ����
	// + const
	// �� const, �ּ� const
	// �� const - ��� ������(const pointer)
	// �ּ� const - ����� ����Ű�� ������(pointer to constant)
	// const �����Ϳ� ������� �ʴ� ����
	// ������ ������ ����� ������� �ʱ⸦ �����Ϸ� �ܰ迡�� �����ϱ� ���ؼ� (������ ����)


}