/*
	작성자 : 이동윤
	작성일 : 2024-07-22
	학습 목표 : 
*/


#include"lectures.h"

void ChangeDoubleArrValue(int(*tPArr)[4], int addValue)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tPArr[i][j] += 1;
		}
	}
}

// char방식으로 tpArr의 값을 변경하는 함수를 작성

void ChangeCharValueIndoubleArr(char(*tPArr)[4], char addChar)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tPArr[i][j] = addChar;
		}
	}
}

void lectures23()
{
	// 변수 선언 : int num
	int num = 10;
	// 포인터 선언
	int* numPtr = &num;
	// 포인터의 포인터 선언
	int** numpPtr = &numPtr;

	printf("변수 : %d, 포인터로부터 값 호출 : %d, 포인터의 포인터 값 호출 : %d\n", num, *numPtr, **numpPtr);

	int Arr[3] = {1, 2, 3};
	int* aPtr = Arr;

	for (int i = 0; i < 3; i++)
	{
		printf("Arr배열의 값 : %d ", *(aPtr + i));
	}
	printf("\n");

	// 2차원 배열

	int Arr2[3][4] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}

	};

	// 배열의 주소를 가져오는 법
	//int* pArr[3] = &Arr;
	//int(*pArr)[3] = &Arr;

	//int** doublePtr = &Arr2;

	// 2차원 배열을 포인터에 넣기
	// int (*포인터 이름)[가로]; = 가로크기가 n인 배열을 가르키는 포인터
	
	int(*pArr2)[4] = Arr2;
	int** doublePtr = Arr2;

	printf("Arr2의 주소 : %p\n", Arr2);
	printf("pArr2의 주소 : %p\n", pArr2);
	printf("doublePtr의 주소 : %p\n", doublePtr);

	// 포인터 변수의 크기를 확인
	printf("Arr2의 크기 : %d\n", sizeof(Arr2));
	printf("pArr2의 크기 : %d\n", sizeof(pArr2));
	printf("doublePtr의 크기 : %d\n", sizeof(doublePtr));

	// 2차원 배열에서 배열을 포인터로 표시
	int Arr3[3][4] = {0};
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("Arr3의 이전 값 : %d ",Arr3[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	ChangeDoubleArrValue(Arr3, 1);


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("Arr3의 이후 값 : %d ", Arr3[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	// Arr[x][y] == (*(Arr + x))[y] == (*(Arr + x) + y);  // A 치환 : *(Arr + x) // A[y] // A다시 치환값을 넣음

	// 2차원 배열을 포인터로 표시하고 값으로 출력
	printf("2차원 배열의 값 : %d\n", Arr2[1][2]);
	printf("2차원 배열을 포인터로 표시한 값 : %d\n", *(*(Arr2 + 1) + 2));
	printf("2차원 배열에서 세로의 크기의 주소를 출력한 값 : %p\n", (*(Arr2 + 1)));
	printf("2차원......세로의 크기가 1이고, 거기서 int 크기만큼 +2한 주소 값 : % p\n", (*(Arr2 + 1) + 2));
	printf("\n");

	// Arr[3][4] 에서 Arr[i]의 의미 : 크기가 4인 int배열이 3개 있는데 그 중에서 i번째 배열을 가리켜라
	// doublePtr : 주소의 주소를 Arr[3][4] 표시만 가능하지, 2차원 배열은 표현할 수 없음
	// 2차원 배열 : int(*Arr[세로])[가로]; 
	// 포인터의 배열 : int* Arr[크기] : 정수형 포인터 배열

	// 정리
	// 2차원 배열을 포인터로 표현하기 위해서는, 반드시 배열의 갯수를 명시해줘야 함
	// 데이터타입 (*포인터변수이름)(배열크기) = 이중 포인터의 주소를 지정할 수 있음

	//ChangeCharValueIndoubleArr함수를 호출해서, 안에 있는 값을 #, $ 변하도록 작성

	char map[3][4] = {0};

	ChangeCharValueIndoubleArr(map, '#');
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("map 값 : %c ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	ChangeCharValueIndoubleArr(map, '$');
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("map 값 : %c ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");



}