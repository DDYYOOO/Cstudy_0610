/*
	작성자 : 이동윤
	작성일 : 2024-07-17
	학습 목표 : 메모리 공간에 대한 이해, 동적 메모리 할당, 포인터 사용
*/

/*
  코드 영역     : CPU가 읽어 들인 파일을 실행 시킨다. 명령어로 실행 
  데이터 영역   : 전역 변수, static 으로 선언한 변수가 저장
  힙 영역       : 메모리를 수동으로 해제해야 하는 저장 공간
  스택 영역     : 메모리가 자동으로 해제되는 저장 공간
*/

// 1. 스택 영역 : 함수 호출 call by value 정보를 표현할 때, 기존 값은 유지한채로 다른 결과를 표시하고 싶을 때 사용
// 2. 힙   영역 : 필요한 데이터 공간 만큼 적재적소로 넣으면 좋음

// 스택, 힙 영역을 나누는 이유
// 메모리 공간이 한정적

// 오버 플로우
// 힙 오버 플로우 : 힙이 스택 공간을 침법
// 스택 오버 플로우 : 스택이 힙 공간을 침범

// 재귀 함수 : 함수가 자기자신을 호출하도록 한 후, 무한 반복
// 힙 오버 플로우 예시 : malloc, free함수로 직접 메모리 할당 및 해제, 

#include"lectures.h"

void AllocateArrary(int count)
{
	int* newPtr = malloc(sizeof(int) * count);

	for (int i = 0; i < count; i++)
	{
		*(newPtr + i) = i + 1;
		printf("%d ", *(newPtr + i));
	}
	free(newPtr);
}


void lectures21()
{
	// 동적 메모리 할당 함수 : malloc
	// memory + allocation : 메모리 할당 함수 
	// 포인터 변수  = malloc(크기);  메모리 공간의 크기

	int num1 = 20;
	int* num1Ptr = &num1;
	int* const numPtr2 = malloc(4);
	*numPtr2 = num1;
	
	printf("%d\n", *numPtr2);

	// 동적 할당한 메모리는 반드시 해제해야 함
	// free
	free(numPtr2);
	printf("%d\n", numPtr2);

	int Arr[4] = {1, 2, 3, 4};
	int* numPtr3 = malloc(sizeof(int) * 4);  //  4 * 4 = 16
	numPtr3 = Arr;

	for (int i = 0; i < 4; i++)
	{
		printf("%d ", *(numPtr3 + i));
	}
	//free(numPtr3);
	printf("\n");

	// 동적으로 정수형 포인터 크기를 생성하는 함수를 작성
	printf("예제 문제\n");

	int count;
	scanf_s("%d", &count);
	AllocateArrary(count);
	
	printf("\n");
	// 

	char c = 69;	// 69에 대응되는 ASII 문자 하나가 출력
	char c2 = 'a';
	printf("%d\n", c);
	printf("%c\n", c);

	//printf("Hello"); // H, e, l, l, o
	// 문자열(string)
	char* s = "Hello";
	printf("%s\n", s);

	// 리터럴 문자열 : "ㅁㄴㅇㅁㅇㄴ"
	// 컴파일 시에 주소를 반환(데이터 영역 저장)

	char sArr[5] = { 'H', 'e', 'l', 'l', 'o'};
	
	for (int i = 0; i < 5; i++)
	{
		printf("%c", sArr[i]);
	}
	printf("\n");

	char* s2 = "Hello World";
	printf("%s\n", s2);

	printf("문자 : %c 아스키코드 : %d\n", *(s2 + 1), *(s2 + 1));	// e
	printf("문자 : %c 아스키코드 : %d\n", *(s2 + 6), *(s2 + 6));	// W
	printf("문자 : %c 아스키코드 : %d\n", *(s2 + 10), *(s2 + 10));  // d
	printf("문자 : %c 아스키코드 : %d\n", *(s2 + 5), *(s2 + 5));    // 띄어쓰기 공백 문자
	printf("문자 : %c 아스키코드 : %d\n", *(s2 + 11), *(s2 + 11));  // 문자열의 마지막에는 \'0' = NULL문자.

	// NULL문자 : 문자열의 마지막을 알려주기 위한 문자
	
	printf("NULL문자를 이용한 문자열 출력\n");

	int index = 0;
	
	while (*(s2 + index) != 0)  // 조건문 종료
	{
		printf("%c", *(s2 + index));
		index++;
	}


}