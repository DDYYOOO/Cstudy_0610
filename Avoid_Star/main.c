#include<stdio.h>
#include<stdbool.h>
#include"Console.h" // 프로젝트 안에 " "있는 파일을 찾아서 복사


int main()
{
	// 콘솔창의 게임의 맵의 크기를 만들어야 한다
	SetConsoleSize(30, 30);
	SetConsoleCursorVisibility(0);
	// 맵의 크기를 만들고 난 다음 움직일 수 있는 캐릭터
	// 캐릭터 + 움직인다
	// 플레이어의 총알 구현(Bullet)
	// GotoXY, printf함수를 이용해서 구현
	int x = 14, y = 28;		// 플레이어의 x,y좌표
	int bx = 0, by = 0;		// 총알의 x,y좌표
	bool bullet = false;    // 현재 총알이 생성되지 않았으면 false, 생성됐으면 true

	while (true)
	{
		Clear();

#if true	// 플레이어의 이동 조작
		if (GetAsyncKeyState(VK_LEFT) & 8001)  // 왼쪽 키를 눌렀을 때 아래 코드를 실행
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
		printf("■");  

#if true   // 총알
		if (GetAsyncKeyState(VK_SPACE) & 8001)
		{
			if (!bullet)// !bullet 과 bullet == false와 같은 의미
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
			printf("↑");
		
			if (by < 1)
				bullet = false;
		}
#endif	
		Sleep(100); // Sleep안에 있는 숫자 만큼 기다렸다가 실행
	}

}