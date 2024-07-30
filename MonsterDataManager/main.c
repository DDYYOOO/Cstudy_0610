#include <stdio.h>
#include <string.h>
#include "Function.h"

// 1. name, region, grade, level, 구조체 변수 선언해서 출력
// 2. 구조체 배열 만들고 반복문으로 배열 출력
// 3. 배열에다가 구조체 배열 데이터 넣기
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

	int totalMonsterCount = 0; // 몬스터 데이터에 몇번 Index에 저장되었는지
	
	while (1)
	{
		//system("cls");
		printf("1. 몬스터 데이터 추가\n");
		printf("2. 몬스터 데이터 검색\n");
		printf("3. 몬스터 총 데이터 출력\n");
		printf("4. 몬스터 데이터 삭제\n");
		printf("5. 프로그램 창 정리\n");
		printf("6. 프로그램 종료\n");
		printf("메뉴를 선택하세요 : ");
		scanf_s("%d", &playerInput);

		// 1. 몬스터 데이터 추가
		if (playerInput == 1)
		{
			AddMosnterInfo(monsterGroup, &totalMonsterCount);
		}
		// 2. 몬스터 데이터 보기
		if (playerInput == 2)
		{
			SearchMonsterName(monsterGroup, &totalMonsterCount);
		}
		// 3. 몬스터 총 데이터 출력
		if (playerInput == 3)
		{
			ShowAllMonster(monsterGroup, totalMonsterCount);
		}
		// 4. 몬스터 데이터 삭제
		if (playerInput == 4)
		{

		}
		// 5. 프로그램 창 정리
		if (playerInput == 5)
		{
			system("cls");
		}
		// 6. 프로그램 종료
		if (playerInput == 6)
		{
			printf("프로그램 종료\n");
			break;
		}
	}

	return 0;

}