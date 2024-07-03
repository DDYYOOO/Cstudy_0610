#include<stdio.h>
#include<stdbool.h>
#include"Console.h" // 프로젝트 안에 " "있는 파일을 찾아서 복사
#include"time.h"
#include<stdlib.h>
#include<conio.h> // console input output

#define MAX 30 // 전처리기로 MAX의 값을 전부 10으로 치환하는 코드 (컴파일 시점)
#define BG 0


void StartMenu(void)
{
	while (true)
	{
		Clear();
		GotoXY(10, 9);
		printf("별 피하기");
		GotoXY(2, 15);
		printf("키를 입력하여 시작하세요.");
		
		if (_kbhit())  // 아무 키를 입력 하면 true, 입력 안하면 false
			break;
	}

}


void GameOver(void)
{
	while (true)
	{
		Clear();
		GotoXY(10, 9);
		printf("사망했습니다");
		GotoXY(2, 15);
		printf("키를 종료하세요.");

		if (_kbhit())  // 아무 키를 입력 하면 true, 입력 안하면 false
			break;
	}
}


int main()
{
	// 콘솔창의 게임의 맵의 크기를 만들어야 한다
	SetTitle("별피하기_이동윤");
	SetColor(BG, 15);
	SetConsoleSize(30, 30);
	SetConsoleCursorVisibility(0);
	// 맵의 크기를 만들고 난 다음 움직일 수 있는 캐릭터
	// 캐릭터 + 움직인다
	// 플레이어의 총알 구현(Bullet)
	// GotoXY, printf함수를 이용해서 구현
	
	int Score = 0;

	int x = 14, y = 28;		// 플레이어의 x,y좌표
	bool IsPlayerDead = false; // 플레이어가 현재 죽지 않음
	int bx = 0, by = 0;		// 총알의 x,y좌표
	bool bullet = false;    // 현재 총알이 생성되지 않았으면 false, 생성됐으면 true
	
#if false // 별을 한개씩 떨어뜨리는 코드 비활성화
	int ex = 0, ey = 0;     // 별의 x, y좌표
	bool emeny = false;	// 몬스터가 시작될 때 false, 생성될 때 true
#endif
	// 배열로 별을 생성하는 코드
	int ex[MAX] = {0};
	int ey[MAX] = {0};
	bool emeny[MAX] = {false};
	srand(time(NULL)); // rand함수의 Seed값을 현재 시간에 따라 변경
	
	int PlayerHP = 5;

	StartMenu();

	while (true)
	{
		Clear();

		GotoXY(0, 0);
		printf("Score : %d", Score);
		Score++;

		GotoXY(0, 2);
		printf("체력 : %d", PlayerHP);
		

#if true	// 플레이어의 이동 조작
		if (GetAsyncKeyState(VK_LEFT) & 8001)  // 왼쪽 키를 눌렀을 때 아래 코드를 실행
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
				printf("★");
				ey[i]++;
				
				// bx, by 총알과 별의 좌표가 같으면 bullet, emeny의 bool값은 false
				if (bx == ex[i] && by == ey[i] && bullet == true)
				{
					bullet = false;
					emeny[i] = false;
				}

				if (x == ex[i] && y == ey[i]) // 플레이어가 충돌
				{
					PlayerHP--;
					// 플레이어가 죽었을 때 작동하는 로직
					if (!IsPlayerDead)
					{
						GotoXY(x, y);
						printf("＠");
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

		// 살아있을 때 와 죽었을 때 현재 플레이어의 위치에 출력
		if (!IsPlayerDead)
		{
			SetColor(BG, 12);
			GotoXY(x, y);
			printf("■");
		}
		else
		{
			GotoXY(x, y);
			printf("＠");
			break;
		}

#endif

#if false
		if (!emeny)		// emeny가 없으면 생성
			{
				//(rand() % 15)	   // rand( ) => 0 ~ 14를 반환해주는 값
				ex = (rand() % 15) * 2; // 0 ~ 28 사이의 값 반환
				ey = 0;
				emeny = true;

			}

		if (emeny)
		{
			GotoXY(ex, ey);
			printf("★");
			ey++;

			if (ey > 28)
			{
				emeny = false;
			}
		}
#endif

		Sleep(50); // Sleep안에 있는 숫자 만큼 기다렸다가 실행
	}

	GameOver();
}