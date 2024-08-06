#include <stdio.h>
#include <string.h>
#include "Function.h"

#define filename "monsterManager.txt"

// 1. name, region, grade, level, ����ü ���� �����ؼ� ���
// 2. ����ü �迭 ����� �ݺ������� �迭 ���
// 3. �迭���ٰ� ����ü �迭 ������ �ֱ�
// 4. char name[100][30] = Monster.name;

void DeleteMonsterByName(Monster monster[100], int* totalCount)
{
	// 0,1,2,3,4.......0,1 <- ,3 2->�� ������
	// �迭�� �缱���ؼ� �������� �ٽ� �����͸� �Է�
	// ���� -> -1;
	// �� -> �������
}

void PrintMonsterList(Monster* monsterlist, int totalCount)
{
	FILE* fp = fopen(filename, "w");

	if (fp == NULL)
	{
		perror("MonsterManager-PrintMonsterList Error\n");
	}

	for (int i = 0; i < totalCount; i++)
	{
		fprintf(fp, "%s %s %s\n", monsterlist[i].name, monsterlist[i].region, monsterlist[i].grade);
	}

	fclose(fp);

}

void LoadMonsterData(Monster* monsterlist, int* totalCount)
{
	FILE* fp = fopen(filename, "r");

	if (fp == NULL)
	{
		perror("MonsterManager-LoadMonsterData Error\n");
	}

	int count = 0;
	char ch;

	if (fgetc(fp) != EOF)
	{
		count = 1;
	}

	fseek(fp, 0, SEEK_SET); // fp�� ����Ű�� �ּҸ� ������ �������� �̵�

	while (fgetc(fp) != EOF)
	{
		ch = fgetc(fp);
		if (ch == '\n')
		{
			count++;
		}
	}

	fseek(fp, 0, SEEK_SET);

	*totalCount = count;

	for (int i = 0; i < count; i++)
	{
		fscanf_s(fp, "%s %s %s\n", (monsterlist + i)->name, 30, (monsterlist + i)->region, 30, (monsterlist + i)->grade, 30);
	}

	fclose(fp);
}

int main()
{
	int playerInput = 0;
	Monster monsterGroup[100];


	//char monster_name[100][30];
	//char monster_region[100][30];
	//char monster_grade[100][30];
	//int monster_level[100];

	int totalMonsterCount = 0; // ���� �����Ϳ� ��� Index�� ����Ǿ�����
	
	LoadMonsterData(monsterGroup, &totalMonsterCount);

	while (1)
	{
		//system("cls");
		printf("1. ���� ������ �߰�\n");
		printf("2. ���� ������ �˻�\n");
		printf("3. ���� �� ������ ���\n");
		printf("4. ���� ������ ����\n");
		printf("5. ���α׷� â ����\n");
		printf("6. ���α׷� ����\n");
		printf("�޴��� �����ϼ��� : ");
		scanf_s("%d", &playerInput);

		// 1. ���� ������ �߰�
		if (playerInput == 1)
		{
			AddMosnterInfo(monsterGroup, &totalMonsterCount);
		}
		// 2. ���� ������ ����
		if (playerInput == 2)
		{
			SearchMonsterName(monsterGroup, &totalMonsterCount);
		}
		// 3. ���� �� ������ ���
		if (playerInput == 3)
		{
			ShowAllMonster(monsterGroup, totalMonsterCount);
		}
		// 4. ���� ������ ����
		if (playerInput == 4)
		{

		}
		// 5. ���α׷� â ����
		if (playerInput == 5)
		{
			system("cls");
		}
		// 6. ���α׷� ����
		if (playerInput == 6)
		{
			printf("���α׷� ����\n");
			break;
		}
	}

	PrintMonsterList(monsterGroup, totalMonsterCount);

	return 0;

}