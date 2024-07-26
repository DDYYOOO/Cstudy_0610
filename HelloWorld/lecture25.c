#include"lectures.h"
#include<stdlib.h>

// 구조체
// 데이터를 반복문으로 표현
// 주소의 시작 점에서 다양한 데이터 자료를 사용할 수 있다
// 


// 1. 구조체 선언 : 키워드 struct

#pragma pack(push, 4)
typedef struct People
{
	char name[25];
	int age;
}People;

#pragma pop
typedef struct Point
{
	int posX;
	int posY;
}Point;

typedef struct Rectange
{
	Point leftUpPos;
	Point rightDownPos;
}Rectange;

typedef struct Circle
{
	Point centerPos;
	double radius;
}Circle;

void ShowCircleInfo(Circle circle)
{
	printf("원의 원점 좌표 : [%d, %d]\n", circle.centerPos.posX, circle.centerPos.posY);
	printf("원의 반지름 좌표 : %lf\n", circle.radius);
}

void ShowRectangeInfo(Rectange rectange)
{
	// Call By Value
	printf("사각형의 leftUp좌표 : [%d, %d]\n",rectange.leftUpPos.posX, rectange.leftUpPos.posY); 
	printf("사각형의 lefDown좌표 : [%d, %d]\n", rectange.leftUpPos.posX, rectange.rightDownPos.posY);
	printf("사각형의 rightDown좌표 : [%d, %d]\n", rectange.rightDownPos.posX, rectange.rightDownPos.posY);
	printf("사각형의 rightUp좌표 : [%d, %d]\n", rectange.rightDownPos.posX, rectange.leftUpPos.posY);
}

void ShowPointInfo(Point* pPtr, int xValue, int yValue)
{
	pPtr->posX = xValue;
	pPtr->posY = yValue;

	printf("x좌표 : %d y좌표 : %d\n", pPtr->posX, pPtr->posY);

}

Point AddPoint(Point p1, Point p2)
{
	Point newPoint;
	newPoint.posX = p1.posX + p2.posX;
	newPoint.posY = p1.posY + p2.posY;
	return newPoint;
}



void lectures25()
{
	// 구조체 변수 선언 및 사용
	struct People p1;

	strcpy_s(p1.name, 20, "홍길동");
	p1.age = 10;
	printf("%s %d\n", p1.name, p1.age);

	Point point1 =
	{
		{10}, {5}
	};

	point1.posX = 10;
	point1.posY = 10;

	printf("x좌표 : %d y좌표 : %d\n", point1.posX, point1.posY);

	Point pointArr[3] =
	{
		(1, 2),
		(10, 20),
		(30, 40)
	};

	// 4. 구조체를 배열로 표현

	for (int i = 0; i < 3; i++)
	{
		printf("x좌표 : %d y좌표 : %d \n", pointArr[i].posX, pointArr[i].posY);
	}

	People peopleArr[3] =
	{
		("이순신", 21),
		("강감찬", 22),
		("장보고", 23)
	};
	//strcpy(peopleArr->name, 21, "이순신");
	//
	//for (int i = 0; i < 3; i++)
	//{
	//	printf("이름 : %d 나이 : %d\n", peopleArr[i].name, peopleArr[i].age);
	//}

	// 5. 구조체 포인터

	Point point3 = { 1, 2 };
	Point* pPtr = &point3;
	pPtr->posX = 5; // == (*pPtr).posX = 10; == point3.posX = 10;
	point3.posX = 7;
	(*pPtr).posX = 9;

	printf("point3의 값 : %d\n", point3);

	People p4;
	People* peoplePtr = &p4;

	//peoplePtr->name = "홍길동";
	strcpy_s(peoplePtr->name, 20, "홍길동");
	peoplePtr->age = 20;

	printf("%s %d\n", peoplePtr->name, peoplePtr->age);

	// 예제 1
	// point 좌표를 구조체 포인터로 값을 변경해서 출력

	Point point4 = { 2, 4 };

	ShowPointInfo(&point4, 4, 8);

	// 6. 동적 할당. 주소의 메모리를 직접 할당 해줄 수 있다 malloc - free

	People* newPeoplePtr = malloc(sizeof(People));

	printf("People구조체의 크기 : %d\n", sizeof(People));

	strcpy_s(newPeoplePtr->name, 20, "이순신");
	newPeoplePtr->age = 30;

	printf("%s %d\n", newPeoplePtr->name, newPeoplePtr->age);
	free(newPeoplePtr);

	// 구조체 포인터의 동적 할당을 할 때는 반드시 sizeof 구조체 이름으로 선언
	// 구조체의 크기는 구조체 안의 모든 데이터 크기 x 수 더한 방식으로 저장되지 않기 때문

	Rectange r1 = { { 1, 2 }, { 4, 8 } };
	
	ShowRectangeInfo(r1);

	Circle c1;
	c1.centerPos.posX = 0;
	c1.centerPos.posY = 0;
	c1.radius = 5;

	ShowCircleInfo(c1);

	Point c_p1 = { 1, 1 };
	Point c_p2 = { 2, 3 };
	Point c_p3 = AddPoint(c_p1, c_p2);

	AddPoint(c_p1, c_p2);

	printf("AddPoint함수 : [%d, %d]\n", c_p3.posX, c_p3.posY);

}