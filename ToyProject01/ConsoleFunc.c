#include"ConsoleFunc.h"

void SetConsoleSize(int _col, int _lines)
{
	char setText[100];
	sprintf_s(setText, 100, "mode con cols=%d lines=%d", _col, _lines);
	system(setText);
}

void GotoXY(int _x, int _y)
{
	COORD pos = { _x, _y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void MenuInfo()
{
	GotoXY(28, 10);
	printf("�Ѿ� ���ϱ� ����\n");
	GotoXY(30, 12);
	printf("1. ���� ����\n");
	GotoXY(30, 13);
	printf("2. ���� ���\n");
	GotoXY(30, 14);
	printf("3. ���� ����\n");
	GotoXY(28, 15);
	printf("���ڸ� �Է��ϼ��� : ");

}

void GameStart(int x, int y)
{
	while (1)
	{
		system("cls");
		
		if (GetAsyncKeyState(VK_LEFT) & 8001)
		{
			if (x < 3)
				x = 3;
			x -= 2;
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 8001)
		{
			if (x > 30)
				x = 30;
			x += 2;
		}
		else if (GetAsyncKeyState(VK_UP) & 8001)
		{
			if (y < 3)
				y = 3;
			y -= 2;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 8001)
		{
			if (y > 26)
				y = 26;
			y += 2;
		}

		GotoXY(x, y);
		printf("@");
	
		Sleep(100);
	}
}

void ShowGameRecord()
{

}

void MainMenu()
{
	int playerinput = 0;
	int x = 20, y = 15;

	while (1)
	{
		scanf_s("%d", &playerinput);
		if (playerinput == 1)
		{
			
		}
		else if(playerinput == 2)
		{
			printf("���� ���");
		}
		else if(playerinput == 3)
		{
			printf("������ ����ƽ��ϴ�\n");
			exit(0);
		}
		else
		{
			printf("�߸��� ���� �Է��߽��ϴ�\n");
		}
	}
}