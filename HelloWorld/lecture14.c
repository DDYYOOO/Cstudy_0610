/*
	작성자 : 이동윤
	작성일 : 2024-06-27
	학습 목표 : 함수
*/

// 함수를 써야하는 이유
// C언어는 절차(Procedual)지향(Orient) 프로그래밍 언어
// 절차 = 함수 <- C언어는 함수를 지향하는 언어

// 1. main 함수에서 시작되는 프로그래밍에 코드 내용이 길어질수록 코드를 파악하기 힘들고, 기능 유지 보수가 힘들어지고, 반복적인 코드가 계속 발생
// 함수를 시용해서 코드를 파악하기 쉽게 만든다.
// 유지 보수를 쉽게 만든다.
// 반복적인 코드를 줄인다.

// 함수의 선언
// 반환값이 있는지 없는지
// 매개변수가 있는지 없는지

// (반환하고 싶은 데이터 형식)(함수 이름)( ) : 함수의 선언
// {
//		함수의 본체;	
// }

// 유형1. 반환값이 있고 매개변수도 있는 함수
// 매개변수 작성법 
// 위치 : 반환값 함수이름(매개변수 작성하는 곳)
// 데이터 형식 매개변수의 이름을 작성
int AddTwoNumer(int a, int b)
{
	int result = a + b;
	// 함수의 목표를 원래 위치로 반환하는 방법으로 : return 사용
	printf("a의 값은 %d이다\n", a);
	return result;
}

// 유형 2. 반환값이 없고 매개변수도 없는 함수
void ShowResult() 
{
	printf("결과를 출력하겠습니다.\n");
	printf("게임을 종료합니다.\n");
}

// 유형 3. 반환값이 없고 매개변수가 있는 함수
void ChangeResult(int result)
{
	//printf("%d로 결과가 변경되었습니다.\n", result);
	//return;
	printf("%d로 결과가 변경되었습니다.\n", result);
}

// 유형 4. 반환값이 있고 매개변수는 없는 함수
int InputNumber()
{
	int number;
	scanf_s("%d", &number);
	return number;
}

#include"lectures.h"

void lectures14() // 함수의 선언
{
	// 함수의 호출
	// 5 + 7 결과를 a라는 정수형 변수에 넣는 코드를 작성
	//int a = 5 + 7;
	//a = AddTwoNumer(5, 7);
	//
	//ShowResult();

	// a변수를 매개변수로 ChangeResult함수로 호출
	//ChangeResult(a);
	//ChangeResult(AddTwoNumer(5, 7));
	
	//int c = InputNumber();
	//printf("%d 값이 출력되었습니다\n", c);

	// 아래의 함수를 호출
	
	int FirstNum, SecondNum;
	
	FirstNum = InputNumber();
	SecondNum = InputNumber();
	int CompareValue = Compare(AbsoluteNum(FirstNum), AbsoluteNum(SecondNum));
	printf("두 수를 절댓값으로 변환한 값 중 큰 값 : %d", CompareValue);
}

// 두 수를 비교해서 큰 값을 리턴하는 함수를 작성
// 두개의 변수를 매개변수로 받는 함수
// 이름 : Compare   정수형 데이터를 비교, 실수형도 가능
int Compare(int a, int b)
{
	
	if (a < b)
	{
		printf("%d가 %d보다 작습니다.\n", a, b);
		return b;
	}
	else
	{
		printf("%d가 %d보다 큽니다.\n", a, b);
		return a;
	}
}
// 변수 하나를 받아서 그 수를 절댓값으로 변경해주는 함수를 만들어라
// 이름 : AbsoluteNum
int AbsoluteNum(int num)
{
	if (num > 0)  // 음수
	{
		return num * (-1);
	}
	else
	{
		return num;
	}
}

// 두 수가 절댓값으로 변경한 두 수를 비교하는 함수를 만들어라
