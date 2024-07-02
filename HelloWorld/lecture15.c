/*
	작성자 : 이동윤
	작성일 : 2024-06-28
	학습 목표 : 지역 변수와 전역 변수의 이해
*/

/*
  지역 변수(Local variable) : 중괄호 내부에서 생성되는 변수 지역변수는 선언된 지역 내에서만 유효.
*/

// 변수의 존재기간 : 중괄호가 끝날 때 변수가 사라진다 지역 변수가 저장되는 공간(메모리 공간)을 스택(stack)이라고 한다.

// 변수의 접근 범위 : 범위 밖에서 선언된 변수와 범위 안에서 선언된 변수의 이름이 같을 때 어떤 변수를 사용?

// 같은 지억 내에서 같은 이름의 변수를 선언할 수 없다 컴파일러가 같은 이름의 변수에 대해서 어떤 변수를 사용해야 할지 모르기 때문.

// 범위가 다른 곳에서 같은 이름의 변수가 선언되었다면 가장 가까운 범위의 변수를 사용

/*
  전역 변수(Global variable) : 중괄호 {} 밖에 선언된 변수
*/

int count;  // 전역 변수 선언 전역 변수는 선언 시에 0으로 초기화가 됨   전역 변수는 사용을 지양
			// 유닛을 뽑을 때 마다, 인구수가 1씩 증가하는 로직에서 

int SimpleFunc()
{
	count++;
	int num = 10;
	num++;
	return num;
}

void PlusOne(int a, int b) // 호출할때 마다 count를 1씩 증가
{
	a++;
	b++;
}

#include"lectures.h"

void lectures15()
{
	static int static_num; // 스태틱 지연 변수 선언

	printf("전역변수 count 초기 값 : %d\n", count);
	count = 10;
	printf("count : %d\n", count);
	int num = 17;
	SimpleFunc();
	printf("num의 값 : %d\n", num);
	printf("count의 값 : %d\n", count);

	int count1 = 4, count2 = 6;

	PlusOne(count1, count2);
	printf("count1의 값 : %d, count2의 값 : %d\n", count1, count2);


	//static int static_num; // lectures15 함수 내에서만 스태틱 지연 변수 선언

	printf("static_num 의 값 : %d\n", static_num);
}
