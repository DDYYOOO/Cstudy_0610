#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void Clear(void);
void GotoXY(int _x, int _y);
void SetTitle(char* _szConsoleName);
void SetColor(unsigned char _BgColor, unsigned char _TextColor);
void SetConsoleCursorVisibility(int _bShow);
void SetConsoleSize(int _col, int _lines);

