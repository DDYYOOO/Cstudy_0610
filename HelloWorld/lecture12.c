/*
  작성자 : 이동윤
  작성일 : 2024-06-25
  학습 목표 : 반복문의 이해와 실습
*/

/*
  반복문을 써야 하는 이유
  불필요한 반복적인 코드를 간결하게 표현할 수 있다.
*/

// 종류 : for반복문, while반복문

/*
  for(초기식; 조건식; 변화식) // loop statement(루프 선언문)
  {
	코드 내용;				// loop body(루프 몸통)
  }

  초기식 : int i = 0; 반복문이 시작할 때 필요한 변수의 선언 및 할당이 이루어지는 공간 ';'
  조건식 : i < 10	 조건식이 참이면 루프 본체의 코드를 실행한 후 변화식을 실행한다     
  변화식 : i++		 초기식의 변수값을 변화시켜서 조건을 탈출할 수 있도록 하는 식

*/


#include"lectures.h"

void lectures12()
{
	// 1. for 반복문
	// for 반복문 예제

	// i++ = i + 1; (대입 연산자 보다 늦게 처리)
	// ++i = i + 1; (대입 연산자 보다 먼저 처리)

	// c = a + b++; -> c의 값이 1만 더해진 값
	// c = a + ++b; -> c의 값이 1이 더해진 값

	// Hello World 10번 출력
	for (int i = 0; i < 10; i++)
	{
		printf("Hello World\n");
	}

	// 초기식, 변화식의 변화를 준다
	int index;

	for (index = 10; index > 0; index--)
	{
		printf("Index print! %d\n", index);
	}

	for (int i_num = 0; i_num < 10; i_num += 2)
	{
		printf("i_num Printf! %d\n", i_num);
	}

	// for(~; ~; ~); // 선언문 뒤에 ; 붙이면 아래의 루프 바디와 별개로 작동
	
	for (; ;)  // 해당 반복문을 표현한 코드 무한 반복문에 빠지면 콘솔창에서 Ctrl + c를 누르면 된다
	{
		printf("Hi\n");
	}
}

void lectures12_2()
{
	// scanf 몇번 반복할지 정해주기
	int i_scanfNum;
	printf("몇번 반복문을 실행 할 건지 숫자를 입력 하세요 :");
	scanf_s("%d", &i_scanfNum);
	// for문과 printf사용해서 i_scanfNum의 현재 값과 "반복문 실습", i_scanfNum의 값은 : \n

	// i_scanfNum의 현재 값과 "반복문 실습", i_scanfNum의 값은 : \n
	// 정수형 변수를 출력. printf함수를 사용해서, 앞에 "반복문 실습 i_scanfNum의 값은 :"

	for (int i = 0; i < i_scanfNum; i++)
	{
		printf("반복문 실습 i_scanfNum의 값은 : %d\n", i_scanfNum);
	}

	// for 반복문은 반복 횟수가 정해져있는 코드를 작성할 때 유용

	// for 예제 2
	printf("반복문 예제 문제2\n");

	// 1이상 100미만의 정수들 중에서 7의 배수와 9의 배수를 출력하는 프로그램을 작성
	// 공통된 숫자가 한 번만 출력되도록 코드를 작성

	for (int i = 1; i < 100; i++)
	{
		// 7의 배수와 9의 배수 일때만 출력
		if(i % 7 == 0 || i % 9 == 0) // 7의 배수와 9의 배수는 7과 9로 나눈 나머지 값을 표현
			printf("%d\n", i);
	}
 
	// for 예제 1번 문제를 while문으로 바꾸어서 구현
	// 변수를 새로 선언 or 다른 변수 선언 OK
	printf("반복문 예제 문제3\n");

	int w_num;
	scanf_s("%d", &w_num);
	while (w_num > 0)
	{
		printf("%d\n", w_num);
		w_num--;
	}
}