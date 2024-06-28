#include<stdio.h>
#include"CountNumFunc.h"
#include"Windows.h"

int InputNumber()
{
	int returnNumber;
	return scanf_s("%d", &returnNumber);
}

// 함수이름 쉽게 변경하는 방법 : Ctrl + R + R

// 지역변수는 그 범위(Scope)가 끝났을 때 메모리에서 제거됩니다.

void StartGameSetting()
{
	int startValue;	
	printf("☆★게임 시작★☆\n");
	printf("숫자를 입력하면 게임이 시작합니다 :");
	scanf_s("%d", &startValue);
}

int SetPlayerHP()
{
	printf("플레이어의 체력을 입력 하세요 : ");
	return InputNumber();
}

void GameWin()
{
	// 승리했을 때 색상을 붉은색으로 표시
	printf("컴퓨터이 값과 일치합니다, 축하합니다.\n");
}

int Fail(int playerHP)
{
	// 어떤 특별한 변수, 체력을 빼야 함
	int currentPlayHP = playerHP - 1;
	printf("플레이어의 남은 체력 횟수 : %d\n", currentPlayHP);
	return currentPlayHP;
}

void ConsoleClear()
{
	system("cls");
}

void SetColor(unsigned char BGColor, unsigned char TextColor)
{
	if (BGColor > 15 || TextColor > 15) return;

	unsigned char ColorNum = (BGColor << 4) | TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}