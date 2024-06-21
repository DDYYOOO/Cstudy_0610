#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	// printf함수와 scanf함수를 시용해서 게임의 느낌을 만듦
	// 플레이어를 환영하는 텍스트를 출력 ☆★
	// printf(숫자를 입력하면 게임이 시작합니다)
	// scanf -> 입력을 받는다  커서가 멈춘상태로 대기하고 있다

	//정수 또는 실수 데이터를 만들어서 컴퓨터가 생각하는 결과를 출력하고, 내가 생각하는 결과를 같이 출력하는 프로그램을 만들어 보세요

	printf("☆★게임 시작★☆\n");

	srand(time(NULL));
	int computerValue = rand() % 100 + 1; // 1 ~ 100의 랜덤한 숫자가 computerValue에 입력이 된다.
	int userValue;
	int startValue;
	printf("어서오세요. 숫자를 입력하면 게임이 시작됩니다 : ");
	scanf_s("%d", &startValue);
	
	printf("플레이어의 값을 입력하세요 : ");
	scanf_s("%d", &userValue);
	printf("컴퓨터의 랜덤한 값 : %d\n", computerValue);
	printf("플레이어의 입력 값 : %d\n", userValue);

	if (computerValue == userValue)
		printf("축하합니다.\n");
	else
		printf("틀렸습니다.\n");

	return 0;
}