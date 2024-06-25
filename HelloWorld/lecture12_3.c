/*
	학습목표 : while 반복문
	while 반복문으로도 반복을 표현할 수 있다
*/

/*
  while(조건식)  // 조건식이 True면 루프 본체를 실행하고, 조건식이 False면 다음 코드를 실행
  {
	코드내용 ;  // 루프 본체
	변화식;
  }

  do ~ while

  do
  {
	반복시킬 코드;
  }while(조건식);
*/
#include"lectures.h"

void lectures12_3()
{
	int i = 0;

	while (i < 10)  // 1이 10보다 작으면 계속 반복
	{
		i = i + 2;  // 변화식
		printf("Hello World\n");
	}

	//while (100)    // 무한 루프
	//{
	//	printf("Hello World\n");
	//}

	int index;
	scanf_s("%d", &index);

	while (index != 3)  // while 조건식에 조건으로 대입 연산자를 사용하면 무한 루프에 빠질수 있으므로 유의해야 함
	{
		printf("Hello World\n");
		scanf_s("%d", &index);
	}

	// while반복문의 장점 - 몇 번 반복될지 모르는 코드에서 사용하기 용이

	// do ~ while
	// 한 번은 반드시 출력하도록 구현이 되어 있는 코드
	int i_doNum = 1;
	do
	{
		printf("한번은 반드시 출력하는 do ~ while문.\n");
		i_doNum = i_doNum * 3;
	} while (i_doNum < 10);



}