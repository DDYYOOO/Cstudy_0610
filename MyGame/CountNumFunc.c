#include<stdio.h>
#include"CountNumFunc.h"
#include"Windows.h"

int InputNumber()
{
	int returnNumber;
	return scanf_s("%d", &returnNumber);
}

// �Լ��̸� ���� �����ϴ� ��� : Ctrl + R + R

// ���������� �� ����(Scope)�� ������ �� �޸𸮿��� ���ŵ˴ϴ�.

void StartGameSetting()
{
	int startValue;	
	printf("�١ڰ��� ���ۡڡ�\n");
	printf("���ڸ� �Է��ϸ� ������ �����մϴ� :");
	scanf_s("%d", &startValue);
}

int SetPlayerHP()
{
	printf("�÷��̾��� ü���� �Է� �ϼ��� : ");
	return InputNumber();
}

void GameWin()
{
	// �¸����� �� ������ ���������� ǥ��
	printf("��ǻ���� ���� ��ġ�մϴ�, �����մϴ�.\n");
}

int Fail(int playerHP)
{
	// � Ư���� ����, ü���� ���� ��
	int currentPlayHP = playerHP - 1;
	printf("�÷��̾��� ���� ü�� Ƚ�� : %d\n", currentPlayHP);
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