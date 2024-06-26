/*
  switch조건문

  switch(변수)
  {
	case 변수의 값 :
	실행되는 코드
	break;

	case 변수의 값 :
	실행되는 코드
	break;

	case 변수의 값 :
	실행되는 코드
	break;

	...
	...
	...

	default :
	break;
  }

*/

/*
  형식이 균일할 때, 처리해야할 조건이 다양할 때 사용하는 조건문
*/

#include"lectures.h"

void lectures13_switch()
{
	int num;
	scanf_s("%d", &num);

	//switch (num)
	//{
	//case 0:
	//	printf("0입니다\n");
	//	break;
	//case 1:
	//	printf("1입니다\n");
	//	break;
	//case 2:
	//	printf("2입니다\n");
	//	break;
	//default:
	//	printf("num은 0 ~ 2이외의 값입니다.\n");
	//	break;
	//}

	// 위의 switch문을 if else if로 바꿈
	//if (num == 0)
	//	printf("0입니다\n");
	//else if (num == 1)
	//	printf("0입니다\n");
	//else if (num == 2)
	//	printf("0입니다\n");
	//else
	//	printf("num은 0 ~ 2이외의 값입니다.\n");

	switch (num)
	{
	case 0:
	case 1:
		printf("0 ~1의 값이 나올 확률 : \n");
		break;
	case 2:
	case 3:
	case 4:
		printf("2, 3, 4의 값이 나올 확률 : \n");
	default:
		printf("num은 0 ~ 2이외의 값입니다.\n");
		//break;
	}

	// switch()  - ( )안에 올 수 있는 데이터 타입은 정수형만 가능. 실수형 데이터 타입을 넣으면 에러가 남

	//double d_num = 1.25;
	char c_num = 'A';
	switch (c_num)		// case와 콜론(:) 사이에 들어가는 값은 정수가 아니고, 정수의 값으로 반환되는 식이여도 상관없다.
	{
	case 1<<2 :
		break;
	case 'A':
		break;
	case 2+3+4:
		break;
	}
}