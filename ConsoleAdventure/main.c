#include<stdio.h>
#include<stdbool.h>
#include"Console.h"

char map[100] = "##########";

void GameInfo() // 게임의 정보를 출력하는 함수를 총괄
{
	//GoToTargetPos(1, 30, "아이템을 획득했습니다");
}


void InputProcess(int* x, int* y)
{

	if (GetAsyncKeyState(VK_LEFT) & 8001)  // 1이 되면 true
	{
		if (*x < 1)
			*x = 1;
		*x -= 1;

	}
	else if (GetAsyncKeyState(VK_RIGHT) & 8001)
	{
		if (*x > 28)
			*x = 28;
		*x += 1;
	}
	else if (GetAsyncKeyState(VK_UP) & 8001)
	{
		if (*y < 1)
			*y = 1;
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

int main()
{
	Clear();
	SetConsoleSize(50, 50);
	SetConsoleCursorVisibility(0);

	int playerX = 15, playerY = 15;		// 플레이어의 시작 좌표
	bool itemFound = false;	// 아이템을 발견하면 true 만들어 준다	
	
	int itemX = 8, itemY = 8;

	char map[100] = "########################";
	

	while (1)
	{
		Clear();
		GameInfo();
		GoToTargetPos(playerX, playerY, "@");

		InputProcess(&playerX, &playerY);		// 플레이어 이동
		InteractOther(&playerX, &playerY, &itemX, &itemY, &itemFound);  // 아이템이랑 플레이어 만났을 때

		if (!itemFound)  // 플레이어와 아이템 위치가 같을 때
		{
			GoToTargetPos(itemX, itemY, "$");
		}
		else
		{
			GoToTargetPos(1, 35, "아이템을 획득했습니다");
		}

		for (int i = 0; i < 30; i++)
		{
			GoToTargetPos(i, 30, "#");
			GoToTargetPos(30, i, "#");
		}

		
		Sleep(50);
	}

	


}