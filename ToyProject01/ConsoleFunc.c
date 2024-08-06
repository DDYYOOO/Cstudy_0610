#include"ConsoleFunc.h"


char toymap[TOYCOLS][TOYROWS] = { 0 };
char toymapString[(TOYCOLS * (TOYROWS + 1)) + 1];


void GotoXY(int _x, int _y)
{
	COORD pos = { _x, _y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetTitle(char* _szConsoleName)
{
	SetConsoleTitleA(_szConsoleName);
}

void SetColor(unsigned char _BgColor, unsigned char _TextColor)
{
	if (_BgColor > 15 || _TextColor > 15) return;

	unsigned short ColorNum = (_BgColor << 4) | _TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}

void SetConsoleCursorVisibility(int _bShow)
{
	CONSOLE_CURSOR_INFO curInfo;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (GetConsoleCursorInfo(hConsole, &curInfo))
	{
		curInfo.bVisible = _bShow;
		SetConsoleCursorInfo(hConsole, &curInfo);
	}
}

void SetConsoleSize(int _col, int _lines)
{
	char setText[100];
	sprintf_s(setText, 100, "mode con cols=%d lines=%d", _col, _lines);
	system(setText);
}

void PlayerInfo()
{
	char playerinfo;
	GotoXY(15, 15);
	printf("ID를 입력하세요 : ");
	scanf_s("%c", &playerinfo);
}

void PlayerData(Player* player, int Count)
{
	FILE* fp = fopen(toyfilename, "w");

	if (fp == NULL)
	{
		perror("ToyProject01-PlayerData Error\n");
	}

	for (int i = 0; i < Count; i++)
	{
		fprintf(fp, "%s %d \n", player[i].name, player[i].score);
	}

	fclose(fp);

}

void MonsterData(Monster* monster, int Count)
{

}


void MakeMap(char Wall, char(*map)[TOYROWS])
{
	for (int i = 0; i < TOYCOLS; i++)
	{
		for (int j = 0; j < TOYROWS; j++)
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
		if (*x > 35)
			*x = 35;
		*x += 2;
	}
	else if (GetAsyncKeyState(VK_UP) & 8001)
	{
		if (*y < 2)
			*y = 2;
		*y -= 2;
	}
	else if (GetAsyncKeyState(VK_DOWN) & 8001)
	{
		if (*y > 35)
			*y = 35;
		*y += 2;
	}
}

void PlayerBullet(int* _x, int* _y)
{
	int bulletX = 0, bulletY = 0;
	bool bullet = false;

	if (GetAsyncKeyState(VK_SPACE) & 8001)
	{
		if (!bullet)
		{
			bulletX = *_x;
			bulletY = *_y - 1;
			bullet = true;
		}
		if (bullet)
		{
			GoToTargetPos(bulletX, bulletY, "↑");
			bulletY--;

			if (bullet < 2)
			{
				bullet = false;
			}
		}
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
		GoToTargetPos(playerX, playerY, "■");
		InputProcess(&playerX, &playerY);
		PlayerBullet(&playerX, &playerY);

		GoToTargetPos(monsterX, monsterY, "$");

		PlayerAndMonsterData();


		Sleep(50);
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
		PlayerInfo();
		if (playerinput == 1)
		{
			StartGame(&playerX, &playerY);
		}
		else if (playerinput == 2)
		{
			ShowMenu();
		}

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
