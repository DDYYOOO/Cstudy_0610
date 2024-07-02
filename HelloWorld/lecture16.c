/*
	작성자 : 이동윤
	작성일 : 2024-07-02
	학습 목표 : 배열
*/

/*
  배열의 선언
  변수의 선언 : (데이터 형식)(변수이름) = 값;
  배열의 선언 : (데이터 형식)(배열이름)[];

  배열을 선언 하는 방법
  1) 데이터형 배열이름[배열의 수]
  2) 
*/

#include"lectures.h"
#include<stdbool.h>

void lectures16()
{
	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;

	// 배열1
	int arr[10] = { 0 };

	// 배열2
	int arr2[] = {0, 1, 2, 3, 4, 5}; 

	// 배열3
	int arr3[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (int i = 0; i < 10; i++)
	{
		printf("배열에 들어간 요소 출력 : %d\n", arr[i]);
		printf("배열2에 들어간 요소 출력 : %d\n", arr2[i]);
		printf("배열3에 들어간 요소 출력 : %d\n", arr3[i]);
	}

	int ex[10] = {0};
	int ey[10] = {0};
	bool emeny[10] = { false };

	for (int i = 0; i < 10; i++)
	{
		printf("ex값 출력 : %d, ey값 출력 : %d, emeny값 출력 : %d\n", ex[i], ey[i], emeny[i]);
	}

}