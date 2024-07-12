/*
	작성자 : 이동윤
	작성일 : 2024-07-11
	학습목표 : 포인터에 대한 이해 
*/

// 포인터의 선언
// (데이터 타입) * 이름; 

// 포인터란
// 포인터변수, 변하는 값(주소)를 저장

// 메모리를 구하는 연산자 : 주소 연산자 &
// & 사용법 : 변수를 먼저 선언하고 변수 앞에 사용. (&변수 : 변수가 가지고 있는 주소를 반환)

// 주소를 16진수 8개 or 16개 비트 공간을 사용해서 메모리 주소 표현
// 주소를 표현할 때 [16진수 4비트]
// 0xABCE0202 <- 주소(32비트)
// 0x00000000 ABCE020 <- 주소(64비트)

// 메모리 주소 저장
// int* numPointer;(줄인 말 numPtr) 
// 포인터 변수를 선언

// 



#include"lectures.h"

void lectures17()
{
	int num;
	scanf_s("%d", &num);
	printf("num의 값 출력 : %d\n", num);

	// 포인터의 익숙
	// 포인터 * 위치는 상관없다
	int* numPtr = &num;  // int* numPtr(포인터 변수의 선언과 초기화) 
	int * numPtr2 = &num;
	int *numPtr3 = &num;
	// 포인터를 출력하면 16진수 주소가 출력됨
	printf("%p\n",numPtr);
	printf("%p\n", numPtr2);
	printf("%p\n", numPtr3);
	
	// 주소에 저장된 값을 출력하는 방법
	// 역참조 연산자 
	// '*' 이항 연산자 : 곱하기
	// 단항 연산자 : 이미 선언된 포인터변수 앞에 *numPtr
	// numPtr 가리키고 있는 값을 참조

	printf("%d\n", *numPtr);
	printf("%d\n", *numPtr2);
	printf("%d\n", *numPtr3);



	// 실습 정수 int number 20을 할당 정수형 포인터 변수 numberPtr 선언 후 number에 있는 주소를 할당
	// printf를 사용해서 numberPtr에 있는 값을 출력( *연산자 사용)
	// 변수 -> 값 + 주소
	int number = 20;	// 변수 number 안에는 20의 값과 주소값이 같이 있다 

	// 1. 포인터 변수를 선언하는 방법 : int*
	int* numberPtr;

	// 2. 변수의 주소를 반환하는 연산자 (주소 연산자 &)
	numberPtr = &number;
	printf("numberPtr 안에 있는 주소값 : %p\n", numberPtr); // numberPtr의 주소 값

	// 3. 포인터 변수가 가리키고 있는 참조(데이터)를 반환하는 연산자 '*'
	printf("numberPtr 안에 있는 값 : %d\n", *numberPtr); // numberPtr의 참조(데이터) 값

	// 포인터 주소가 참조한 값
	// 주소를 이용해서 값을 변경하는 작업 (익숙해야 함)
	printf("기존 number의 값 : %d\n", number);
	*numberPtr = 30;
	printf("number의 값 : %d\n", number);


	// 정리
	// 1. 변수 num1 = 10;			변수의 특징 : 메모리 주소를 몰라도 값을 가져오거난 저장할 수 있다.
	// 2. 주소 연산자 : 변수의 메모리 주소를 구하는 연산자 (&num1 : 변수로부터 주소를 구할 수 있음)
	// 3. 역참조 연산자 : '*' 포인터 변수가 참조하고 있는 (메모리 상에 가리키고있는) 값에 접근 할 수 있다.
	
	// int* numPtr << 포인터 변수 선언
	// *numPtr << 포인터 변수 참조 값을 호출(역참조), numPtr이 포인터 변수이다.
	// *numPtr = 30;  << 포인터가 가리키고 있는 참조 값을 변경. 

	int a_num = 10;
	int* a_numPtr = &a_num;
	int* b_numPtr = a_numPtr;

	(*a_numPtr)++;
	(*b_numPtr)++;
	printf("%d\n", a_num);

	// 예제
	// 변수 이름 e_num1, e_num2 선언 후 각각 10, 20 할당
	//  e_num1, e_num2를 가리키는 포인터e_num1Ptr, e_num2Ptr를 선언 후 대입
	// int* temp포인터를 하나 선언
	// temp에 e_num1Ptr대입, e_num2 -> e_num1, e_num2 temp값 받아오기
	int e_num1 = 10, e_num2 = 20;
	int* e_num1Ptr = &e_num1;
	int* e_num2Ptr = &e_num2;
	printf("%d %d\n", *e_num1Ptr, *e_num2Ptr); // 본래의 값 출력

	// swap 구현
	int* temp;
	temp = e_num1Ptr;
	e_num1Ptr = e_num2Ptr;
	e_num2Ptr = temp;
	printf("%d %d\n", *e_num1Ptr, *e_num2Ptr); // 변경한 값 출력

	// 복습
	int exam_num1 = 50, exam_num2 = 30;
	int* temp_num = NULL;
	int* exam_num1Ptr = &exam_num1;
	int* exam_num2Ptr = &exam_num2;
	printf("%d %d\n", *exam_num1Ptr, *exam_num2Ptr);

	temp_num = exam_num1Ptr;
	exam_num1Ptr = exam_num2Ptr;
	exam_num2Ptr = temp_num;
	printf("%d %d\n", *exam_num1Ptr, *exam_num2Ptr);

}
