#include<stdio.h>
#include<string.h>
#include"Function.h"

typedef int MyInt;
typedef int* MyIntPtr;


int Main()
{
	MyInt myint = 4;
	printf("%d\n", myint);

	MyIntPtr myintPtr = &myint;
	printf("%d\n", *myintPtr);

	struct Monster m1;
	strcpy_s(m1.name, 30, "���");
	printf("���� �̸� : %s\n", m1.name);

	// ��(Compare) �Լ�
	char name1[30] = "ȫ�浿";
	char name2[30] = "ȫ�浿";
	
	if (Compare(name1, name2))
	{
		printf("����\n");
	}
	else
	{
		printf("�ٸ���\n");
	}

	// ����ü�� ������ ����
	// ����ü ������ �ּҿ����ڸ� ���
	Monster* monsterPtr = &m1;

	//
	Monster monsterGroup[100];
	int totalonsterCount = 0;

	// ��ȭ ����
	//int monstersize;
	//scnaf_s("%d", &monstersize);
	//Monster* monsterGPtr[400] = malloc(sizeof(Monster) * monstersize);
	//free(monsterGPtr);

	AddMosnterInfo(monsterGroup, &totalonsterCount);
	printf("���� �̸� : %s, ���� ��� : %s , ���� ���� : %s\n", monsterGroup[0].name, monsterGroup[0].grade, monsterGroup[0].region);

	//ShowMonsterInfo(m1);
	//SearchMonsterName(m1);
	
}