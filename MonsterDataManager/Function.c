#include"Function.h"


int Compare(char* str1, char* str2) 
{
	while (*str1)	// nullPtr만나면 종료
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
	printf("검색할 몬스터의 이름 입력 : ");
	scanf_s("%s", searchname, 30);	// 동적 할당, 프로그램 실행 뒤 searchname함수 공간에 저장.

	for (int i = 0; i < *totalmonsterCount; i++)
	{
		if (Compare(monster[i].name, searchname))
		{
			printf("해당 몬스터를 찾았습니다.\n");
			printf("몬스터 이름 : %s, 몬스터 지역 : %s , 몬스터 등급 : %s\n", monster[i].name, monster[i].region, monster[i].grade);
		}
		else
		{
			printf("해당 몬스터를 찾지 못했습니다\n");
		}
	}
}

void AddMosnterInfo(Monster monster[100], int* monsterIndexPtr)
{
	char newname[30];
	char newregion[30];
	char newgrade[30];
	printf("추가할 몬스터의 이름을 입력 : ");
	scanf_s("%s", newname, 30);
	printf("추가할 몬스터의 지역을 입력 : ");
	scanf_s("%s", newregion, 30);
	printf("추가할 몬스터의 등급을 입력 : ");
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
		printf("몬스터 이름 : %s, 몬스터 지역 : %s, 몬스터 등급 : %s \n", monster[i].name, monster[i].region, monster[i].grade);
	}
}