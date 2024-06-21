/*
	작성자 : 이동윤
	작성일 : 2024-06-20
	학습 목표 : C언어의 기본 자료형 + 상수
*/

// 자료형이 무엇인가?
// 변수 => (자료형) (변수이름)
// 자료형은 변수를 만들기 위해서 필요한거다.
// 수를 구분할 필요가 있다. <정수, 실수>
// 정수를 사용 -> 얼마만큼 데이터를 저장할 것인가?
// char 변수이름 = 0b0000001;
// int 변수이름 = 0b 00000000 00000000 00000000 00000001;
// long long 변수이름 = 0b 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000001;
// 데이터가 저장될 메모리의 크리글 지정하기 위해 사용한다.
// 어떤 데이터 타입(정수, 실수)사용할 지 지정한 후 그 데이터의 크기를 지정한 키워드를 data type(자료형)이라 한다.
// "int" : 4바이트 공간, 정수형 데이터 저장할 공간 -> 변수이름.

/*
	기본 자료형의 종류와 데이터의 표현범위
	(1)정수형
	char	  : 1바이트(8비트) 2e8(256)  -2e7 ~ 2e7 -1 표현한다(-128 ~ 127 -> 256개)
	short	  : 2바이트(16비트) -2e15 ~ 2e15 -1
	int		  : 4바이트(32비트) -2e31 ~ 2e31 -1
	long	  : 4바이트(32비트) ~ 8바이트(64비트)
	long long : 8바이트(64비트) -2e63 ~ 2e63 -1

	ANSI : American National Standards Institue(C언어의 표준을 정하는 협회)
		   컴파일러가 데이터형의 최소 크기를 지켜라

	(2)실수형
	float	   : 4바이트 (부호)(지수부)(가수부) -> 소수점 6자리 표현
	double	   : 8바이트 소수점 15자리 표현
	long float : 8바이트 소수점 18자리 표현
*/

/*
	1부호(MSB) 0, 1 음수, 양수...
	부호가 필요 없다 -> unsigned
	unsigned char 변수 이름 : 0 ~ 2e8개 저장. 부호없는 정수 표현식.
	unsigned int 변수 이름 : 0 ~ 2e32개 저장.
*/

/*
	sizeof 연산자 -> 정수 (n)바이트..
	int a = 10;
	int i_num = sizeof(int);    4
	int i_num = sizeof a;       sizeof() 한다고해서 함수가 아닌다.
	int i_num = sizeof (a);     일반적으로 ()와 함께 사용한다.
*/

/*
	상수
	변하지 않는 수
	변수 - 자료형.

	종류 : 이름을 갖는 상수, 이름을 갖지 않는 상수
	리터럴 상수 (literal) : 문자 그대로 변하지 않는 수.
	double my_double = 3.15;

	int my_int = 10;    int형 상수
	char my_char = 5;   int형 상수
	short my_short = 7; int형 상수
	int my_int = 30억보다 큰 수 2e31 -1 

	리터럴상수
	정수는 기본 자료형이 int
	int보다 큰 수가 입력이 되면 자동으로 int 보다 큰 데이터형이 선택

	int 보다 작은, char, short는 왜 int로 컴파일러가 지정이 될까>
	가장 많이 처리하는 데이터 타입 int
	short -> char int계산된 녀석들과 연산을 해야 하는 경우가 잦다
	컴퓨터가 처리할 수 있는 가장 빠른 단위(int) 지정해서 데이터 타입을 바꾸어 주고 있다. (컴파일러, 사람)

	실수는 기본 자료형이 double
	double my_double = 3.15;
	float my_float = 3.15;

	my_long = 3.15l;
	UL       : unsigned long
	LL       : long long
	UL:      : unsigned long long
	
	F      : float
	L      : long float
*/

/*
	이름 있는 상수 : 심볼릭 상수(const, define)
	중력의 크기 : -9.8f
	파이		   : 3.141592.....

	float gravity = -9.8f;  // 중력의 크기라 변하면 안됨
	const gravity = -9.8f;   // const 선언과 동시에 초기화를 해줘야 한다.
	const gravity = -9.0f;  // 변수에 새로운 수를 집어 넣으면 에러가 뜨게 함

	전처리기가 컴파일하기 전에 GRAVITY라는 변수를 -9.8로 변환시킨다.
	#define GRAVITY = -9.8f

	상수를 작성할 때 이름 명명 방법
	대문자로 작성을 해주되, 단어를 띄어 써야할 경우 '_'로 작성(GET_TIME_PRINCPLE)

*/

#include"lectures.h"

void lectures9()
{
	printf("9강 시작\n");

	printf("★★기본 자료형 예제 문제★★\n");

	// sizeof 연산자를 사용해서 데이터형을 출력하기 
	// char, short, int long, long long, float, double, long float
	
	//char my_char;
	//printf("char 데이터 크기 : %d\n", sizeof(my_char));
	//short my_short;
	//printf("short 데이터 크기 : %d\n", sizeof(my_short));
	//int my_int;
	//printf("int 데이터 크기 : %d\n", sizeof(my_int));
	//long my_long;
	//printf("long 데이터 크기 : %d\n", sizeof(my_long));
	//long long my_longlong;
	//printf("long long 데이터 크기 : %d\n", sizeof(my_longlong));
	//float my_float;
	//printf("float 데이터 크기 : %d\n", sizeof(my_float));
	//double my_double;
	//printf("double 데이터 크기 : %d\n", sizeof(my_double));
	//long float my_longfloat;
	//printf("long float 데이터 크기 : %d\n", sizeof(my_longfloat));

	// 이렇게 하면 경고를 해결해볼 수도 있다.
	int sizeNum = sizeof(char);
	printf("char 데이터 크기 : %d\n", sizeof(char));
	sizeNum = sizeof(short);
	printf("short 데이터 크기 : %d\n", sizeof(short));
	sizeNum = sizeof(int);
	printf("int 데이터 크기 : %d\n", sizeof(int));
	sizeNum = sizeof(long);
	printf("long 데이터 크기 : %d\n", sizeof(long));
	sizeNum = sizeof(long long);
	printf("long long 데이터 크기 : %d\n", sizeof(long long));
	sizeNum = sizeof(float);
	printf("float 데이터 크기 : %d\n", sizeof(float));
	sizeNum = sizeof(double);
	printf("double 데이터 크기 : %d\n", sizeof(double));
	sizeNum = sizeof(long double);
	printf("long double 데이터 크기 : %d\n", sizeof(long double));

	//문제 2. 리터럴 상수를 sizeof연산자로 출력
	// 실수(3.15, 3.15f....), 정수(10, 11, 12...)
	// sizeof(5); 어떤값이 출력하는 함수로 표현
	
	printf("문제2\n");
	sizeNum = sizeof(10);
	printf("정수형 리터럴 상수 크키 : %d\n", sizeNum);
	sizeNum = sizeof(3.14);
	printf("실수형 리터럴 상수 크기 : %d\n", sizeNum);
	sizeNum = sizeof('A');
	printf("문자의 상수 표현의 기본 크기 : %d\n", sizeNum);



	// 문제3 직사각형의 넓이를 구하는 프로그램을 작성
	// 조건1 : 좌표를 두개 지정받아야한다 (xpos1, ypos1), (xpos2, ypos2)
	// 조건2 : xpos2가 xpos1보다 커야한다(음수 처리x)
	// xpos2 - xpos1 길이로 하는 직사각형을 구해야 한다
	// (4, 6) (6, 8) 2*2 = 4

	printf("문제3\n");
	int xpos1, xpos2, ypos1, ypos2, result;
	printf("첫번째 x, y좌표 : \n");
	scanf_s("%d %d", &xpos1, &ypos1);
	printf("두번쨰 작성된 x, y값은 첫번째 작성된 x, y보다 커야합니다\n");
	printf("두번째 x, y좌표 : \n");
	scanf_s("%d %d", &xpos2, &ypos2);
	result = (xpos2 - xpos1) * (ypos2 - ypos1);
	printf("직사각형의 넓이는 : %d\n", result);

	//심볼릭 상수 문제1.
	//const 키워드를 사용하여 파이를 PI로 저장하고 그 값을 3.14로 한다.
	//원의 넓이를 구하는 코드를 상수를 사용하여 표현하세요

	printf("심볼릭 상수 문제 1\n");
	const float PI = 3.14;
	int radius;
	printf("원의 반지름 값을 입력하세요 : ");
	scanf_s("%d", &radius);

	result = (radius * radius) * PI;
	printf("반지름이 %d 인 원의 넓이는 : %d\n", radius, result);

}