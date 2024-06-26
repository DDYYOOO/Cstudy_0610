/*
	작성자 : 이동윤
	작성일 : 2024-06-26
	학습 목표 : break, continue
*/

/*
  for반복문, while반복문
  반복적인 내용을 간결하게 표현
  break, continue  (반복문, 조건문 - 제어문) 제어해주는 방법
  for, while, do ~ while, switch 사용
*/

/*
  break : 제어흐름에서 벗어나기 위해 사용. break 선언되면 해당 제어문에서 빠져 나옴
  continue : 제어흐름을 유지한 상태로 해당 코드의 실행만 건너 뛰는 기능을 함
*/


#include"lectures.h"

void lectures13()
{
	// printf 10번 반복하는 for반복문
	// 0 ~ 특정 숫자까지 반복해서 아래의 코드를 실행하는데, 내가 원하는 목포값에 도달하면 
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("Hi%d\n", i);
	//
	//	if (i == 7)
	//	{
	//		printf("i가 7일때 출력됨\n");
	//		break;
	//	}
	//}
	//
	//int index = 0;
	//for (; ;)
	//{
	//	index++;
	//	printf("hi\n");
	//	if (index == 7)
	//	{
	//		printf("7이 출력되었습니다\n");
	//		break;
	//	}
	//}

	// for반복문
	//int targetNumber; // 출력하고자 하는 목표 숫자
	//scanf_s("%d", &targetNumber);

	//int counter = 0;  // 반복문에서 targetNumber를 찾기 위한 변수
	//for (; ;)
	//{
	//	counter++;
	//	printf("idid\n");
	//	if (targetNumber == counter)
	//	{
	//		printf("원하는 결과값이 출력되었습니다. %d\n ", targetNumber);
	//		break;
	//	}
	//}

	// while반복문
	//int w_counter = 0;
	//while (1)
	//{
	//	w_counter++;
	//	printf("IDID %d\n", w_counter);
	//	if (targetNumber == w_counter)
	//	{
	//		printf("원하는 결과값이 출력되었습니다 %d\n", targetNumber);
	//		break;
	//	}
	//}

	// continue 사용 예제
	//int w_num = 0;
	//while (w_num < 10)
	//{
	//	w_num++;
	//	if (w_num % 2 == 0) // 2로 나눴을때 나머지가 0 (짝수), 아닌 숫자들은 홀수
	//	{
	//		printf("건너 뛴 w_num의 값 : %d\n", w_num);
	//		continue;
	//	}
	//	printf("w_num의 값 : %d\n", w_num);
	//}

	// 주사위에는 12개 면이 있다 scanf함수로 주사위의 눈을 조작
	// 만약 주사위가 짝수가 나온다면 현재 갖고 있는 돈의 소지금이 2배, 홀수면 갖고 있는 돈의 소지금이 0원이 되는 코드 작성
	// 만약 소지금이 0이면 프로그램이 종료
	printf("주사위 예제 시작\n");

	// 0 ~ 12 숫자를 scanf_s출력
	printf("여러분이 지금 타짜여서 주사위의 숫자를 골라주세요(0 ~ 12) :");
	int diceNum, gameMoney;
	// 지금 코드의 문제점 12보다 큰 숫자, 0보다 작은 숫자를 입력하면 그 숫자가 diceNum에 출력 <- 이것을 수정하는 코드
	scanf_s("%d\n", &diceNum);
	gameMoney = 1000;  // 기본 소지금

	while (1)
	{
		if (diceNum < 1 || diceNum > 12) // 
		{
			printf("현재 잘못된 주사위 크기를 입력했습니다. \n 주사위를 다시 입력해주세요 : \n");
			scanf_s("%d\n", &diceNum);
		}
		else // 실제 게임 작동 로직
		{
			// 짝수인지 홀수인지 판별하는 코드 작성
			if (diceNum % 2 == 0)  // 짝수
			{
				gameMoney = gameMoney * 2;

				if (gameMoney > 5000)
				{
					printf("게임에서 승리했습니다. 보유 금액 : %d", gameMoney);
					scanf_s("%d\n", &diceNum);
				}
				else
				{
					printf("현재 보유중인 금액 : %d\n", gameMoney);
				}
			}
			else // 홀수
			{
				gameMoney = 0;
				printf("게임에서 졌습니다 보유 금액은 : %d", gameMoney);
				break;
			}

		}

	}


}