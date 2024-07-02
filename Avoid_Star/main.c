#include<stdio.h>
#include<stdbool.h>
#include"Console.h" // ������Ʈ �ȿ� " "�ִ� ������ ã�Ƽ� ����
#include"time.h"
#include<stdlib.h>

#define MAX 30 // ��ó����� MAX�� ���� ���� 10���� ġȯ�ϴ� �ڵ� (������ ����)

int main()
{
	// �ܼ�â�� ������ ���� ũ�⸦ ������ �Ѵ�
	SetConsoleSize(30, 30);
	SetConsoleCursorVisibility(0);
	SetColor(0, 15);
	// ���� ũ�⸦ ����� �� ���� ������ �� �ִ� ĳ����
	// ĳ���� + �����δ�
	// �÷��̾��� �Ѿ� ����(Bullet)
	// GotoXY, printf�Լ��� �̿��ؼ� ����
	int x = 14, y = 28;		// �÷��̾��� x,y��ǥ
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


	while (true)
	{
		Clear();

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
		GotoXY(x, y); 
		printf("��");  

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
				GotoXY(ex[i], ey[i]);
				printf("��");
				ey[i]++;
				
			}
			if (ey[i] > 28)
			{
				emeny[i] = false;
			}
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

		Sleep(100); // Sleep�ȿ� �ִ� ���� ��ŭ ��ٷȴٰ� ����
	}

}