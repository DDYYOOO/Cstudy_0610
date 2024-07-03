#include<stdio.h>
#include<stdbool.h>
#include"Console.h" // ������Ʈ �ȿ� " "�ִ� ������ ã�Ƽ� ����
#include"time.h"
#include<stdlib.h>
#include<conio.h> // console input output

#define MAX 30 // ��ó����� MAX�� ���� ���� 10���� ġȯ�ϴ� �ڵ� (������ ����)
#define BG 0


void StartMenu(void)
{
	while (true)
	{
		Clear();
		GotoXY(10, 9);
		printf("�� ���ϱ�");
		GotoXY(2, 15);
		printf("Ű�� �Է��Ͽ� �����ϼ���.");
		
		if (_kbhit())  // �ƹ� Ű�� �Է� �ϸ� true, �Է� ���ϸ� false
			break;
	}

}


void GameOver(void)
{
	while (true)
	{
		Clear();
		GotoXY(10, 9);
		printf("����߽��ϴ�");
		GotoXY(2, 15);
		printf("Ű�� �����ϼ���.");

		if (_kbhit())  // �ƹ� Ű�� �Է� �ϸ� true, �Է� ���ϸ� false
			break;
	}
}


int main()
{
	// �ܼ�â�� ������ ���� ũ�⸦ ������ �Ѵ�
	SetTitle("�����ϱ�_�̵���");
	SetColor(BG, 15);
	SetConsoleSize(30, 30);
	SetConsoleCursorVisibility(0);
	// ���� ũ�⸦ ����� �� ���� ������ �� �ִ� ĳ����
	// ĳ���� + �����δ�
	// �÷��̾��� �Ѿ� ����(Bullet)
	// GotoXY, printf�Լ��� �̿��ؼ� ����
	
	int Score = 0;

	int x = 14, y = 28;		// �÷��̾��� x,y��ǥ
	bool IsPlayerDead = false; // �÷��̾ ���� ���� ����
	int bx = 0, by = 0;		// �Ѿ��� x,y��ǥ
	bool bullet = false;    // ���� �Ѿ��� �������� �ʾ����� false, ���������� true
	
#if false // ���� �Ѱ��� ����߸��� �ڵ� ��Ȱ��ȭ
	int ex = 0, ey = 0;     // ���� x, y��ǥ
	bool emeny = false;	// ���Ͱ� ���۵� �� false, ������ �� true
#endif
	// �迭�� ���� �����ϴ� �ڵ�
	int ex[MAX] = {0};
	int ey[MAX] = {0};
	bool emeny[MAX] = {false};
	srand(time(NULL)); // rand�Լ��� Seed���� ���� �ð��� ���� ����
	
	int PlayerHP = 5;

	StartMenu();

	while (true)
	{
		Clear();

		GotoXY(0, 0);
		printf("Score : %d", Score);
		Score++;

		GotoXY(0, 2);
		printf("ü�� : %d", PlayerHP);
		

#if true	// �÷��̾��� �̵� ����
		if (GetAsyncKeyState(VK_LEFT) & 8001)  // ���� Ű�� ������ �� �Ʒ� �ڵ带 ����
		{
			if (x < 1)
				x = 1;
			x -= 2;		  
		}
		else if(GetAsyncKeyState(VK_RIGHT) & 8001)
		{
			if (x > 27)
				x = 27;
			x += 2;		  
		}
		else if (GetAsyncKeyState(VK_UP) & 8001)
		{
			if (y < 1)
				y = 1;	
			y -= 2;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 8001)
		{ 
			if (y > 28)
				y = 28;
			y += 2;		  
		}
#endif

#if true   // �Ѿ�
		if (GetAsyncKeyState(VK_SPACE) & 8001)
		{
			if (!bullet)// !bullet �� bullet == false�� ���� �ǹ�
			{
				bx = x;
				by = y - 1;
				bullet = true;
			}
		}

		if (bullet)
		{
			by--;
			GotoXY(bx, by);
			printf("��");
		
			if (by < 1)
				bullet = false;
		}
#endif	




#if true
		for (int i = 0; i < MAX; i++)
		{
			if (!emeny[i])
			{
				ex[i] = (rand() % 15) * 2;
				ey[i] = 0;
				emeny[i] = true;
				break;
			}
		}
		for(int i = 0; i < MAX; i++)
		{
			if (emeny[i])
			{
				SetColor(BG, rand() % 15);
				GotoXY(ex[i], ey[i]);
				printf("��");
				ey[i]++;
				
				// bx, by �Ѿ˰� ���� ��ǥ�� ������ bullet, emeny�� bool���� false
				if (bx == ex[i] && by == ey[i] && bullet == true)
				{
					bullet = false;
					emeny[i] = false;
				}

				if (x == ex[i] && y == ey[i]) // �÷��̾ �浹
				{
					PlayerHP--;
					// �÷��̾ �׾��� �� �۵��ϴ� ����
					if (!IsPlayerDead)
					{
						GotoXY(x, y);
						printf("��");
						if(PlayerHP <= 0)
							IsPlayerDead = true;
					}

				}

				if (ey[i] > 28)
				{
					emeny[i] = false;
				}
			}
		}

		// ������� �� �� �׾��� �� ���� �÷��̾��� ��ġ�� ���
		if (!IsPlayerDead)
		{
			SetColor(BG, 12);
			GotoXY(x, y);
			printf("��");
		}
		else
		{
			GotoXY(x, y);
			printf("��");
			break;
		}

#endif

#if false
		if (!emeny)		// emeny�� ������ ����
			{
				//(rand() % 15)	   // rand( ) => 0 ~ 14�� ��ȯ���ִ� ��
				ex = (rand() % 15) * 2; // 0 ~ 28 ������ �� ��ȯ
				ey = 0;
				emeny = true;

			}

		if (emeny)
		{
			GotoXY(ex, ey);
			printf("��");
			ey++;

			if (ey > 28)
			{
				emeny = false;
			}
		}
#endif

		Sleep(50); // Sleep�ȿ� �ִ� ���� ��ŭ ��ٷȴٰ� ����
	}

	GameOver();
}