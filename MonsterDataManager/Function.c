#include"Function.h"


int Compare(char* str1, char* str2) 
{
	while (*str1)	// nullPtr������ ����
	{
		if (*str1 != *str2)
		{
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str2 == '\0') // *str2 == nullPtr
	{
		return 1;
	}

	return 0;
}

void SearchMonsterName(Monster monster[100], int* totalmonsterCount)
{
	char searchname[30];
	printf("�˻��� ������ �̸� �Է� : ");
	scanf_s("%s", searchname, 30);	// ���� �Ҵ�, ���α׷� ���� �� searchname�Լ� ������ ����.

	for (int i = 0; i < *totalmonsterCount; i++)
	{
		if (Compare(monster[i].name, searchname))
		{
			printf("�ش� ���͸� ã�ҽ��ϴ�.\n");
			printf("���� �̸� : %s, ���� ���� : %s , ���� ��� : %s\n", monster[i].name, monster[i].region, monster[i].grade);
		}
		else
		{
			printf("�ش� ���͸� ã�� ���߽��ϴ�\n");
		}
	}
}

void AddMosnterInfo(Monster monster[100], int* monsterIndexPtr)
{
	char newname[30];
	char newregion[30];
	char newgrade[30];
	printf("�߰��� ������ �̸��� �Է� : ");
	scanf_s("%s", newname, 30);
	printf("�߰��� ������ ������ �Է� : ");
	scanf_s("%s", newregion, 30);
	printf("�߰��� ������ ����� �Է� : ");
	scanf_s("%s", newgrade, 30);

	strcpy_s(monster[*monsterIndexPtr].name, 30, newname);
	strcpy_s(monster[*monsterIndexPtr].region, 30, newregion);
	strcpy_s(monster[*monsterIndexPtr].grade, 30, newgrade);

	(*monsterIndexPtr)++;
}

void ShowAllMonster(Monster monster[100], int total)
{
	for (int i = 0; i < total; i++)
	{
		printf("���� �̸� : %s, ���� ���� : %s, ���� ��� : %s \n", monster[i].name, monster[i].region, monster[i].grade);
	}
}