#include<stdio.h>
#include<stdbool.h>
#include"Console.h"

#define ROWS 30 // 가로 
#define COLS 30 // 세로 Collums(기둥)

char map[COLS][ROWS] = {0};		// 맵 안에 있는 데이터
char mapString[(COLS * (ROWS + 1)) + 1];  // 데이터로부터 출력하는 문자열
// ROWS + 1 : 개행 문자\n을 더해준 것
// (COLS + ROWS) : 


void MakeMap(char Wall, char(*map)[ROWS])
{
	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 29; j++)
		{
			map[i][j] = ' ';
		}
	}

	int mapIndex = 0;

	for (int i = 0; i < COLS; i++)
	{
		map[i][0] = '#';
		map[i][COLS - 1] = '#';
	}

	for (int j = 0; j < ROWS; j++)
	{
		map[0][j] = '#';
		map[ROWS - 1][j] = '#';
	}


	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			mapString[mapIndex++] = map[i][j];

		}
		mapString[mapIndex++] = '\n';
	}
	mapString[mapIndex] = '\0';
}

void InputProcess(int* x, int* y)
{

	if (GetAsyncKeyState(VK_LEFT) & 8001)  // 1이 되면 true
	{
		if (*x < 2)
			*x = 2;
		*x -= 1;

	}
	else if (GetAsyncKeyState(VK_RIGHT) & 8001)
	{
		if (*x > 27)
			*x = 27;
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
		if (*y > 28)
			*y = 28;
		*y += 1;
	}
}

void InteractOther(int* playerX, int* playerY, int* itemX, int* itemY, bool* itemFound)
{
	// 같은 위치
	if (*playerX == *itemX && *playerY == *itemY)
	{
		*itemFound = true;
	}
}

void GoToTargetPos(int a, int b, char* s)
{
	GotoXY(a, b);
	printf("%s", s);
}

void GameInfo() // 게임의 정보를 출력하는 함수를 총괄
{

}

int main()
{
#if true	
	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 29; j++)
		{
			map[i][j] = ' ';
		}
	}

	int mapIndex = 0;

	for (int i = 0; i < COLS; i++)
	{
		map[i][0] = '#';
		map[i][COLS - 1] = '#';
	}

	for (int j = 0; j < ROWS; j++)
	{
		map[0][j] = '#';
		map[ROWS - 1][j] = '#';
	}

	//for (int i = COLS - 20; i < COLS - 15; i++)
	//{
	//	i = '';
	//	printf("%c", );
	//}


	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			mapString[mapIndex++] = map[i][j];

		}
		mapString[mapIndex++] = '\n';
	}
	mapString[mapIndex] = '\0';
#endif

	Clear();
	SetConsoleSize(50, 50);
	SetConsoleCursorVisibility(0);

	int playerX = 15, playerY = 15;		// 플레이어의 시작 좌표
	bool itemFound = false;	// 아이템을 발견하면 true 만들어 준다	
	
	int itemX = 8, itemY = 8;

	// 게임 맵 생성
	//MakeMap();


	while (1)
	{
		Clear();
		GoToTargetPos(0, 0, mapString);
		GameInfo();
		GoToTargetPos(playerX, playerY, "@");

		InputProcess(&playerX, &playerY);		// 플레이어 이동
		InteractOther(&playerX, &playerY, &itemX, &itemY, &itemFound);  // 아이템이랑 플레이어 만났을 때

		if (!itemFound)
		{
			GoToTargetPos(itemX, itemY, "$");
		}
		else
		{
			GoToTargetPos(1, 31, "아이템을 획득했습니다");
		}

#if false
		for (int i = 0; i < 30; i++)
		{
			GoToTargetPos(i, 0, "#");
			GoToTargetPos(i, 29, "#");
			GoToTargetPos(0, i, "#");
			GoToTargetPos(29, i, "#");
		}
#endif
		
	

		
		Sleep(50);
	}

	


}