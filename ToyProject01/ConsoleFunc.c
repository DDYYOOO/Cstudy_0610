#include"ConsoleFunc.h"

void MainMenu(int playerinput)
{
	while (1)
	{
		printf("1. 게임 시작\n");
		printf("2. 게임 기록\n");
		printf("3. 게임 창정리\n");
		printf("4. 게임 종료\n");
		printf("숫자를 입력하세요 : ");
		scanf_s("%d", &playerinput);
		if (playerinput == 1)
		{
			printf("게임 시작");
		}
		if (playerinput == 2)
		{
			printf("게임 기록");
		}
		if (playerinput == 3)
		{
			system("cls");
		}
		if (playerinput == 4)
		{
			printf("게임을 종료했습니다");
			break;
		}
	}
}