#include<stdio.h>
#include<string.h>

typedef int MyInt;
typedef int* MyIntPtr;

typedef struct Monster
{
	char name[30];
	char region[30];
	char grade[30];
}Monster;

int Compare(char* str1, char* str2) // 반환하는 값이 0이면 다르다, 1이면 같다
{
	while (*str1)
	{
		if (*str1 != *str2)
		{
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str2 == '\0') // 같으면 1을 반환
	{
		return 1;
	}
	
	return 0;
}


void SearchMonsterName(Monster monster)
{
	char searchname[30];
	printf("검색할 몬스터의 이름 입력 : ");
	scanf_s("%s", searchname, 30);
	if (Compare(monster.name, searchname))
	{
		printf("해당 몬스터를 찾았습니다.\n");
		printf("몬스터 이름 : %s, 몬스터 지역 : %s , 몬스터 등급 : %s\n", monster.name, monster.region, monster.grade);
	}
}

void AddMosnterInfo(Monster(*monster)[100], int* monsterIndexPtr)
{
	char newName[30];
	char region[30];
	char grade[30];
	printf("변경할 몬스터의 이름을 입력 : ");
	scanf_s("%s", newName, 30);
	printf("변경할 몬스터의 지역을 입력 : ");
	scanf_s("%s", region, 30);
	printf("변경할 몬스터의 등급을 입력 : ");
	scanf_s("%s", grade, 30);

	strcpy_s(monster[*monsterIndexPtr]->name, 30, newName);
	strcpy_s(monster[*monsterIndexPtr]->region, 30, region);
	strcpy_s(monster[*monsterIndexPtr]->grade, 30, grade);

	(*monsterIndexPtr)++;
}

void ShowMonsterInfo(Monster monster)
{
	printf("몬스터의 이름 : %s\n", monster.name);
	printf("몬스터의 서식지 : %s\n", monster.region);
	printf("몬스터의 등급 : %s\n", monster.grade);
}

int main()
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