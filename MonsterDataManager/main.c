#include<stdio.h>
#include<string.h>
#include"Function.h"

// 1. name, region, grade, level, ����ü ���� �����ؼ� ���
// 2. ����ü �迭 ����� �ݺ������� �迭 ���
// 3. �迭���ٰ� ����ü �迭 ������ �ֱ�
// 4. char name[100][30] = Monster.name;


int main()
{
	int playerInput = 0;
	Monster monsterGroup[100];


	char monster_name[100][30];
	char monster_region[100][30];
	char monster_grade[100][30];
	int monster_level[100];

	int totalMonsterCount = 0; // ���� �����Ϳ� ��� Index�� ����Ǿ�����
	
	while (1)
	{
		//system("cls");
		printf("1.���� ������ �߰�\n");
		printf("2.���� ������ ����\n");
		printf("3.���� ������ ����\n");
		printf("4.���α׷� ����\n");
		printf("�޴��� �����ϼ��� : ");
		scanf_s("%d", &playerInput);

		// 1. ���� ������ �߰�
		if (playerInput == 1)
		{
			AddMosnterInfo(monsterGroup, &totalMonsterCount);
			
			printf("���α׷� ����\n");
			continue;
		}
		// 2. ���� ������ ����
		if (playerInput == 2)
		{
			printf("���α׷� ����\n");
			continue;
		}
		// 3. ���� ������ ����
		if (playerInput == 3)
		{
			printf("���α׷� ����\n");
			break;
		}
		// 4. ���α׷� ����
		if (playerInput == 4)
		{
			printf("���α׷� ����\n");
			break;
		}
	}

	return 0;

}