#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int InputNumber();			// 함수를 미리 선언해두는 방식
							// 컴파일러는 코드르 위에서부터 읽기 때문에, 미리 선언되어 있지 않은 함수를 호출할 수 없다
							// C언어에서는 이 함수를 나중에 사용한다


int main()
{
	// printf함수와 scanf함수를 시용해서 게임의 느낌을 만듦
	// 플레이어를 환영하는 텍스트를 출력 ☆★
	// printf(숫자를 입력하면 게임이 시작합니다)
	// scanf -> 입력을 받는다  커서가 멈춘상태로 대기하고 있다

	// 정수 또는 실수 데이터를 만들어서 컴퓨터가 생각하는 결과를 출력하고, 내가 생각하는 결과를 같이 출력하는 프로그램을 만들어 보세요


	// 0 ~ 15에 해당되는 색상을 이용해서 콘솔창 꾸며보기
	SetColor(0 , 15);

	//system("cls");
	
	StartGameSetting();

	srand(time(NULL));
	int computerValue = rand() % 100 + 1; // 1 ~ 100의 랜덤한 숫자가 computerValue에 입력이 된다.
	int userValue;
	int playerHP; // 지역 변수로 사용되면 그 값이 사라지기때문에 함수의 리턴과 동시에 변수에 할당

	playerHP = SetPlayerHP();

	printf("게임 시작!\n");

	printf("플레이어의 값을 입력하세요 : ");
	userValue = InputNumber();
	printf("컴퓨터의 랜덤한 값 : %d\n", computerValue);
	printf("플레이어의 입력 값 : %d\n", userValue);
	

	while (1)
	{
		if (computerValue > userValue)
		{
			printf("컴퓨터의 랜덤한 값 : %d가 플레이어의 입력 값 : %d보다 큽니다\n", computerValue, userValue);
		}
		else
		{
			printf("컴퓨터의 랜덤한 값 : %d가 플레이어의 입력 값 : %d보다 작습니다\n", computerValue, userValue);
		}

		if (computerValue == userValue)
		{
			// 함수화 1 : GameWin게임에서 승리를 구현하는 함수 구현
			GameWin();
			break;
		}
		else
		{
			// 만약 플레이어의 현재 체력이 0보다 작거나 같으면 게임을 종료
			if (playerHP <= 0)
			{
				printf("게임 종료\n");
				break;
			}
			// 함수화 2 : 플레이어의 체력을 감소 시키고 숫자를 다시 맞출 기회를 주는 코드를 함수화 

			// 플레이어의 체력을 감소시킨다.
			Fail();

			// 다시 플레이어의 맟출 기회를 줌
			printf("플레이어의 값을 입력하세요 : ");
			userValue = InputNumber();
		}
	}


	// if문을 이용한 랜덤한 숫자 맞추기 게임

	//if (computerValue != userValue)
	//{
	//	printf("틀렸습니다. 3번 남았습니다. 다시 입력하세요 :");
	//	scanf_s("%d", &userValue);
	//	printf("컴퓨터의 랜덤한 값 : %d\n", computerValue);
	//	printf("플레이어의 입력 값 : %d\n", userValue);
	//
	//
	//	if (computerValue != userValue)
	//	{
	//		printf("틀렸습니다. 2번 남았습니다. 다시 입력하세요 :");
	//		scanf_s("%d", &userValue);
	//		printf("컴퓨터의 랜덤한 값 : %d\n", computerValue);
	//		printf("플레이어의 입력 값 : %d\n", userValue);
	//
	//		if (computerValue != userValue)
	//		{
	//			printf("틀렸습니다. 1번 남았습니다. 다시 입력하세요 :");
	//			scanf_s("%d", &userValue);
	//			printf("컴퓨터의 랜덤한 값 : %d\n", computerValue);
	//			printf("플레이어의 입력 값 : %d\n", userValue);
	//			
	//			if (computerValue != userValue)
	//			{
	//				printf("틀렸습니다. 게임에서 패배했습니다\n");
	//			}
	//			else
	//			{
	//				printf("축하합니다. 게임에서 이겼습니다.\n");
	//			}
	//		}
	//		else
	//		{
	//			printf("축하합니다. 게임에서 이겼습니다.\n");
	//		}
	//	}
	//	else
	//	{
	//		printf("축하합니다. 게임에서 이겼습니다.\n");
	//	}
	//}
	//else
	//{
	//	printf("축하합니다. 게임에서 이겼습니다.\n");
	//}

	// for문을 이용한 랜덤한 숫자 맞추기 게임

	//int counter = 0;
	//int life = 5;
	
	//for (; ;)
	//{
	//	life--;
	//
	//	if (computerValue != userValue)
	//	{
	//		printf("\n틀렸습니다. %d번 남았습니다.\n다시 입력하세요 :", life);
	//		scanf_s("%d", &userValue);
	//		printf("컴퓨터의 랜덤한 값 : %d\n", computerValue);
	//		printf("플레이어의 입력 값 : %d\n", userValue);
	//
	//		if (life == 1) 
	//		{
	//			printf("기회를 모두 사용했습니다. 게임에서 패배했습니다\n");
	//			break;
	//		}
	//
	//		if (computerValue > userValue)
	//		{
	//			printf("컴퓨터의 랜덤한 값 : %d가 플레이어의 입력 값 : %d보다 큽니다\n", computerValue, userValue);
	//		}
	//		else
	//		{
	//			printf("컴퓨터의 랜덤한 값 : %d가 플레이어의 입력 값 : %d보다 작습니다\n", computerValue, userValue);
	//		}
	//	}
	//	else
	//	{
	//		printf("축하합니다. 게임에서 이겼습니다.\n");
	//		break;
	//	}
	//}
	//printf("기회를 모두 사용했습니다. 게임에서 패배했습니다\n");

	 //while문을 이용한 랜덤한 숫자 맞추기 게임

	//int countNum = 5;
	//while (countNum > 1)
	//{
	//	countNum--;
	//	if (computerValue != userValue)
	//	{
	//		printf("틀렸습니다. %d번 남았습니다. 다시 입력하세요 :", countNum);
	//		scanf_s("%d", &userValue);
	//		printf("컴퓨터의 랜덤한 값 : %d\n", computerValue);
	//		printf("플레이어의 입력 값 : %d\n", userValue);
	//		
	//		if (computerValue > userValue)
	//		{
	//			printf("컴퓨터의 랜덤한 값 : %d가 플레이어의 입력 값 : %d보다 큽니다\n", computerValue, userValue);
	//		}
	//		else
	//		{
	//			printf("컴퓨터의 랜덤한 값 : %d가 플레이어의 입력 값 : %d보다 작습니다\n", computerValue, userValue);
	//		}
	//
	//	}
	//	else
	//	{
	//		printf("축하합니다. 게임에서 이겼습니다.\n");
	//		break;
	//	}
	//}
	//printf("틀렸습니다. 게임에서 패배했습니다\n");
	return 0;
}
