#include<stdio.h>
#include<string.h>

typedef struct Monster
{
	char name[30];
	char region[30];
	char grade[30];
	int level;

}Monster;

// 1. name, region, grade, level, ����ü ���� �����ؼ� ���
// 2. ����ü �迭 ����� �ݺ������� �迭 ���
// 3. �迭���ٰ� ����ü �迭 ������ �ֱ�
// 4. char name[100][30] = Monster.name;

int AddMonster(char (*Monster_name)[30], char(*Monster_region)[30], char(*Monster_grade)[30], int level, int* totalCount, Monster* monsterPtr)
{

}

int SearchMonster()  // compare �Լ� ���
{

}

int ShowAllMonster() // printf, for�Լ��� ��� ��� ���
{

}

int DeleteMonster() // Ư�� �迭 ��� �˻��ؼ� �����Ͱ� ������ �ش� �����͸� null, 0����
{

}

int main()
{
	int playerInput = 0;
	char monster_name[100][30];
	char monster_region[100][30];
	char monster_grade[100][30];
	int totalMonsterCount; // ���� �����Ϳ� ��� Index�� ����Ǿ�����
	int monster_level[100];
	
	Monster m1;
	//m1.name = "��ũ";
	m1.level = 5;


	while (1)
	{
		system("cls");
		printf("1.���� ������ �߰�\n");
		printf("2.���� ������ ����\n");
		printf("3.���� ������ ����\n");
		printf("4.���α׷� ����\n");
		printf("�޴��� �����ϼ��� : ");
		scanf_s("%d", &playerInput);

		// 1. ���� ������ �߰�
		if (playerInput == 1)
		{
			printf("���α׷� ����\n");
			break;
		}
		// 2. ���� ������ ����
		if (playerInput == 2)
		{
			printf("���α׷� ����\n");
			break;
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