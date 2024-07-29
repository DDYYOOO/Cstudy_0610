#include"Function.h"

int Compare(char* str1, char* str2) 
{
	while (*str1)
	{
		if (*str1 != *str2)
		{
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str2 == '\0') 
	{
		return 1;
	}

	return 0;
}

void SearchMonsterName(Monster monster)
{
	char searchname[30];
	printf("�˻��� ������ �̸� �Է� : ");
	scanf_s("%s", searchname, 30);
	if (Compare(monster.name, searchname))
	{
		printf("�ش� ���͸� ã�ҽ��ϴ�.\n");
		printf("���� �̸� : %s, ���� ���� : %s , ���� ��� : %s\n", monster.name, monster.region, monster.grade);
	}
}

void AddMosnterInfo(Monster(*monster)[100], int* monsterIndexPtr)
{
	char newName[30];
	char region[30];
	char grade[30];
	printf("������ ������ �̸��� �Է� : ");
	scanf_s("%s", newName, 30);
	printf("������ ������ ������ �Է� : ");
	scanf_s("%s", region, 30);
	printf("������ ������ ����� �Է� : ");
	scanf_s("%s", grade, 30);

	strcpy_s(monster[*monsterIndexPtr]->name, 30, newName);
	strcpy_s(monster[*monsterIndexPtr]->region, 30, region);
	strcpy_s(monster[*monsterIndexPtr]->grade, 30, grade);

	(*monsterIndexPtr)++;
}

void ShowMonsterInfo(Monster monster)
{
	printf("������ �̸� : %s\n", monster.name);
	printf("������ ������ : %s\n", monster.region);
	printf("������ ��� : %s\n", monster.grade);
}