#include<stdio.h>
#include<string.h>

typedef struct Monster
{
	char name[30];
	char region[30];
	char grade[30];
	int level;

}Monster;

// 1. name, region, grade, level, 구조체 변수 선언해서 출력
// 2. 구조체 배열 만들고 반복문으로 배열 출력
// 3. 배열에다가 구조체 배열 데이터 넣기
// 4. char name[100][30] = Monster.name;

int AddMonster(char (*Monster_name)[30], char(*Monster_region)[30], char(*Monster_grade)[30], int level, int* totalCount, Monster* monsterPtr)
{

}

int SearchMonster()  // compare 함수 사용
{

}

int ShowAllMonster() // printf, for함수로 모든 요소 출력
{

}

int DeleteMonster() // 특정 배열 요소 검색해서 데이터가 있으면 해당 데이터를 null, 0변경
{

}

int main()
{
	int playerInput = 0;
	char monster_name[100][30];
	char monster_region[100][30];
	char monster_grade[100][30];
	int totalMonsterCount; // 몬스터 데이터에 몇번 Index에 저장되었는지
	int monster_level[100];
	
	Monster m1;
	//m1.name = "오크";
	m1.level = 5;


	while (1)
	{
		system("cls");
		printf("1.몬스터 데이터 추가\n");
		printf("2.몬스터 데이터 보기\n");
		printf("3.몬스터 데이터 삭제\n");
		printf("4.프로그램 종료\n");
		printf("메뉴를 선택하세요 : ");
		scanf_s("%d", &playerInput);

		// 1. 몬스터 데이터 추가
		if (playerInput == 1)
		{
			printf("프로그램 종료\n");
			break;
		}
		// 2. 몬스터 데이터 보기
		if (playerInput == 2)
		{
			printf("프로그램 종료\n");
			break;
		}
		// 3. 몬스터 데이터 삭제
		if (playerInput == 3)
		{
			printf("프로그램 종료\n");
			break;
		}
		// 4. 프로그램 종료
		if (playerInput == 4)
		{
			printf("프로그램 종료\n");
			break;
		}
	}




	return 0;

}