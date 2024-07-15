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
	int numArr[5] = { 11, 22, 33, 44, 55 };
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
	int arr1[3] = { 0, 1, 2 };
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
	int arr2[3] = { 0, 1, 2 };
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
	printf("����1\n");
	int firstArr[5] = { 1, 2, 3, 4, 5 };
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
	printf("����2\n");
	int secondArr[5] = { 1, 2, 3, 4, 5 };	// ������ �迭 5�� ���� �� �ʱ�ȭ
	int* secondArrPtr = secondArr;			// ������(�ּҸ� �����ϴ� ����) �迭�� �̸� ��ü�� ������. &secondArr : �ּ��� �ּ�
	secondArrPtr += 4;                      // ������ ���� +4 : sizeof(int)* n

	for (int i = 0; i < 5; i++)
	{
		printf("secondArr�迭�� �� : %d\n", *secondArrPtr);  // ���� �����ؼ� ����
		secondArrPtr--;	   // i--; 
	}
	printf("\n");
	// *(Ptr)++;  <- �����Ͱ� ����Ű�� �ִ� ������ ��ȯ �� ���� 1�� ����  num = 10; 1�� ���ؼ� 11�� ��ȯ 
	// *(Ptr + 1); <- �����Ͱ� ����Ű�� �ִ� �ּ� typeũ�⸦ ���ؼ� ���� ����Ű�� �ִ� �ּҸ� ����

	int exArr[5] = { 0 };
	int* exArrPtr2 = exArr;
	printf("�迭�� ũ�� : %d\n", sizeof(exArr));
	printf("�������� ũ�� : %d\n", sizeof(exArrPtr2));

	// �ִ��� �޸𸮸� �Ʋ�����
	// arr[1000] -> 4 x 1000; 8��Ʈ
	printf("\n");

	// ����2
	int o_Arr[3] = { 1, 2, 3 };
	int* o_ArrPtr = o_Arr;

	for (int i = 0; i < 3; i++)
	{
		printf("*(Ptr + i) : %d ", *(o_ArrPtr + i));
		printf("*(o_Arr + i) : %d ", *(o_Arr + i));
		printf("o_Arr[i] : %d ", o_Arr[i]);
		printf("Ptr[i] : %d\n", o_ArrPtr[i]);
	}

	// �迭�� �������� ����
	/*
	  (Ptr + 0) (Ptr + 1) (Ptr + 2) // ������ ���� �ּ��� ����
	  (Arr + 0) (Arr + 1) (Arr + 2) // �迭 �̸�(�ּ�) ����
	  Ptr[0] = *(Ptr + 0)
	  Arr[0] = *(Arr + 0)
	  Ptr[0] Ptr[1] Ptr[2]  // �ش� �ּ��� ���� ��� ������
	  Arr[0] Arr[1] Arr[2]  // �ش� �ּ��� ���� ��� ������
	  �迭�� ������ ������ ���� : arr[i] = *(arr + i)
	 */

	 // �߸��� �������� ��� : �� ������

	//int* ob_numPtrA = 0x100000;
	//printf("%p", ob_numPtrA);   // 0x1000000 �޸� �ּҿ� ���� �������� �ְ� �������� �ְ�
	//printf("%d", *ob_numPtrA);  // �����͸� ���� �ּ� �������ִ� ���� ����. ������ �߻��� ���ɼ��� �ſ� ����

	//int* ob_numPtrA = 0;
	//int* ob_numPtrA = NULL;  // nullPtr    NULL : �� ������. �� �ּҰ� �ƹ��͵� ����Ű�� ���� �ʴ�. 
	printf("\n");

	// ����3 ���̰� 6�� �迭�� ���� �� 1,2,3,4,5... -> 6,5,4,3,.... �� ���
	printf("����3\n");
	int t_Arr[6] = { 1, 2, 3, 4, 5, 6 };
	int* frontPtr = (t_Arr + 0);
	int* backPtr = (t_Arr + 5);
	int temp;

	printf("�ٲٱ� ������ �� \n");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", t_Arr[i]);
	}

	printf("\n");
	for (int i = 0; i < 3; i++) // �迭�� ���� (6) ������ 2 �� �� : 3
	{
		temp = *frontPtr;
		*frontPtr = *backPtr;
		*backPtr = temp;
		frontPtr++;
		backPtr--;
	}

	printf("�ٲٱ� ������ �� \n");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", t_Arr[i]);
	}
}
