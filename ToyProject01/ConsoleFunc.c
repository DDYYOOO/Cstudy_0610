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
	system("cls");
	char playerinfo[30];
	GotoXY(15, 15);
	printf("ID�� �Է��ϼ��� : ");
	scanf_s("%s", playerinfo);
	GotoXY(45, 2);
	printf("%s", playerinfo);
}

void PlayerData(Player* player, int *Count)
{
	//FILE* fp = fopen(toyfilename, "w");
	//
	//if (fp == NULL)
	//{
	//	perror("ToyProject01-PlayerData Error\n");
	//}
	//
	//for (int i = 0; i < Count; i++)
	//{
	//	fprintf(fp, "%s %d \n", player[i].name, player[i].score);
	//}
	//
	//fclose(fp);
	//
}

void MonsterData(Monster* monster, int Count)
{

}

void playerDead()
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
	// ���� ���� ��
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

	for (int i = 1; i < TOYROWS; i++)
	{
		map[TOYROWS - 7][i] = Wall;
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

void InputProcess(Player* player, bool playerbullet)
{

	if (GetAsyncKeyState(VK_LEFT) & 8001)
	{
		if (player->playerX < 3)
			player->playerX = 3;
		player->playerX -= 2;
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 8001)
	{
		if (player->playerX > 35)
			player->playerX = 35;
		player->playerX += 2;
	}
	else if (GetAsyncKeyState(VK_UP) & 8001)
	{
		if (player->playerY < 3)
			player->playerY = 3;
		player->playerY -= 2;
	}
	else if (GetAsyncKeyState(VK_DOWN) & 8001)
	{
		if (player->playerY > 30)
			player->playerY = 30;
		player->playerY += 2;
	}
	else if (GetAsyncKeyState(VK_SPACE) & 8001)
	{
		if (!playerbullet)
		{
			player->playerbulletX = player->playerX;
			player->playerbulletY = player->playerbulletY - 1;
			playerbullet = true;
		}

		if (playerbullet)
		{
			player->playerbulletY--;
			GoToTargetPos(player->playerbulletX, player->playerbulletY, "��");

			if (player->playerbulletY < 2)
			{
				playerbullet = false;
			}
		}

	}
}

void PlayerBullet(int* _x, int* _y, bool bullet)
{
	int bulletX = 0, bulletY = 0;

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
			GoToTargetPos(bulletX, bulletY, "��");
			bulletY--;
		
			if (bulletY < 2)
			{
				bullet = false;
			}
		}

	}
}

void PlayerAndMonsterData()
{
	GotoXY(45, 1);
	printf("�÷��̾�");
	GotoXY(41, 3);
	printf("�̸� : ");
	GotoXY(41, 5);
	printf("���� : ");
	GotoXY(41, 7);
	printf("HP : ");
	GotoXY(41, 9);
	printf("MP : ");
	GotoXY(45, 13);
	printf("����");
	GotoXY(41, 15);
	printf("�̸� : ");
	GotoXY(41, 17);
	printf("��� : ");
	GotoXY(41, 19);
	printf("HP : ");
	GotoXY(41, 21);
	printf("MP : ");
	GotoXY(4, 36);
	printf("�Ѿ� SPACE");
	GotoXY(20, 35);
	printf("��  ��");
	GotoXY(20, 36);
	printf("�Ʒ� ��");
	GotoXY(27, 35);
	printf("����  ��");
	GotoXY(27, 36);
	printf("������ ��");

}

void StartGame()
{
	Player p1;
	int monsterX = 15, monsterY = 5;
	bool playerbullet = false;
	MakeMap('#', toymap);
	RenderMap();

	while (1)
	{
		GoToTargetPos(0, 0, toymapString);
		GoToTargetPos(p1.playerX, p1.playerbulletY, "��");
		InputProcess(p1.playerX, p1.playerY, playerbullet);
		//PlayerBullet(&playerX, &playerY, playerbullet);


		if (GetAsyncKeyState(VK_SPACE) & 8001)
		{
			if (!playerbullet)
			{
				bulletX = playerX;
				bulletY = playerY - 1;
				playerbullet = true;
			}

			if (playerbullet)
			{
				bulletY--;
				GoToTargetPos(bulletX, bulletY, "��");

				if (bulletY < 2)
				{
					playerbullet = false;
				}
			}

		}

		GoToTargetPos(monsterX, monsterY, "$");

		PlayerAndMonsterData();

		if (playerX == monsterX && playerY == monsterY)
		{
			GoToTargetPos(playerX, playerY, "@");
			system("cls");
			GotoXY(23, 20);
			printf("�׾����ϴ�");
			break;
		}
		Sleep(50);
		
	}
}

void ShowMenu()
{
	char playerinfo[30];
	int totalCount = 0;
	int playerinput = 0;
	int playerX = 15, playerY = 15;
	GotoXY(19, 15);
	printf("ź�� ���� ����\n");
	GotoXY(20, 17);
	printf("1. ���� ����\n ");
	GotoXY(20, 18);
	printf("2. ���� ���\n ");
	GotoXY(20, 19);
	printf("3. ���� ����\n ");
	GotoXY(20, 20);
	printf("���� : ");
	GotoXY(26, 20);
	scanf_s("%d", &playerinput);
	system("cls");
	if (playerinput == 1)
	{
		StartGame();
	}
	if (playerinput == 2)
	{
		printf("���� ���\n");
	}
	if (playerinput == 3)
	{
		printf("���� ����\n");
		exit(0);
	}
	else
	{
		GotoXY(17, 15);
		printf("�߸� �Է��߽��ϴ�");
		ShowMenu();
	}
}
