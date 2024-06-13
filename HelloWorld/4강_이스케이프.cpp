/*
*	ㅇ


*/


#include <stdio.h>

int main(void)
{
	int num = 500;

	printf("지금 보유한 금액은 : %d\n");
	printf("\a");
	printf("hello\b\bhi\n");
	printf("건강하세요\n");
	printf("지금 보유한 금액은 : %d\n");
	printf("지금 보유한 금액은 : %d\n");
	
	//변수를 이용한 데이터의 저장
	//변수를 저정하는 다양한 방법
	//(1) 변수를 선언, 선언 할당

	int num1;
	num1 = 10;
	//(2) 변수 초기화. (선언과 할당)
	int num2 = 20;
	//(3) 변수를 동시에 선언, 단 데이터 형태 같은 것만
	int num3, num4, num5;
	num3 = 10, num4 = 20, num5 = 30;
	printf("%d %d %d", num3, num4, num5);
	//(4) 변수를 동시에 선언과 함께 할당
	
	// 변수 이름 작성 시 주의 사항
	//변수의 이름에 숫자가 들어가면 안된다.
	//int 776num;
	//#, $ 특수 기호를 이름에 사용할 수 없다.
	//int #num;
	// 띄어쓰기(공백 문자)를 할 수 없다.
	//int your function;
	//키워드도 이름으로 사용할 수 있다.
	//auto, enum, break, return, void, float, short, while
	// int int34;

	//변수에 이름을 잘 지을 것을 생각 해야한다.

	//int abc = 10;
	int playerHP = 100;
	int P_HP;




	return 0;


}