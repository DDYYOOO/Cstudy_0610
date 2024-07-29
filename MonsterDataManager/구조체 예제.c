#include<stdio.h>
#include<string.h>

typedef int MyInt;
typedef int* MyIntPtr;

typedef struct Monster
{
	char name[30];
	char region[30];
	char grade[30];
}Monster;

int Compare(char* str1, char* str2) // ��ȯ�ϴ� ���� 0�̸� �ٸ���, 1�̸� ����
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
	if (*str2 == '\0') // ������ 1�� ��ȯ
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

int main()
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