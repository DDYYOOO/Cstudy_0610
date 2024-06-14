#include"lectures.h"

//int   : 무엇을(정수), 
//float : 무엇을(실수),

//선언방법
//데이터 형태 작성(int, float) 변수 이름(a)
//예시 : int a;

//할당(assignMent)
//선언한 변수에 데이터를 넣는 것
//a이름의 변수에 정수 형태의 데이터를 넣을 수 있게 된다.
//int a = 10;

//초기화(Initialize)
//변수에 처음으로 데이터를 할당하는 것


void lectures3()
{
	printf("Hello World! 이것은3강의 내용입니다.\n");
	int a = 5 + 3; //int a 함수 값 8

	a = 4 + 7; // int a 함수값이 원래8이지만 4+7로 인해 11로 변경
	printf("%d \n", a);

	float b = 3.2f + 4.7f;
	printf("%f\n", b);

	//문제 1
	//변수의 이름 width, height, length 정수를 담을 수 있는 변수 선언

	int width = 12;
	int height = 10;
	int length = 8;

	//문제 2
	//세 변을 곱한 값(부피) Volume 변수에 저장하세요

	int Volume = width * height * length;

	//문제 3
	// volume / 165로 나누어 원하는 계산 값을 구한 뒤 printf함수로 출력하세요.

	//Volume = Volume / 165;
	Volume = (Volume + 164) / 165; //반올림
	printf("문제 3의 정수형 답은 %d\n", Volume);

	//int Volume2 = Volume / 165;
	//printf("문제 3의 정수형 답은 %d\n", Volume2);

	float Volume_f = width * height * length;
	Volume_f = Volume_f / 165.0f;
	printf("문제 3의 실수형 답은 %f\n", Volume_f);

	//float Volume3 = Volume / 165.0f;
	//printf("문제 3의 실수형 답은 %f", Volume3);

	//문제 2-1 섭씨, 화씨
	//화씨 = 9/5 * 섭씨 + 32
	//화씨가 실수로 표현될 수 있도록 변수를 선언해주세요.
	//9/5의 값이 1이 아닌 1.8이 나와야 합니다.
	//섭씨 1, 화씨 33.8

	float Celsius = 1.5f;    //섭씨
	float Fahrenheit = 9.0f / 5.0f * Celsius + 32;  //화씨

	printf("섭씨 to 화씨 : %.2f\n", Fahrenheit); //%.2f : 소수점 2자리까지 출력
}

