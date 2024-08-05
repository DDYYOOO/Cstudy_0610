#include"ConsoleFunc.h"
#include<stdio.h>



void MakeMap(char Wall, char(*map)[ROWS])
{
	for (int i = 0; i < 79; i++)
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

void RenderMap()
{
	int mapIndex = 0;

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

int main()
{
	//int playerInput = 0;

	SetConsoleSize(80, 30);

	MakeMap('#', map);
	RenderMap();
	
	MenuInfo();

	MainMenu();


}