#include<stdio.h>
#include<stdbool.h>
#include"Console.h" // ������Ʈ �ȿ� " "�ִ� ������ ã�Ƽ� ����


int main()
{
	// �ܼ�â�� ������ ���� ũ�⸦ ������ �Ѵ�
	SetConsoleSize(30, 30);
	SetConsoleCursorVisibility(0);
	// ���� ũ�⸦ ����� �� ���� ������ �� �ִ� ĳ����
	// ĳ���� + �����δ�
	// �÷��̾��� �Ѿ� ����(Bullet)
	// GotoXY, printf�Լ��� �̿��ؼ� ����
	int x = 14, y = 28;		// �÷��̾��� x,y��ǥ
	int bx = 0, by = 0;		// �Ѿ��� x,y��ǥ
	bool bullet = false;    // ���� �Ѿ��� �������� �ʾ����� false, ���������� true

	while (true)
	{
		Clear();

#if true	// �÷��̾��� �̵� ����
		if (GetAsyncKeyState(VK_LEFT) & 8001)  // ���� Ű�� ������ �� �Ʒ� �ڵ带 ����
		{
			if (x < 1)
				x = 1;
			x -= 1;		  
		}
		else if(GetAsyncKeyState(VK_RIGHT) & 8001)
		{
			if (x > 27)
				x = 27;
			x += 1;		  
		}
		else if (GetAsyncKeyState(VK_UP) & 8001)
		{
			if (y < 1)
				y = 1;	
			y -= 1;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 8001)
		{ 
			if (y > 28)
				y = 28;
			y += 1;		  
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
		Sleep(100); // Sleep�ȿ� �ִ� ���� ��ŭ ��ٷȴٰ� ����
	}

}