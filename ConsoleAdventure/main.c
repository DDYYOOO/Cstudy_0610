#include<stdio.h>
#include<stdbool.h>
#include"Console.h"

char map[100] = "##########";

void GameInfo() // ������ ������ ����ϴ� �Լ��� �Ѱ�
{
	//GoToTargetPos(1, 30, "�������� ȹ���߽��ϴ�");
}


void InputProcess(int* x, int* y)
{

	if (GetAsyncKeyState(VK_LEFT) & 8001)  // 1�� �Ǹ� true
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

int main()
{
	Clear();
	SetConsoleSize(50, 50);
	SetConsoleCursorVisibility(0);

	int playerX = 15, playerY = 15;		// �÷��̾��� ���� ��ǥ
	bool itemFound = false;	// �������� �߰��ϸ� true ����� �ش�	
	
	int itemX = 8, itemY = 8;

	char map[100] = "########################";
	

	while (1)
	{
		Clear();
		GameInfo();
		GoToTargetPos(playerX, playerY, "@");

		InputProcess(&playerX, &playerY);		// �÷��̾� �̵�
		InteractOther(&playerX, &playerY, &itemX, &itemY, &itemFound);  // �������̶� �÷��̾� ������ ��

		if (!itemFound)  // �÷��̾�� ������ ��ġ�� ���� ��
		{
			GoToTargetPos(itemX, itemY, "$");
		}
		else
		{
			GoToTargetPos(1, 35, "�������� ȹ���߽��ϴ�");
		}

		for (int i = 0; i < 30; i++)
		{
			GoToTargetPos(i, 30, "#");
			GoToTargetPos(30, i, "#");
		}

		
		Sleep(50);
	}

	


}