/*
	작성자 : 이동윤
	작성일 : 2024-07-15
	학습 목표 :  배열과 포인터의 차이 => "상수"포인터 
*/

// 1. 배열과 포인터의 차이
// sizeof(배열), sizeof(포인터 변수) 각각의 값이 다르게 나옴
// 배열은 상수 포인터이다.

// 2. 포인터와 상수
// 상수를 가르키는 포인터 pointer to constant
// 포인터 그 자체가 상수 constant pointer
// 상수를 가르키는 그 자체가 상수인 포인터 constantpointer to constant



#include"lectures.h"

void ShowData(const int* Ptr)
{
	const int* rPtr = Ptr;
	printf("%d\n", *rPtr);
	//*rPtr = 20;
}

voidShowAllData(int* const Arr, int len)
{
	//int* const tempArrPtr = Arr;
	for (int i = 0; i < len; i++)
	{
		printf("%d ", Arr[i]);
	}
	// for 반복문으로 arr의 길이 만큼 배열요소를 printf함수로 만듬
}

void lectures19()
{
	const int s_num = 10;
	int* s_numPtr = &s_num;
	ShowData(s_numPtr);

	int s_Arr[4] = {1, 2, 3, 4};
	int* s_ArrPtr = s_Arr;
	voidShowAllData(s_ArrPtr, sizeof(s_Arr) / sizeof(int));  // sizeof(Arr) -> 4 * sizeof(int) / sizeof(int)

	printf("\n");

	// (1) sizeof 연산자
	int Arr[3] = {1, 2, 3};
	int* ArrPtr = Arr;   // int* ArrPtr = &Arr[0];

	printf("배열의 크기 : %d\n", sizeof(Arr));		// sizeof(int) * 3 = 12
	printf("포인터의 크기 : %d\n", sizeof(ArrPtr));  // 64비트             8

	// 포인터로 코드를 작성하면 실수할 가능성이 높아지고 이해하기도 난해
	// 메모리르 훨씬 효율적으로 사용할 수 있다

	// 상수를 가르키는 포인터 pointer to constant
	// num의 값을 변경하지 못하게 막아줌
	// const int* 포인터 변수도 그 값을 변경하지 못한다. 역참조 연산자 값을 못바꾼다.
	const int num = 10;
	//num = 15;  // 에러
	const int* numPtr = &num;  // in const* numPtr = &num;
	//*numPtr = 15; // 에러

	// 포인터 그 자체가 상수 constant pointer
	int num1 = 20;
	int num2 = 30;
	int* const numCPtr = &num1;  // 상수 포인터의 선언. 배열이 상수 포인터.
	*numCPtr = 40;
	// numCPtr = &num2;          // 상수 포인터 . 주소를 변경하지 못한다. 
								 // 배열은 상수 포인터. 배열의 선언 이 후 배열의 주소를 변경할 수 없다.
		
	// 상수를 가르키는 그 자체가 상수인 포인터 constantpointer to constant
	const int num3 = 40;
	const int num4 = 50;
	const int* const numCPtr2 = &num3;
	//*numCPtr2 = 50;          에러
	//numCPtr2 = &num4;        에러

	// 정리
	// 포인터. 변수
	// 변수 - 값, 주소(&)
	// 포인터 - 주소, 값(*)

	// 포인터 선언
	// + const
	// 값 const, 주소 const
	// 값 const - 상수 포인터(const pointer)
	// 주소 const - 상수를 가리키는 포인터(pointer to constant)
	// const 포인터에 사용하지 않는 이유
	// 포인터 변수가 절대로 병경되지 않기를 컴파일러 단계에서 보장하기 위해서 (안정성 보장)


}