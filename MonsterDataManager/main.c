#include <stdio.h>
#include <string.h>
#include "Function.h"

// 1. name, region, grade, level, ����ü ���� �����ؼ� ���
// 2. ����ü �迭 ����� �ݺ������� �迭 ���
// 3. �迭���ٰ� ����ü �迭 ������ �ֱ�
// 4. char name[100][30] = Monster.name;

void DeleteMonsterByName(Monster monster[100], int* totalCount)
{
	
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

	return 0;

}