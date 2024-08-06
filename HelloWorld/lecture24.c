/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-07-23
	�н� ��ǥ : ����ü
*/


#include"lectures.h"
#include<stdbool.h>

// ����ü�� ��� ������ �ʱ�ȭ �ϴ� ��
// 
// ����ü�� ������
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
	// ����ü �����ͷ� ����� �ٲٴ� ��� : ->������
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
	*isplayerDead = !(*isplayerDead); // !((*(isplayer : �ּҸ� ��� �ִ� ����)) : ����Ű�� �� false) => true

}



void lectures24()
{
	// playerX, playerY, isPlayerDead : �÷��̾��� ��ǥ(x, y), �÷��̾��� ���� ���� 
	// Call by Reference 
	int playerX = 5, playerY = 5;
	bool isPlayerDead = false;
	
	// Structure �ڷᱸ��
	struct Player
	{
		int playerX;
		int playerY;
		bool isplayerDead;
	};

	// typedef Ű���带 ����Ͽ� ����ü ����
	typedef struct Player2
	{
		int playerX;
		int playerY;
		bool isplayerDead;
	}Player2;
	// ����ü �ȿ��� �ʱ�ȭ�� �� �� ����


	// struct(����ü) Player(������ Ÿ��) p1(����);
	// Player2(������ Ÿ��) p2(����);
	struct Player p1;
	Player2 p2;
	Item t1; 

	t1.itemX = 0, t1.itemY = 0;
	int some = 1;
	t1.itemPtr = &some;
	printf("some�� �� : %d\n", some);
	*t1.itemPtr = 10;
	printf("some�� �� : %d\n", some);

	// Item ����ü ����������Ű�� �ּҸ� �����ϴ� ����(������) ����
	Item* t1Ptr = &t1;

	// ����ü�� �ּҸ� �̿��ؼ� ����ü ������ ����
	(*t1Ptr).itemX = 20; // t1Ptr.itemX = 20 �� ���� �ǹ�
	//*t1Ptr.itemX; // ����. t1Ptr������ itemX�� ������
	printf("Item�� itemX�� �� : %d\n", t1.itemX);

	// (*�����ͺ���).�������; vs *�����ͺ���.��������� ������
	// *������ ������ : �켱 ������ ������ ���� �����ϱ� ������, *�����ͺ���.��������� �� ���� ��������� ������ �ǹ�
	// (*�����ͺ���).������� ����� �ϸ�, (������ ������ ����Ű�� ��). ��� ������ ����
	// ����ü �����͸� �̿��ؼ� ��� ������ �����ϱ� ���ؼ� (*�����ͺ����̸�) <- �� ���·� �ݵ�� ����ؾ� ��

	// ȭ��ǥ ������ : ����ü �����Ϳ��� ����ϴ� ������
	t1Ptr->itemX = 10; // (*t1Ptr).itemX = 10;

	// ����
	// ����ü�� ���� ���� : typedef struct�̸� (int a;, int b;, int* Ptr;)�̸�;
	// ����ü�� �����ϰ� �� ����ü�� ������ �����ϴ� ������ (.)
	// ����ü Ÿ��* �������̸� = &����üŸ�Ժ���
	// ���� �Ҵ� malloc
	// ����ü �����͸� �̿��ؼ� ���� �����ϱ� ���� -> ȭ��ǥ �����ڸ� ���


	// ����ü�� ��� ������ ����ϴ� ��� : (.)������
	p1.playerX = 5;
	p1.playerY = 5;
	p1.isplayerDead = true;
	
	printf("Player����ü ��� = playerX : %d, playerY : %d, isPlayerDead : %d\n", p1.playerX, p1.playerY, p1.isplayerDead);

	p2.playerX = 5;
	p2.playerY = 5;
	p2.isplayerDead = true;

	printf("Player2����ü ��� = playerX : %d, playerY : %d, isPlayerDead : %d\n", p2.playerX, p2.playerY, p2.isplayerDead);

	t1.itemX = 5;
	t1.itemY = 5;
	//Item* t1Ptr = &t1;

	printf("Item����ü ��� = itemX : %d, itemY : %d\n", t1Ptr->itemX, t1Ptr->itemY);

	ChangePlayerInfo(&playerX, &playerY, &isPlayerDead, 5);
	printf("playerX : %d, playerY : %d, isPlayerDead : %d\n", playerX, playerY, (bool)isPlayerDead);

	ChangePlayerInfoByStruct(&p1, 5);
	printf("playerX : %d, playerY : %d, isPlayerDead : %d\n", p2.playerX, p2.playerY, (bool)isPlayerDead);

	// �ּ�. ������ Ÿ��(4byte) n��
	// ���� �ٸ� ������ Ÿ���� ����� �� �ִ� �ϳ��� Ÿ���� ���� �� �ִ� ��� -> ����ü

	ChangeItemInfoByStruct(&t1, 10);
	printf("itemX : %d, itemY : %d\n", t1.itemX, t1.itemY);

	Monster monster;
	
	monster.MonsterGrade = "�Ϲ�";
	monster.MonsterName = "���";

	printf("������ �̸� : %s ������ ��� : %s \n", monster.MonsterName, monster.MonsterGrade);
}
