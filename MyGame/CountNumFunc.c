#include<stdio.h>
#include"CountNumFunc.h"
#include"Windows.h"

void startNumberSetting()
{

}


void GameWin()
{
	// �¸����� �� ������ ���������� ǥ��
	printf("��ǻ���� ���� ��ġ�մϴ�, �����մϴ�.\n");
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