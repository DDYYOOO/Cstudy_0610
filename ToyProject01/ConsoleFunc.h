#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<stdbool.h>

#define TOTALMAPROWS 60
#define TOTALMAPCOLS 40
#define TOYROWS 40
#define TOYCOLS 39
#define toyfilename "toyPlayerData.txt"

typedef struct Player
{
	char name[30];
	int score;
	int playerX;
	int playerY;
	int playerbulletX;
	int playerbulletY;
	int level;
	int HP;
	int MP;

}Player;

typedef struct ToyMonster
{
	char name[30];
	char grade[30];
	int level;
	int HP;
	int MP;

}Monster;

void Clear(void);
void GotoXY(int _x, int _y);
void SetTitle(char* _szConsoleName);
void SetColor(unsigned char _BgColor, unsigned char _TextColor);
void SetConsoleCursorVisibility(int _bShow);
void SetConsoleSize(int _col, int _lines);

void MonsterData(Monster* monster, int Count);
void MakeMap(char Wall, char(*map)[TOYROWS]);
void RenderMap();
void GoToTargetPos(int a, int b, char* s);
void InputProcess(int* x, int* y);
void PlayerBullet(int* _x, int* _y);
void PlayerAndMonsterData();
void StartGame();
void ShowMenu();
