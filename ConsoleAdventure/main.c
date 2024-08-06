#include<stdio.h>
#include<stdbool.h>
#include"Console.h"

#define ROWS 30 // ���� 
#define COLS 30 // ���� Collums(���)
#define filename "playerData.txt"

char map2[COLS][ROWS] = {0};		// �� �ȿ� �ִ� ������
char mapString[(COLS * (ROWS + 1)) + 1];  // �����ͷκ��� ����ϴ� ���ڿ�
// ROWS + 1 : ���� ����\n�� ������ ��
// (COLS + ROWS) : 


void MakeMap(char Wall, char(*map)[ROWS]) // 2���� �迭 �ʿ� �����ϴ� ������ ����
{
	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 29; j++)
		{
			map[i][j] = ' ';
		}
	}

	for (int i = 0; i < COLS; i++)
	{
		map[i][0] = Wall;
		map[i][COLS - 1] = Wall;
	}

	for (int j = 0; j < ROWS; j++)
	{
		map[0][j] = Wall;
		map[ROWS - 1][j] = Wall;
	}

	for (int i = ROWS - 20; i >= ROWS - 24; i--)
	{
		map[ROWS - 20][i] = Wall;
	}

	for (int i = COLS - 20; i >= COLS - 25; i--)
	{
		map[i][COLS - 20] = Wall;
	}
}

void InWall(char Wall, char(*map)[ROWS])
{
	for (int i = ROWS - 20; i >= ROWS - 25; i--)
	{
		for (int j = COLS - 20; j >= COLS - 25; j--)
		{
			map[ROWS - 20][i] = Wall;
			map[i][COLS - 20] = Wall;
		}
	}
}

void RenderMap()
{
	int mapIndex = 0;

	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			mapString[mapIndex++] = map2[i][j];

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

void SeelectStartMenu()
{

}

void ShowGameRecord()
{
	printf("!!");
}

void GameInfo() // ������ ������ ����ϴ� �Լ��� �Ѱ�
{

}

typedef struct PlayerData
{
	char name[30];	// �̸��� �����ϱ� ���� �迭
	int score;	// ������ ������ ����

}PlayerData;


void SavePlayerData(PlayerData* player, int totalCount)
{
	FILE* fp = fopen(filename, "w");

	if (fp == NULL)
	{
		perror("���� ���� ����\n");
	}

	for (int i = 0; i < totalCount; i++)
	{
		fprintf(fp, "%s %d \n", player[i].name, player[i].score);
	}

	fclose(fp);

}

void LoadPlayerData(PlayerData* player, int* totalCount)
{
	FILE* fp = fopen(filename, "r");

	if (fp == NULL)
	{
		perror("���� �б� ����\n");
	}

	int count = 0;
	char ch;

	if (fgetc(fp) != EOF)
	{
		count = 1;
	}

	fseek(fp, 0, SEEK_SET); // fp�� ����Ű�� �ּҸ� ������ �������� �̵�

	while (fgetc(fp) != EOF)
	{
		ch = fgetc(fp);
		if (ch == '\n')
		{
			count++;
		}
	}

	fseek(fp, 0, SEEK_SET);

	*totalCount = count;

	for (int i = 0; i < count; i++)
	{
		fscanf_s(fp, "%s %d \n", (player + i)->name, 30, &(player + i)->score);
	}

	fclose(fp);
}

int main()
{
#if false	
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
#endif

	PlayerData allPlayerData[10];
	int totalCount = 0;
	
	LoadPlayerData(allPlayerData, &totalCount);
	printf("%s %d", allPlayerData[0].name, allPlayerData[0].score);

	SeelectStartMenu();

	printf("1. ���� ���� \n");
	printf("2. ���� ��� \n");
	printf("3. ���� ���� \n");
	int selectNum = 0;
	scanf_s("%d", &selectNum);
	if (selectNum == 1)
	{
		printf("������ �����߽��ϴ�\n");
	}
	else if (selectNum == 2)
	{
		ShowGameRecord();
	}
	else if (selectNum == 3)
	{
		exit(0);
	}
	else
	{
		printf("�߸��� ���� �Է��߽��ϴ�\n");
	}



	Clear();
	SetConsoleSize(50, 50);
	SetConsoleCursorVisibility(0);

	int playerX = 15, playerY = 15;		// �÷��̾��� ���� ��ǥ
	bool itemFound = false;	// �������� �߰��ϸ� true ����� �ش�	
	bool canMove = true; // canMove�� true�� �� ��������
	
	int itemX = 8, itemY = 8;

	// ���� �� ����

	// ���� �ܺ� ����
	MakeMap('#', map2);

	// ���� ������ 
	//InWall('#', map);

	RenderMap();



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

		if (canMove)
		{
			
		}
		else
		{

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