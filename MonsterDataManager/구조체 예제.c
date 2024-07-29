#include<stdio.h>
#include<string.h>
#include"Function.h"

typedef int MyInt;
typedef int* MyIntPtr;


int Main()
{
	MyInt myint = 4;
	printf("%d\n", myint);

	MyIntPtr myintPtr = &myint;
	printf("%d\n", *myintPtr);

	struct Monster m1;
	strcpy_s(m1.name, 30, "고블린");
	printf("몬스터 이름 : %s\n", m1.name);

	// 비교(Compare) 함수
	char name1[30] = "홍길동";
	char name2[30] = "홍길동";
	
	if (Compare(name1, name2))
	{
		printf("같다\n");
	}
	else
	{
		printf("다르다\n");
	}

	// 구조체의 포인터 사용법
	// 구조체 변수에 주소연산자를 사용
	Monster* monsterPtr = &m1;

	//
	Monster monsterGroup[100];
	int totalonsterCount = 0;

	// 심화 과정
	//int monstersize;
	//scnaf_s("%d", &monstersize);
	//Monster* monsterGPtr[400] = malloc(sizeof(Monster) * monstersize);
	//free(monsterGPtr);

	AddMosnterInfo(monsterGroup, &totalonsterCount);
	printf("몬스터 이름 : %s, 몬스터 등급 : %s , 몬스터 지역 : %s\n", monsterGroup[0].name, monsterGroup[0].grade, monsterGroup[0].region);

	//ShowMonsterInfo(m1);
	//SearchMonsterName(m1);
	
}