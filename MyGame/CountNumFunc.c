#include<stdio.h>
#include"CountNumFunc.h"
#include"Windows.h"

void startNumberSetting()
{

}


void GameWin()
{
	// 승리했을 때 색상을 붉은색으로 표시
	printf("컴퓨터이 값과 일치합니다, 축하합니다.\n");
}

int Fail(int playerHP)
{

}

void SetColor(unsigned char BGColor, unsigned char TextColor)
{
	if (BGColor > 15 || TextColor > 15) return;

	unsigned char ColorNum = (BGColor << 4) | TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}