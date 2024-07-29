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
	printf("검색할 몬스터의 이름 입력 : ");
	scanf_s("%s", searchname, 30);
	if (Compare(monster.name, searchname))
	{
		printf("해당 몬스터를 찾았습니다.\n");
		printf("몬스터 이름 : %s, 몬스터 지역 : %s , 몬스터 등급 : %s\n", monster.name, monster.region, monster.grade);
	}
}

void AddMosnterInfo(Monster(*monster)[100], int* monsterIndexPtr)
{
	char newName[30];
	char region[30];
	char grade[30];
	printf("변경할 몬스터의 이름을 입력 : ");
	scanf_s("%s", newName, 30);
	printf("변경할 몬스터의 지역을 입력 : ");
	scanf_s("%s", region, 30);
	printf("변경할 몬스터의 등급을 입력 : ");
	scanf_s("%s", grade, 30);

	strcpy_s(monster[*monsterIndexPtr]->name, 30, newName);
	strcpy_s(monster[*monsterIndexPtr]->region, 30, region);
	strcpy_s(monster[*monsterIndexPtr]->grade, 30, grade);

	(*monsterIndexPtr)++;
}

void ShowMonsterInfo(Monster monster)
{
	printf("몬스터의 이름 : %s\n", monster.name);
	printf("몬스터의 서식지 : %s\n", monster.region);
	printf("몬스터의 등급 : %s\n", monster.grade);
}