/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-07-17
	�н� ��ǥ : �޸� ������ ���� ����, ���� �޸� �Ҵ�, ������ ���
*/

/*
  �ڵ� ����     : CPU�� �о� ���� ������ ���� ��Ų��. ��ɾ�� ���� 
  ������ ����   : ���� ����, static ���� ������ ������ ����
  �� ����       : �޸𸮸� �������� �����ؾ� �ϴ� ���� ����
  ���� ����     : �޸𸮰� �ڵ����� �����Ǵ� ���� ����
*/

// 1. ���� ���� : �Լ� ȣ�� call by value ������ ǥ���� ��, ���� ���� ������ä�� �ٸ� ����� ǥ���ϰ� ���� �� ���
// 2. ��   ���� : �ʿ��� ������ ���� ��ŭ �������ҷ� ������ ����

// ����, �� ������ ������ ����
// �޸� ������ ������

// ���� �÷ο�
// �� ���� �÷ο� : ���� ���� ������ ħ��
// ���� ���� �÷ο� : ������ �� ������ ħ��

// ��� �Լ� : �Լ��� �ڱ��ڽ��� ȣ���ϵ��� �� ��, ���� �ݺ�
// �� ���� �÷ο� ���� : malloc, free�Լ��� ���� �޸� �Ҵ� �� ����, 

#include"lectures.h"

void AllocateArrary(int count)
{
	int* newPtr = malloc(sizeof(int) * count);

	for (int i = 0; i < count; i++)
	{
		*(newPtr + i) = i + 1;
		printf("%d ", *(newPtr + i));
	}
	free(newPtr);
}


void lectures21()
{
	// ���� �޸� �Ҵ� �Լ� : malloc
	// memory + allocation : �޸� �Ҵ� �Լ� 
	// ������ ����  = malloc(ũ��);  �޸� ������ ũ��

	int num1 = 20;
	int* num1Ptr = &num1;
	int* const numPtr2 = malloc(4);
	*numPtr2 = num1;
	
	printf("%d\n", *numPtr2);

	// ���� �Ҵ��� �޸𸮴� �ݵ�� �����ؾ� ��
	// free
	free(numPtr2);
	printf("%d\n", numPtr2);

	int Arr[4] = {1, 2, 3, 4};
	int* numPtr3 = malloc(sizeof(int) * 4);  //  4 * 4 = 16
	numPtr3 = Arr;

	for (int i = 0; i < 4; i++)
	{
		printf("%d ", *(numPtr3 + i));
	}
	//free(numPtr3);
	printf("\n");

	// �������� ������ ������ ũ�⸦ �����ϴ� �Լ��� �ۼ�
	printf("���� ����\n");

	int count;
	scanf_s("%d", &count);
	AllocateArrary(count);
	
	printf("\n");
	// 

	char c = 69;	// 69�� �����Ǵ� ASII ���� �ϳ��� ���
	char c2 = 'a';
	printf("%d\n", c);
	printf("%c\n", c);

	//printf("Hello"); // H, e, l, l, o
	// ���ڿ�(string)
	char* s = "Hello";
	printf("%s\n", s);

	// ���ͷ� ���ڿ� : "������������"
	// ������ �ÿ� �ּҸ� ��ȯ(������ ���� ����)

	char sArr[5] = { 'H', 'e', 'l', 'l', 'o'};
	
	for (int i = 0; i < 5; i++)
	{
		printf("%c", sArr[i]);
	}
	printf("\n");

	char* s2 = "Hello World";
	printf("%s\n", s2);

	printf("���� : %c �ƽ�Ű�ڵ� : %d\n", *(s2 + 1), *(s2 + 1));	// e
	printf("���� : %c �ƽ�Ű�ڵ� : %d\n", *(s2 + 6), *(s2 + 6));	// W
	printf("���� : %c �ƽ�Ű�ڵ� : %d\n", *(s2 + 10), *(s2 + 10));  // d
	printf("���� : %c �ƽ�Ű�ڵ� : %d\n", *(s2 + 5), *(s2 + 5));    // ���� ���� ����
	printf("���� : %c �ƽ�Ű�ڵ� : %d\n", *(s2 + 11), *(s2 + 11));  // ���ڿ��� ���������� \'0' = NULL����.

	// NULL���� : ���ڿ��� �������� �˷��ֱ� ���� ����
	
	printf("NULL���ڸ� �̿��� ���ڿ� ���\n");

	int index = 0;
	
	while (*(s2 + index) != 0)  // ���ǹ� ����
	{
		printf("%c", *(s2 + index));
		index++;
	}


}