#include"ConsoleFunc.h"
#include<stdio.h>

#define TOTALMAPROWS 60
#define TOTALMAPCOLS 40
#define TOYROWS 40
#define TOYCOLS 39


char toymap[TOYCOLS][TOYROWS] = { 0 };
char toymapString[(TOYCOLS * (TOYROWS + 1)) + 1];

typedef struct Monster
{
	char name[30];
	char grade[30];
	int level;
	int HP;
	int MP;
	
}Monster;


void MonsterData(Monster* monster, int Count)
{

}


void MakeMap(char Wall, char(*map)[TOYROWS])
{
	for (int i = 0; i < TOYCOLS; i++)
	{
		for (int j = 0; j < TOYROWS ; j++)
		{
			map[i][j] = ' ';
		}
	}
	// 게임 실행 맵
	for (int i = 0; i < TOYCOLS; i++)
	{
		map[i][0] = Wall;
		map[i][TOYCOLS] = Wall;
	}

	for (int j = 0; j < TOYROWS; j++)
	{
		map[0][j] = Wall;
		map[TOYROWS - 2][j] = Wall;
	}
}

void RenderMap()
{
	int mapIndex = 0;

	for (int i = 0; i < TOYCOLS; i++)
	{
		for (int j = 0; j < TOYROWS; j++)
		{
			toymapString[mapIndex++] = toymap[i][j];

		}
		toymapString[mapIndex++] = '\n';
	}
	toymapString[mapIndex] = '\0';

}

void GoToTargetPos(int a, int b, char* s)
{
	GotoXY(a, b);
	printf("%s", s);
}

void InputProcess(int* x, int* y)
{

	if (GetAsyncKeyState(VK_LEFT) & 8001)
	{
		if (*x < 3)
			*x = 3;
		*x -= 2;

	}
	else if (GetAsyncKeyState(VK_RIGHT) & 8001)
	{
		if (*x > 37)
			*x = 37;
		*x += 1;
	}
	else if (GetAsyncKeyState(VK_UP) & 8001)
	{
		if (*y < 2)
			*y = 2;
		*y -= 1;
	}
	else if (GetAsyncKeyState(VK_DOWN) & 8001)
	{
		if (*y > 36)
			*y = 36;
		*y += 1;
	}
}

void PlayerAndMonsterData()
{
	GotoXY(45, 1);
	printf("플레이어");
	GotoXY(41, 3);
	printf("이름 : ");
	GotoXY(41, 5);
	printf("점수 : ");
	GotoXY(41, 7);
	printf("HP : ");
	GotoXY(41, 9);
	printf("MP : ");
	GotoXY(45, 13);
	printf("몬스터");
	GotoXY(41, 15);
	printf("이름 : ");
	GotoXY(41, 17);
	printf("등급 : ");
	GotoXY(41, 19);
	printf("HP : ");
	GotoXY(41, 21);
	printf("MP : ");
}

void StartGame()
{
	int playerX = 15, playerY = 15;
	int monsterX = 15, monsterY = 5;
	MakeMap('#', toymap);
	RenderMap();

	while (1)
	{
		GoToTargetPos(0, 0, toymapString);
		GoToTargetPos(playerX, playerY, "@");
		InputProcess(&playerX, &playerY);

		GoToTargetPos(monsterX, monsterY, "$");

		PlayerAndMonsterData();

		Sleep(100);
	}
}

void ShowMenu()
{
	int playerinput = 0;
	int playerX = 15, playerY = 15;
	GotoXY(19, 15);
	printf("탄막 슈팅 게임\n");
	GotoXY(20, 17);
	printf("1. 게임 시작\n ");
	GotoXY(20, 18);
	printf("2. 게임 기록\n ");
	GotoXY(20, 19);
	printf("3. 게임 종료\n ");
	GotoXY(20, 20);
	printf("선택 : ");
	GotoXY(26, 20);
	scanf_s("%d", &playerinput);
	system("cls");
	if (playerinput == 1)
	{
		StartGame(&playerX, &playerY);
	}
	if (playerinput == 2)
	{
		printf("게임 기록\n");
	}
	if (playerinput == 3)
	{
		printf("게임 종료\n");
		exit(0);
	}
	else
	{
		GotoXY(17, 15);
		printf("잘못 입력했습니다");
		ShowMenu();
	}
}


int main()
{
	int playerinput = 0;
	int playerX = 15, playerY = 15;

	SetTitle("탄막 슈팅 게임 이동윤");
	SetConsoleCursorVisibility(0);
	SetConsoleSize(TOTALMAPROWS, TOTALMAPCOLS);

	SetColor(0, 15);
	ShowMenu();

}