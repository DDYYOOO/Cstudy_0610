/*
	작성자 : 이동윤
	작성일 : 2024-07-23
	학습 목표 : 구조체
*/


#include"lectures.h"
#include<stdbool.h>

// 구조체의 멤버 변수를 초기화 하는 법
// 
// 구조체와 포인터
typedef struct Item
{
	int itemX;
	int itemY;
	int* itemPtr;
}Item;

typedef struct Player2
{
	int playerX;
	int playerY;
	bool isplayerDead;
}Player2;

typedef struct ToyMonster
{
	char* MonsterName;
	char* MonsterGrade;
	bool Sexual;

}Monster;

void ChangePlayerInfoByStruct(Player2* p2, int addValue)
{
	// 구조체 포인터로 멤버를 바꾸는 방법 : ->연산자
	p2->playerX += addValue; // *playerX += AddValue;
	p2->playerY += addValue; // *playerY += AddValue;
	p2->isplayerDead = !(p2->isplayerDead); //*isplayerDead = !(*isplayerDead);
}

void ChangeItemInfoByStruct(Item* t1, int addValue)
{
	t1->itemX += addValue;
	t1->itemY += addValue;
}

void ChangePlayerInfo(int* playerX, int* playerY, bool *isplayerDead, int AddValue)
{
	*playerX += AddValue;
	*playerY += AddValue;
	*isplayerDead = !(*isplayerDead); // !((*(isplayer : 주소를 담고 있는 변수)) : 가리키는 값 false) => true

}



void lectures24()
{
	// playerX, playerY, isPlayerDead : 플레이어의 좌표(x, y), 플레이어의 생존 여부 
	// Call by Reference 
	int playerX = 5, playerY = 5;
	bool isPlayerDead = false;
	
	// Structure 자료구조
	struct Player
	{
		int playerX;
		int playerY;
		bool isplayerDead;
	};

	// typedef 키워드를 사용하여 구조체 선언
	typedef struct Player2
	{
		int playerX;
		int playerY;
		bool isplayerDead;
	}Player2;
	// 구조체 안에서 초기화를 할 수 없다


	// struct(구조체) Player(데이터 타입) p1(변수);
	// Player2(데이터 타입) p2(변수);
	struct Player p1;
	Player2 p2;
	Item t1; 

	t1.itemX = 0, t1.itemY = 0;
	int some = 1;
	t1.itemPtr = &some;
	printf("some의 값 : %d\n", some);
	*t1.itemPtr = 10;
	printf("some의 값 : %d\n", some);

	// Item 구조체 변수를가리키는 주소를 지정하는 변수(포인터) 선언
	Item* t1Ptr = &t1;

	// 구조체의 주소를 이용해서 구조체 변수에 접근
	(*t1Ptr).itemX = 20; // t1Ptr.itemX = 20 와 같은 의미
	//*t1Ptr.itemX; // 에러. t1Ptr변수의 itemX를 역참조
	printf("Item의 itemX의 값 : %d\n", t1.itemX);

	// (*포인터변수).멤버변수; vs *포인터변수.멤버변수의 차이점
	// *역참조 연산자 : 우선 순위가 오른쪽 먼저 연산하기 때문에, *포인터변수.멤버변수의 선 선언 멤버변수의 역참조 의미
	// (*포인터변수).멤버변수 사용을 하면, (포인터 변수가 가리키는 값). 멤버 변수에 접근
	// 구조체 포인터를 이용해서 멤버 변수를 수정하기 위해서 (*포인터변수이름) <- 이 형태로 반드시 사용해야 함

	// 화살표 연산자 : 구조체 포인터에서 사용하는 연산자
	t1Ptr->itemX = 10; // (*t1Ptr).itemX = 10;

	// 정리
	// 구조체의 변수 선언 : typedef struct이름 (int a;, int b;, int* Ptr;)이름;
	// 구조체를 선언하고 그 구조체의 변수에 접근하는 연산자 (.)
	// 구조체 타입* 포인터이름 = &구조체타입변수
	// 동적 할당 malloc
	// 구조체 포인터를 이용해서 값을 변경하기 위해 -> 화살표 연산자를 사용


	// 구조체의 멤버 변수를 사용하는 방법 : (.)연산자
	p1.playerX = 5;
	p1.playerY = 5;
	p1.isplayerDead = true;
	
	printf("Player구조체 출력 = playerX : %d, playerY : %d, isPlayerDead : %d\n", p1.playerX, p1.playerY, p1.isplayerDead);

	p2.playerX = 5;
	p2.playerY = 5;
	p2.isplayerDead = true;

	printf("Player2구조체 출력 = playerX : %d, playerY : %d, isPlayerDead : %d\n", p2.playerX, p2.playerY, p2.isplayerDead);

	t1.itemX = 5;
	t1.itemY = 5;
	//Item* t1Ptr = &t1;

	printf("Item구조체 출력 = itemX : %d, itemY : %d\n", t1Ptr->itemX, t1Ptr->itemY);

	ChangePlayerInfo(&playerX, &playerY, &isPlayerDead, 5);
	printf("playerX : %d, playerY : %d, isPlayerDead : %d\n", playerX, playerY, (bool)isPlayerDead);

	ChangePlayerInfoByStruct(&p1, 5);
	printf("playerX : %d, playerY : %d, isPlayerDead : %d\n", p2.playerX, p2.playerY, (bool)isPlayerDead);

	// 주소. 데이터 타입(4byte) n개
	// 서로 다른 데이터 타입을 사용할 수 있는 하나의 타입을 만들 수 있는 기능 -> 구조체

	ChangeItemInfoByStruct(&t1, 10);
	printf("itemX : %d, itemY : %d\n", t1.itemX, t1.itemY);

	Monster monster;
	
	monster.MonsterGrade = "일반";
	monster.MonsterName = "고블린";

	printf("몬스터의 이름 : %s 몬스터의 등급 : %s \n", monster.MonsterName, monster.MonsterGrade);
}
