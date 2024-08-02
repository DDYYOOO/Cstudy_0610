/*
	작성자 : 이동윤
	작성일 : 2024-08-02
	학습 목표 : 
*/

// void에 대한 설명 - (1)함수의 반환점, (2)void Pointer
// Enum에 대한 설명 - (1)Enum이 왜 필요한지

// 함수에서 반환형이 어떤 것?
// void : 공허하다, 비어있다 (함수의 반환형에 사용되면 반환형(Return Type)이 없다)

// Swap(int* a, int* b)(int temp; temp, *a, *b) : 두 변수의 다른 변수에 넣어서 데이터를 교환한다
// void Swap : 인자로 넘겨주는 a와b의 값만 변경해주고 종료
// int Compare() : 같으면 0 틀리면 1을 반환하도록 하며, if문이랑 같이 사용 

#include"lectures.h"

void Add_one(int* a)
{
	*a = *a + 1;
}

// 반환형이 존재하는 이유 : 컴파일러가 이 코드를 보고나서 크기를 미리 결정해주는 기능

// void는 메모리 공간에 얼마나 저장되는지 알 수 없어서 void형 변수는 선언 할 수 없다
// void* 변수는 메모리 공간에 얼마나 저장되어있는지 알 수 있을까?
// void* 불완전한 형식이다
// 메모리 공간에 얼마나 차지하는지 크기를 알려준다.  정수, 실수, 구조체

// 정리
// int* : 메모리 공간에 4byte를 확보하고, 그 공간에 int 형식으로 데이터를 읽음
// void* : 메모리 공간에 8byte를 확보했지만 어떤 형식인지 모름 
// void*쓰는 이유
// IntSwap, DoubleSwap등 데이터 타입만 다른 버젼의 함수들이 쓰이고 있다
// 이 함수들을 타입을 지정해서 정해주는 함수로 만들면 하나로 표현 할 수 있다?
// 타입을 저장해주는 방법 -> void Pointer

#define TYPEOFINT 1
#define TYPEOFDOUBLE 2
#define TYPEOFFLOAT 3

// define INT DOUBLE FLOAT
// 상수를 한번에 표현하는 방식 : enum키워드 제공

// 열거형 ENUM 사용하는 이유
// 1. 코드 가독성 증가 : 상수로 표현하는 변수의 이름이 정확히 어떤 내용인지 불완전, enum 상수의 이름들을 정의하는 공간을 만듦 TYPE -> 상수3개(float, int, double)
// 2. 네임스페이스 공간 제공 : 험수의 인자로 enum type을 사용할 수 있다
// 유지보수가 쉬워짐 : 네임스페이스 공간이 따로 지정이 되어있으므로 버그를 찾기 수월
// 타입 안정성이 생김 : 상수의 데이터를 따로 저장할 필요 없이 enum type을 선언하면 됨

typedef enum TYPE { TYPE_char, TYPE_int, TYPE_double, TYPE_long_int }TYPE;		// TYPE_char : 0, TYPE_int : 1, TYPE_double : 2

void SwapValue(void* ptr1, void* ptr2, TYPE type)
{
	switch(type)
	{
		case TYPE_char:
		{
			char temp;
			temp = (*(char*)ptr1);
			(*(char*)ptr1) = (*(char*)ptr2);
			(*(char*)ptr2) = temp;
			break;
		}
		case TYPE_int:
		{
			int temp;
			temp = (*(int*)ptr1);
			(*(int*)ptr1) = (*(int*)ptr2);
			(*(int*)ptr2) = temp;
			break;
		}
		case TYPE_double:
		{
			double temp;
			temp = (*(double*)ptr1);
			(*(double*)ptr1) = (*(double*)ptr2);
			(*(double*)ptr2) = temp;
			break;
		}
		default:
			printf("해당하는 타입이 없습니다\n");
	}
}


void lectures27()
{
	int num = 1;	// 컴파일러가 미리 메모리 공간에 4byte를 확보하고 2진수로 작성된 0101데이터로부터 정보를 전달
	// void some;   // 컴파일러가 메모리 공간에 얼마나 저장해야하는지 알 수 없다
	Add_one(&num);
	printf("%d\n", num);

	void* voidPtr;	// 포인터 변수는 64비트 시스템일 때, 8바이트 크기를 확보
	printf("voidPtr의 크기 : %d\n", sizeof(voidPtr));

	double a = 1.1;
	voidPtr = &a;

	// voidPtr를 double* 형식으로 type변환
	printf("voidPtr가 가리키는 값 : %lf\n", (*(double*)voidPtr));

	char c1 = 'a';
	char c2 = 'b';
	SwapValue(&c1, &c2, TYPE_char);
	printf("c1 : %c, c2 : %c\n", c1, c2);

	int a1 = 1;
	int a2 = 2;
	SwapValue(&a1, &a2, TYPE_int);
	printf("a1 : %d, a2 : %d\n", a1, a2);

	double d1 = 1.1;
	double d2 = 2.2;
	SwapValue(&d1, &d2, TYPE_double);
	printf("d1 : %lf, d2 : %lf\n", d1, d2);

}