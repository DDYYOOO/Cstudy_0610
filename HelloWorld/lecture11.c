/*
	작성자 : 이동윤
	작성일 : 2024-06-24
	학습 목표 : 코드의 흐름 제어를 학습한다. (조건문)
*/

/*
  Why? 코드의 흐름 제어를 왜 배울까?
  코드의 유연성을 주기 위해서
  조건문
*/

/*
  if(컴퓨터가 생서안 숫자 값과 플레이어가 입력한 숫자가 같으면)
     숫자를 맞췄다. 게임 클리어 -> 게임 종료, 다시 시작
  if(검퓨터가 생성한 숫자 값과 플레이어가 입력한 숫자가 다르면)
     숫자를 틀렸다. 다시 맞출 기회를 제공한다 -> 다시 맞출 기회를 준다
*/

/*
  의사 코드(수도 코드, 슈도 코드, pseudo code)
  코드로 바로 작성하기엔느 실력이 부족하기 때문에, 논리적인 흐름을 추론하기 어려운 코드인 경우에는 사람의 언어로 프로그래밍 언어를 작성한다. 이러한 언어를 의사 코드라고 부른다.
*/

/*
  if조건문, 사용할 수 있다.
  if(조건식)
  {
	조건식이 참일 때, 실행되는 코드를 작성;
  }
*/

/*
  주의 해야 할 점1. if 조건문과 새미클론
  if(조건식);
  {
	"코드 내용";
  }

  주의해야 할 점2. 대입 연산자, '==' 연산자의 차이를 구분할 것

  C언어는 0이외의 숫자는 if(조건식)안에서 참(true)이라고 판정한다.
  0이면 거짓(false)이라고 판정한다.
*/

/*
  () 중괄호 없는 if문
  if(조건식)
     코드 내용;
*/

/*
  if ~ else 조건과 정확히 반대로 이루어진 or 조건과 일치하지 않는 나머지
  if(조건식) 
  {
	코드 내용;
  }
  else	위의 조건식이 false일때 실행
  {
	코드 내용;
  }
*/

/*
  else if	if조건문이 false이면 else if사용할 수 있다. 
			else if뒤에 조건식이 없으면 컴파일 에러를 발생한다.
			else if는 단독으로 사용할 수 없다.
  if(방향키 왼쪽)
     왼쪽으로 움직여라
  else if(방향키 오른쪽)
     오른쪽으로 움직여라
  else if(방향키 위쪽)
	 위쪽으로 움직여라
  else if(방향키 아래쪽)
	 아래쪽으로 움직여라
  else
     방향키 이외의 키 입력 값
*/

#include"lectures.h"

void lectures11()
{
	int num1 = 5;

	if (num1 == 10) // if(조건문); 표현을 사용하면 안된다.
	{
		printf("10입니다\n");
	}

	// if(10)에 num1 코드를 작성하여 "5"입니다 출력되지 않게 작성을 해보세요.
	if (num1 == -100) // num1과 10을 비교해서 같은지 아닌지 작성하려는 목적. num1 = 10 의미는 10을 num1에 넣어라
	{
		printf("5입니다\n");
	}

	if (num1 == 7)
		printf("중괄호 없는 코드 출력\n");	// if 조건문에 실행할 코드가 한 줄이라면 중괄호를 생략할 수 있다.
	printf("중괄호 없는 코드2 출력\n");	// 중괄호를 생략하는 방식은 1줄만 가능하기 떄문에 2줄 이상 코드에서는 중괄호가 필요

	// 실수와 문자의 조건문 사용
	float f_num1 = 0.1f;

	if (f_num1 == 0.1f)
		printf("0.1입니다\n");

	if (f_num1 == 0.000005f * 2)
		printf("0.1이 출력이 될까? \n");	// 근사치를 조심해야한다. 지양 할 것.

	char c_num1 = 'A';

	if (c_num1 == 'A')
		printf("A입니다.\n");
	if(c_num1 == 65)
		printf("A입니다.\n");

	// scanf_s로 조건문 작성해보기
	// 사용자의 입력을 받아서 그 값이 같으면 참 다르면 거짓이다를 출력

	int num2;
	int targetNum = 50;

	printf("정수를 입력하세요(목표 값 : 50) : ");
	scanf_s("%d", &num2);

	if (num2 == targetNum)
		printf("참입니다\n");
	else
		printf("거짓입니다\n");

	//if (num2 != targetNum)
	//{
	//	printf("거짓입니다\n");
	//}
	
	// c_num2가 k와 일치하면 "k입니다"를 출력시키고, 일치하지 않으면 c_num2를 k값으로 변경시키는 코드를 작성
	int c_num2 = 'k'; // k는 아스키 코드로 107

	//if (c_num2 != 107)
	//{
	//	printf("k가 아닙니다");
	//	c_num2 = 'k';
	//}
	//
	//if (c_num2 == 'k')
	//{
	//	printf("k입니다\n");
	//}

	if (c_num2 == 'k')
	{
		printf("k가 아닙니다\n");
		c_num2 = 'k';
		printf("c_num2 의 값은 %c입니다\n", c_num2);
	}

	printf("if 예제 문제\n");

	int score;
	scanf_s("%d", &score);

	if (80 <= score)
		printf("A등급입니다.");
	else if (70 <= score)
		printf("B등급입니다.");
	else if (60 <= score)
		printf("C등급입니다.");
	else if (50 <= score)
		printf("D등급입니다.");
	else
		printf("F등급입니다.");

	
}