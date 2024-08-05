#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<Windows.h>

#define ROWS 30 
#define COLS 30 


char map[COLS][ROWS] = { 0 };
char mapString[(COLS * (ROWS + 1)) + 1];

typedef struct Monster
{
	char name[100];
	char bullet[100];
	int monsterHP;
	int Level;
}Monster;

void SetConsoleSize(int _col, int _lines);
void GotoXY(int _x, int _y);
void MenuInfo();
void MakeMap(char Wall, char(*map)[ROWS]);
void RenderMap();
void GameStart(int x, int y);
void MainMenu();