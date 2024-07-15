/*
	작성자 : 이동윤
	작성일 : 2024-07-12
	학습목표: 포인터의 연산
*/

// 1. 포인터

#include"lectures.h"

void lectures18()
{
	int num = 10;			// 변수 선언
	int* numPtr = &num;		// 포인터 변수 선언 및 주소 초기화
	(*numPtr)++;			// 역참조 연산자 : 주소가 가리키는 값을 반환
	printf("num의 값 : %d\n", *numPtr);	// num : 11

	// 16진수로 포인터변수에 값을 넣어서 주소의 값을 지정
	int* numPtrA = 0x10000;
	int* numPtrB = 0x10000;
	numPtrA = numPtrA + 1; // numPtrA + 1;
	numPtrB = numPtrB + 2;
	printf("PtrA의 값 : %p\n", numPtrA);
	printf("PtrB의 값 : %p\n", numPtrB);

	// 주소의 크기를 구하는 방식
	printf("포인터 변수의 크기 : %d\n", sizeof(numPtrA)); // 86 : 4
	printf("포인터 변수의 크기 : %d\n", sizeof(numPtrA)); // 64 : 8

	// 포인터 변수의 크기가 다른 이유
	// 주소를 저장하는 변수. 크기를 가짐
	// 16진수 1개의 바이트 공간. 8개(4비트 * 8 = 32비트)
	// x86 : 왜 32비트? - Intel사 8086개인컴퓨터에서 32비트 아키텍쳐 최초 제공 -> 86을 따와서 x86 = 32비트 공식이 생김

	// int* -> 4바이트 정수 주소는 공간의 첫번째 바이트에 저장, 시작부터 크기까지 공간을 확보해서 저장

	// 포인터와 배열
	int numArr[5] = { 11, 22, 33, 44, 55 };
	//  0   1   2   3   4
	int index = 2;

	printf("numArr[5]의 3번째 값 : %d\n", numArr[index]);

	// index의 값에 더하기 또는 빼기 연산자를 사용해서 numArr을 반복문으로 출력

	// 정방향 출력
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", numArr[i]);
	}
	printf("\n");
	// 역방향 출력
	for (int i = 4; i >= 0; i--)
	{
		printf("%d ", numArr[i]);
	}
	printf("\n");
	// 배열읠 포인터로 바꾸는 방법
	int arr1[3] = { 0, 1, 2 };
	printf("배열의 이름 : %p\n", arr1);

	for (int i = 0; i < 3; i++)
	{
		printf("배열의 요소 %d 요소 : %p\n", i, &arr1[i]);
	}

	// 배열의 첫번쨰 요소의 값의 주소를 반환을 했더니 그 결과값이 배열의 이름의 주소와 같다.

	// int 포인터 변수 + 1 : 주소의 값이 4만큼 크기가 커짐

	char* charPtr = 0x1000000;
	charPtr++;
	printf("%p\n", charPtr); // char 1바이트
	short* shortPtr = 0x1000000;
	shortPtr++;
	printf("%p\n", shortPtr); // short 2바이트

	// 포인터 연산의 공식
	// sizeof(char)* : 데이터의 크기
	charPtr += 10;		// 0x1000000 + 10(1x10)
	shortPtr += 10;		// 0x1000000 + 20(2x10)

	// int포인터 10만큼 증가 4x10
	// 포인터 연산은 sizeof(데이터형) x n(더해준 수)크기가 증가

	// 배열에서 포인터 연산자. &, *
	int arr2[3] = { 0, 1, 2 };
	// 배열을 포인터변수로 선언 
	int* s_Ptr = arr2;
	int* s_Ptr2 = &arr2[0];

	&arr2[0]; // 주소 arr2 배열 1번째 주소
	&arr2[1]; // 주소 arr2 배열 2번째 주소
	&arr2[2]; // 주소 arr2 배열 3번째 주소

	printf("주소의 연산 후 역참조 값 : %d\n", *(s_Ptr + 1)); // s_Ptr 포인터변수 s_Ptr가리키고있는 주소를 4 증가
	printf("역참조 후 값 : %d\n", (*s_Ptr2)++);
	printf("\n");

	//printf("주소의 연산 후 역참조 값 : %d\n", *(s_Ptr++));

	// 예제
	// 길이가 5인 배열 선언 firstArr[5]
	// firstArr이름을 firstArrPtr 포인터 변수에 넣어라
	// firstArrPtr 연산을 이용해서 해당 주소의 값을 3을 증가
	// 반복문을 사용
	printf("예제1\n");
	int firstArr[5] = { 1, 2, 3, 4, 5 };
	int* firstArrPtr = firstArr; // 배열 첫번째는 주소 연산자 없음에도 주소다
	// 포인터 변수. 주소의 변수. 주소
	for (int i = 0; i < 5; i++)
	{
		*firstArrPtr += 3; // firstArr[i] += 3;
		firstArrPtr++;	   // i++; 
	}

	for (int i = 0; i < 5; i++)
	{
		printf("firstArr배열요소에 3을 증가 시킨 값 : %d\n", firstArr[i]);
	}
	printf("\n");

	// 예제2 포인터 연산의 뺄셈을 사용해서 배열의 큰 수 부터 작은 수 출력
	printf("예제2\n");
	int secondArr[5] = { 1, 2, 3, 4, 5 };	// 정수형 배열 5개 선언 및 초기화
	int* secondArrPtr = secondArr;			// 포인터(주소를 저장하는 변수) 배열의 이름 자체가 포인터. &secondArr : 주소의 주소
	secondArrPtr += 4;                      // 포인터 변수 +4 : sizeof(int)* n

	for (int i = 0; i < 5; i++)
	{
		printf("secondArr배열의 값 : %d\n", *secondArrPtr);  // 값을 변경해서 저장
		secondArrPtr--;	   // i--; 
	}
	printf("\n");
	// *(Ptr)++;  <- 포인터가 가리키고 있는 참조값 반환 그 값에 1을 더함  num = 10; 1을 더해서 11이 반환 
	// *(Ptr + 1); <- 포인터가 가리키고 있는 주소 type크기를 더해서 현재 가리키고 있는 주소를 변경

	int exArr[5] = { 0 };
	int* exArrPtr2 = exArr;
	printf("배열의 크기 : %d\n", sizeof(exArr));
	printf("포인터의 크기 : %d\n", sizeof(exArrPtr2));

	// 최대한 메모리를 아껴쓰자
	// arr[1000] -> 4 x 1000; 8비트
	printf("\n");

	// 정리2
	int o_Arr[3] = { 1, 2, 3 };
	int* o_ArrPtr = o_Arr;

	for (int i = 0; i < 3; i++)
	{
		printf("*(Ptr + i) : %d ", *(o_ArrPtr + i));
		printf("*(o_Arr + i) : %d ", *(o_Arr + i));
		printf("o_Arr[i] : %d ", o_Arr[i]);
		printf("Ptr[i] : %d\n", o_ArrPtr[i]);
	}

	// 배열과 포인터의 정리
	/*
	  (Ptr + 0) (Ptr + 1) (Ptr + 2) // 포인터 변수 주소의 연산
	  (Arr + 0) (Arr + 1) (Arr + 2) // 배열 이름(주소) 연산
	  Ptr[0] = *(Ptr + 0)
	  Arr[0] = *(Arr + 0)
	  Ptr[0] Ptr[1] Ptr[2]  // 해당 주소의 값을 출력 역참조
	  Arr[0] Arr[1] Arr[2]  // 해당 주소의 값을 출력 역참조
	  배열과 포인터 사이의 공식 : arr[i] = *(arr + i)
	 */

	 // 잘못된 포인터의 사용 : 널 포인터

	//int* ob_numPtrA = 0x100000;
	//printf("%p", ob_numPtrA);   // 0x1000000 메모리 주소에 값이 있을수도 있고 없을수도 있고
	//printf("%d", *ob_numPtrA);  // 포인터를 직접 주소 배정해주는 것을 위험. 오류가 발생할 가능성이 매우 높다

	//int* ob_numPtrA = 0;
	//int* ob_numPtrA = NULL;  // nullPtr    NULL : 널 포인터. 이 주소가 아무것도 가리키고 있지 않다. 
	printf("\n");

	// 예제3 길이가 6인 배열을 선언 후 1,2,3,4,5... -> 6,5,4,3,.... 로 출력
	printf("예제3\n");
	int t_Arr[6] = { 1, 2, 3, 4, 5, 6 };
	int* frontPtr = (t_Arr + 0);
	int* backPtr = (t_Arr + 5);
	int temp;

	printf("바꾸기 이전의 값 \n");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", t_Arr[i]);
	}

	printf("\n");
	for (int i = 0; i < 3; i++) // 배열의 길이 (6) 나누기 2 한 값 : 3
	{
		temp = *frontPtr;
		*frontPtr = *backPtr;
		*backPtr = temp;
		frontPtr++;
		backPtr--;
	}

	printf("바꾸기 이후의 값 \n");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", t_Arr[i]);
	}
}
