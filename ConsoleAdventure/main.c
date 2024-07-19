#include<stdio.h>
#include<stdbool.h>
#include"Console.h"

#define ROWS 30 // ���� 
#define COLS 30 // ���� Collums(���)

char map[COLS][ROWS] = {0};		// �� �ȿ� �ִ� ������
char mapString[(COLS * (ROWS + 1)) + 1];  // �����ͷκ��� ����ϴ� ���ڿ�
// ROWS + 1 : ���� ����\n�� ������ ��
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

	if (GetAsyncKeyState(VK_LEFT) & 8001)  // 1�� �Ǹ� true
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
	// ���� ��ġ
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

void GameInfo() // ������ ������ ����ϴ� �Լ��� �Ѱ�
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

	int playerX = 15, playerY = 15;		// �÷��̾��� ���� ��ǥ
	bool itemFound = false;	// �������� �߰��ϸ� true ����� �ش�	
	
	int itemX = 8, itemY = 8;

	// ���� �� ����
	//MakeMap();


	while (1)
	{
		Clear();
		GoToTargetPos(0, 0, mapString);
		GameInfo();
		GoToTargetPos(playerX, playerY, "@");

		InputProcess(&playerX, &playerY);		// �÷��̾� �̵�
		InteractOther(&playerX, &playerY, &itemX, &itemY, &itemFound);  // �������̶� �÷��̾� ������ ��

		if (!itemFound)
		{
			GoToTargetPos(itemX, itemY, "$");
		}
		else
		{
			GoToTargetPos(1, 31, "�������� ȹ���߽��ϴ�");
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