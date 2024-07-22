/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-07-22
	�н� ��ǥ : 
*/


#include"lectures.h"

void ChangeDoubleArrValue(int(*tPArr)[4], int addValue)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tPArr[i][j] += 1;
		}
	}
}

// char������� tpArr�� ���� �����ϴ� �Լ��� �ۼ�

void ChangeCharValueIndoubleArr(char(*tPArr)[4], char addChar)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tPArr[i][j] = addChar;
		}
	}
}

void lectures23()
{
	// ���� ���� : int num
	int num = 10;
	// ������ ����
	int* numPtr = &num;
	// �������� ������ ����
	int** numpPtr = &numPtr;

	printf("���� : %d, �����ͷκ��� �� ȣ�� : %d, �������� ������ �� ȣ�� : %d\n", num, *numPtr, **numpPtr);

	int Arr[3] = {1, 2, 3};
	int* aPtr = Arr;

	for (int i = 0; i < 3; i++)
	{
		printf("Arr�迭�� �� : %d ", *(aPtr + i));
	}
	printf("\n");

	// 2���� �迭

	int Arr2[3][4] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}

	};

	// �迭�� �ּҸ� �������� ��
	//int* pArr[3] = &Arr;
	//int(*pArr)[3] = &Arr;

	//int** doublePtr = &Arr2;

	// 2���� �迭�� �����Ϳ� �ֱ�
	// int (*������ �̸�)[����]; = ����ũ�Ⱑ n�� �迭�� ����Ű�� ������
	
	int(*pArr2)[4] = Arr2;
	int** doublePtr = Arr2;

	printf("Arr2�� �ּ� : %p\n", Arr2);
	printf("pArr2�� �ּ� : %p\n", pArr2);
	printf("doublePtr�� �ּ� : %p\n", doublePtr);

	// ������ ������ ũ�⸦ Ȯ��
	printf("Arr2�� ũ�� : %d\n", sizeof(Arr2));
	printf("pArr2�� ũ�� : %d\n", sizeof(pArr2));
	printf("doublePtr�� ũ�� : %d\n", sizeof(doublePtr));

	// 2���� �迭���� �迭�� �����ͷ� ǥ��
	int Arr3[3][4] = {0};
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("Arr3�� ���� �� : %d ",Arr3[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	ChangeDoubleArrValue(Arr3, 1);


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("Arr3�� ���� �� : %d ", Arr3[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	// Arr[x][y] == (*(Arr + x))[y] == (*(Arr + x) + y);  // A ġȯ : *(Arr + x) // A[y] // A�ٽ� ġȯ���� ����

	// 2���� �迭�� �����ͷ� ǥ���ϰ� ������ ���
	printf("2���� �迭�� �� : %d\n", Arr2[1][2]);
	printf("2���� �迭�� �����ͷ� ǥ���� �� : %d\n", *(*(Arr2 + 1) + 2));
	printf("2���� �迭���� ������ ũ���� �ּҸ� ����� �� : %p\n", (*(Arr2 + 1)));
	printf("2����......������ ũ�Ⱑ 1�̰�, �ű⼭ int ũ�⸸ŭ +2�� �ּ� �� : % p\n", (*(Arr2 + 1) + 2));
	printf("\n");

	// Arr[3][4] ���� Arr[i]�� �ǹ� : ũ�Ⱑ 4�� int�迭�� 3�� �ִµ� �� �߿��� i��° �迭�� �����Ѷ�
	// doublePtr : �ּ��� �ּҸ� Arr[3][4] ǥ�ø� ��������, 2���� �迭�� ǥ���� �� ����
	// 2���� �迭 : int(*Arr[����])[����]; 
	// �������� �迭 : int* Arr[ũ��] : ������ ������ �迭

	// ����
	// 2���� �迭�� �����ͷ� ǥ���ϱ� ���ؼ���, �ݵ�� �迭�� ������ �������� ��
	// ������Ÿ�� (*�����ͺ����̸�)(�迭ũ��) = ���� �������� �ּҸ� ������ �� ����

	//ChangeCharValueIndoubleArr�Լ��� ȣ���ؼ�, �ȿ� �ִ� ���� #, $ ���ϵ��� �ۼ�

	char map[3][4] = {0};

	ChangeCharValueIndoubleArr(map, '#');
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("map �� : %c ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	ChangeCharValueIndoubleArr(map, '$');
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("map �� : %c ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");



}