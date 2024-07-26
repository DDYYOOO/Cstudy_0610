#include"lectures.h"
#include<stdlib.h>

// ����ü
// �����͸� �ݺ������� ǥ��
// �ּ��� ���� ������ �پ��� ������ �ڷḦ ����� �� �ִ�
// 


// 1. ����ü ���� : Ű���� struct

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
	printf("���� ���� ��ǥ : [%d, %d]\n", circle.centerPos.posX, circle.centerPos.posY);
	printf("���� ������ ��ǥ : %lf\n", circle.radius);
}

void ShowRectangeInfo(Rectange rectange)
{
	// Call By Value
	printf("�簢���� leftUp��ǥ : [%d, %d]\n",rectange.leftUpPos.posX, rectange.leftUpPos.posY); 
	printf("�簢���� lefDown��ǥ : [%d, %d]\n", rectange.leftUpPos.posX, rectange.rightDownPos.posY);
	printf("�簢���� rightDown��ǥ : [%d, %d]\n", rectange.rightDownPos.posX, rectange.rightDownPos.posY);
	printf("�簢���� rightUp��ǥ : [%d, %d]\n", rectange.rightDownPos.posX, rectange.leftUpPos.posY);
}

void ShowPointInfo(Point* pPtr, int xValue, int yValue)
{
	pPtr->posX = xValue;
	pPtr->posY = yValue;

	printf("x��ǥ : %d y��ǥ : %d\n", pPtr->posX, pPtr->posY);

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
	// ����ü ���� ���� �� ���
	struct People p1;

	strcpy_s(p1.name, 20, "ȫ�浿");
	p1.age = 10;
	printf("%s %d\n", p1.name, p1.age);

	Point point1 =
	{
		{10}, {5}
	};

	point1.posX = 10;
	point1.posY = 10;

	printf("x��ǥ : %d y��ǥ : %d\n", point1.posX, point1.posY);

	Point pointArr[3] =
	{
		(1, 2),
		(10, 20),
		(30, 40)
	};

	// 4. ����ü�� �迭�� ǥ��

	for (int i = 0; i < 3; i++)
	{
		printf("x��ǥ : %d y��ǥ : %d \n", pointArr[i].posX, pointArr[i].posY);
	}

	People peopleArr[3] =
	{
		("�̼���", 21),
		("������", 22),
		("�庸��", 23)
	};
	//strcpy(peopleArr->name, 21, "�̼���");
	//
	//for (int i = 0; i < 3; i++)
	//{
	//	printf("�̸� : %d ���� : %d\n", peopleArr[i].name, peopleArr[i].age);
	//}

	// 5. ����ü ������

	Point point3 = { 1, 2 };
	Point* pPtr = &point3;
	pPtr->posX = 5; // == (*pPtr).posX = 10; == point3.posX = 10;
	point3.posX = 7;
	(*pPtr).posX = 9;

	printf("point3�� �� : %d\n", point3);

	People p4;
	People* peoplePtr = &p4;

	//peoplePtr->name = "ȫ�浿";
	strcpy_s(peoplePtr->name, 20, "ȫ�浿");
	peoplePtr->age = 20;

	printf("%s %d\n", peoplePtr->name, peoplePtr->age);

	// ���� 1
	// point ��ǥ�� ����ü �����ͷ� ���� �����ؼ� ���

	Point point4 = { 2, 4 };

	ShowPointInfo(&point4, 4, 8);

	// 6. ���� �Ҵ�. �ּ��� �޸𸮸� ���� �Ҵ� ���� �� �ִ� malloc - free

	People* newPeoplePtr = malloc(sizeof(People));

	printf("People����ü�� ũ�� : %d\n", sizeof(People));

	strcpy_s(newPeoplePtr->name, 20, "�̼���");
	newPeoplePtr->age = 30;

	printf("%s %d\n", newPeoplePtr->name, newPeoplePtr->age);
	free(newPeoplePtr);

	// ����ü �������� ���� �Ҵ��� �� ���� �ݵ�� sizeof ����ü �̸����� ����
	// ����ü�� ũ��� ����ü ���� ��� ������ ũ�� x �� ���� ������� ������� �ʱ� ����

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

	printf("AddPoint�Լ� : [%d, %d]\n", c_p3.posX, c_p3.posY);

}