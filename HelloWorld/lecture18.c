/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-07-12
	�н���ǥ: �������� ����
*/

// 1. ������

#include"lectures.h"

void lectures18()
{
	int num = 10;			// ���� ����
	int* numPtr = &num;		// ������ ���� ���� �� �ּ� �ʱ�ȭ
	(*numPtr)++;			// ������ ������ : �ּҰ� ����Ű�� ���� ��ȯ
	printf("num�� �� : %d\n", *numPtr);	// num : 11

	// 16������ �����ͺ����� ���� �־ �ּ��� ���� ����
	int* numPtrA = 0x10000;
	int* numPtrB = 0x10000;
	numPtrA = numPtrA + 1; // numPtrA + 1;
	numPtrB = numPtrB + 2;
	printf("PtrA�� �� : %p\n", numPtrA); 
	printf("PtrB�� �� : %p\n", numPtrB);

	// �ּ��� ũ�⸦ ���ϴ� ���
	printf("������ ������ ũ�� : %d\n", sizeof(numPtrA)); // 86 : 4
	printf("������ ������ ũ�� : %d\n", sizeof(numPtrA)); // 64 : 8

	// ������ ������ ũ�Ⱑ �ٸ� ����
	// �ּҸ� �����ϴ� ����. ũ�⸦ ����
	// 16���� 1���� ����Ʈ ����. 8��(4��Ʈ * 8 = 32��Ʈ)
	// x86 : �� 32��Ʈ? - Intel�� 8086������ǻ�Ϳ��� 32��Ʈ ��Ű���� ���� ���� -> 86�� ���ͼ� x86 = 32��Ʈ ������ ����

	// int* -> 4����Ʈ ���� �ּҴ� ������ ù��° ����Ʈ�� ����, ���ۺ��� ũ����� ������ Ȯ���ؼ� ����

	// �����Ϳ� �迭
	int numArr[5] = {11, 22, 33, 44, 55};
				  //  0   1   2   3   4
	int index = 2;

	printf("numArr[5]�� 3��° �� : %d\n", numArr[index]);

	// index�� ���� ���ϱ� �Ǵ� ���� �����ڸ� ����ؼ� numArr�� �ݺ������� ���

	// ������ ���
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", numArr[i]);
	}
	printf("\n");
	// ������ ���
	for (int i = 4; i >= 0; i--)
	{
		printf("%d ", numArr[i]);
	}
	printf("\n");
	// �迭�� �����ͷ� �ٲٴ� ���
	int arr1[3] = {0, 1, 2};
	printf("�迭�� �̸� : %p\n", arr1);

	for (int i = 0; i < 3; i++)
	{
		printf("�迭�� ��� %d ��� : %p\n", i, &arr1[i]);
	}

	// �迭�� ù���� ����� ���� �ּҸ� ��ȯ�� �ߴ��� �� ������� �迭�� �̸��� �ּҿ� ����.

	// int ������ ���� + 1 : �ּ��� ���� 4��ŭ ũ�Ⱑ Ŀ��

	char* charPtr = 0x1000000;
	charPtr++;
	printf("%p\n", charPtr); // char 1����Ʈ
	short* shortPtr = 0x1000000;
	shortPtr++;
	printf("%p\n", shortPtr); // short 2����Ʈ

	// ������ ������ ����
	// sizeof(char)* : �������� ũ��
	charPtr += 10;		// 0x1000000 + 10(1x10)
	shortPtr += 10;		// 0x1000000 + 20(2x10)

	// int������ 10��ŭ ���� 4x10
	// ������ ������ sizeof(��������) x n(������ ��)ũ�Ⱑ ����

	// �迭���� ������ ������. &, *
	int arr2[3] = {0, 1, 2};
	// �迭�� �����ͺ����� ���� 
	int* s_Ptr = arr2;
	int* s_Ptr2 = &arr2[0];

	&arr2[0]; // �ּ� arr2 �迭 1��° �ּ�
	&arr2[1]; // �ּ� arr2 �迭 2��° �ּ�
	&arr2[2]; // �ּ� arr2 �迭 3��° �ּ�

	printf("�ּ��� ���� �� ������ �� : %d\n", *(s_Ptr + 1)); // s_Ptr �����ͺ��� s_Ptr����Ű���ִ� �ּҸ� 4 ����
	printf("������ �� �� : %d\n", (*s_Ptr2)++);
	printf("\n");

	//printf("�ּ��� ���� �� ������ �� : %d\n", *(s_Ptr++));

	// ����
	// ���̰� 5�� �迭 ���� firstArr[5]
	// firstArr�̸��� firstArrPtr ������ ������ �־��
	// firstArrPtr ������ �̿��ؼ� �ش� �ּ��� ���� 3�� ����
	// �ݺ����� ���
	int firstArr[5] = {1, 2, 3, 4, 5};
	int* firstArrPtr = firstArr; // �迭 ù��°�� �ּ� ������ �������� �ּҴ�
									 // ������ ����. �ּ��� ����. �ּ�
	for (int i = 0; i < 5; i++)
	{
		*firstArrPtr += 3; // firstArr[i] += 3;
		firstArrPtr++;	   // i++; 
	}

	for (int i = 0; i < 5; i++)
	{
		printf("firstArr�迭��ҿ� 3�� ���� ��Ų �� : %d\n", firstArr[i]);
	}
	printf("\n");
	// ����2 ������ ������ ������ ����ؼ� �迭�� ū �� ���� ���� �� ���
	int secondArr[5] = { 1, 2, 3, 4, 5 };
	int* secondArrPtr = secondArr;

	for (int i = 0; i < 5; i++)
	{
		*secondArrPtr -= 3; // firstArr[i] += 3;
		secondArrPtr++;	   // i++; 
	}

	for (int i = 4; i >= 0; i--)
	{
		printf("secondArr�迭�� �� : %d\n", firstArr[i]);
	}
	printf("\n");
	// *(Ptr)++;  <- �����Ͱ� ����Ű�� �ִ� ������ ��ȯ �� ���� 1�� ����  num = 10; 1�� ���ؼ� 11�� ��ȯ 
	// *(Ptr + 1); <- �����Ͱ� ����Ű�� �ִ� �ּ� typeũ�⸦ ���ؼ� ���� ����Ű�� �ִ� �ּҸ� ����

	int exArr[5] = {0};
	int* exArrPtr2 = exArr;
	printf("�迭�� ũ�� : %d\n", sizeof(exArr));
	printf("�������� ũ�� : %d\n", sizeof(exArrPtr2));

	// �ִ��� �޸𸮸� �Ʋ�����
	// arr[1000] -> 4 x 1000; 8��Ʈ

	printf("\n");
	// ����3 ���̰� 6�� �迭�� ���� �� 1,2,3,4,5... -> 6,5,4,3,.... �� ���
	int thirdArr[6] = {1, 2, 3, 4, 5, 6};
	int* thirdArrPtr = thirdArr;
	for (int i = 0; i < 6; i++)
	{
		printf("thirdArr�迭�� �� : %d\n", thirdArr[i]);
	}
	for (int i = 5; i >= 0; i--)
	{
		printf("thirdArr�迭�� �� : %d\n", thirdArr[i]);
	}
}