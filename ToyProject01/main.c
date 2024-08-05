#include"ConsoleFunc.h"
#include<stdio.h>

#define TOTALMAPROWS 60
#define TOTALMAPCOLS 40
#define TOYROWS 33
#define TOYCOLS 33


char toymap[TOYCOLS][TOYROWS] = { 0 };
char toymapString[(TOYCOLS * (TOYROWS + 1)) + 1];


void MakeMap(char Wall, char(*map)[TOYROWS]) 
{
	for (int i = 0; i < TOYCOLS; i++)
	{
		for (int j = 0; j < TOYROWS; j++)
		{
			map[i][j] = ' ';
		}
	}

	for (int i = 0; i < TOYCOLS; i++)
	{
		map[i][0] = Wall;
		map[i][TOYCOLS - 1] = Wall;
	}

	for (int j = 0; j < TOYROWS; j++)
	{
		map[0][j] = Wall;
		map[TOYROWS - 1][j] = Wall;
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
		if (*x > 30)
			*x = 30;
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
		if (*y > 30)
			*y = 30;
		*y += 1;
	}
}

void StartGame()
{
	int playerX = 15, playerY = 15;
	MakeMap('#', toymap);
	RenderMap();

	while (1)
	{
		GoToTargetPos(0, 0, toymapString);
		GoToTargetPos(playerX, playerY, "@");
		InputProcess(&playerX, &playerY);

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
	GotoXY(26, 23);
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