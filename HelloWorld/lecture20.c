/*
	작성자 : 이동윤
	작성일 : 2027-07-16
	학습 목표 : 포인터의 인자를 함수에 사용, Call by Value와 Call by Reference에 대해 이해
*/

// 배열을 매개 변수로 쓰기 위해 포인터 변수

// 배열을 선언하는 법 : int Arr[10]; 처음 선언할 때 크기까지 만들어 줘야 함.
// 값이 그 크기에 따라서 변한다.
// 시작할 때 값을 초기화해줘야 한다.
void AddArrayElement(int* arr, int len, int add)	// 배열 요소의 값을 n만큼 더하는 함수로 변경
{
	for (int i = 0; i < len; i++)
	{
		arr[i] += add;
		printf("%d ", arr[i]);
	}
}

// Call by Value vs Call by Reference
// 함수가 종료될 때 값을 반환
// return  - 그 시점에서 함수를 종료시키고 함수를 호출한 곳으로 돌아감
// return 0  - 함수를 종료하는 시점에서 0을 반환

// 반환값이 없는 경우 : void
// 반환값이 있는 경우 : 반환 하고 싶은 데이터형을 입력

void Call_by_Value(int _num)
{
	_num += 10;
}

void Call_by_Reference(int* _numPtr)
{
	*_numPtr += 10;
}

// Call_by_Value 값에 의한 호출 : 함수 호출 시 기본적으로 외부에 영향을 주지 않음
// 포인터는 역참조 연산자를 사용하여 외부 주소를 참조해서 값을 변경할 수 있다.


#include"lectures.h"

void SquareByValue_20(int num)
{
	num = num * num;
	printf("함수 안에서 실행된 값 : %d\n", num);
}

void SquareByRef_20(int* numPtr)
{
	*numPtr *= *numPtr;
}

void ChangeElement_Value(int a, int b, int c)
{
	int temp;
	temp = a;
	a = b;
	b = c;
	c = temp;
	printf("Call_by_Value 값 : %d %d %d \n", a, b, c);

}

void ChangeElement_Ref(int* a, int* b, int* c)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = *c;
	*c = temp;
	// a -> b, b -> c, c -> a 값을 변경하는 함수
}

// 전역변수 : 
// 지역변수 : { }(스택) 안에 작성되는 변수, { }이 종료될 떄 같이 소멸

int global_val_l20 = 30;	// ex) 점수, 몬스터 처지

void DoublePointerCallByRef(int** ref)
{

	*ref = &global_val_l20;
}

void DecimalToBinaray(int num)
{
	int binaray[20] = {0};		
	int pos = 0;

	while (1)
	{
		binaray[pos] = num % 2;
		num = num / 2;
		pos++;
		
		if (num == 0)
			break;
	}

	for (int i = pos - 1; i >= 0; --i)
	{
		printf("%d ", binaray[i]);
	}
}

void lectures20()
{
	int Arr[3] = {1, 2, 3};
	AddArrayElement(Arr, 3, 5);
	printf("\n");

	int num = 10;
	int* numPtr = &num;

	Call_by_Value(num);
	printf("Call_by_Value num의 값 : %d\n", num);
	Call_by_Reference(numPtr);
	printf("Call_by_Reference num의 값 : %d\n", num);

	printf("예제 1\n");
	int b = 3;
	int* bPtr = &b;
	SquareByValue_20(b);		// 값이 변경 안됨
	printf("b의 값 : %d\n", b);
	SquareByRef_20(bPtr);	// 값이 제곱이 되서 출력
	printf("b의 값 : %d\n", b);

	printf("예제 2\n");
	int t1 = 10, t2 = 20, t3 = 30;
	ChangeElement_Value(t1, t2, t3);
	ChangeElement_Ref(&t1, &t2, &t3);
	printf("%d %d %d\n", t1, t2, t3);

	printf("이중 포인터\n");		// 포인터(주소)변수 - 주소

	int p1 = 10;
	int p2 = 20;
	int* p1Ptr = &p1;
	int* p2Ptr = &p2;
	int* p3Ptr = NULL;

	// 이중 포인터 : 주소로 가리키고 있는 변수의 주소 
	p3Ptr = &global_val_l20;
	DoublePointerCallByRef(&p1Ptr);
	printf("%d\n", *p1Ptr);

	printf("예제 3\n");
	// 10진수를 2진수로 변환해서 출력하는 함수를 만들 것
	int input;
	scanf_s("%d", &input);

	DecimalToBinaray(input);

	// 11을 2진수로 만드는 법
	// 11/2 = 5 + 1
	// 5/2 =  2 + 1
	// 2/2 = 1 + 0
	// 1/2 = 0 + 1
	// 1011(2) = 1 + 2 + 0 + 8 = 11

}