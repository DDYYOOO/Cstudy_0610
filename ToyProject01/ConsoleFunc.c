#include"ConsoleFunc.h"

void MainMenu(int playerinput)
{
	while (1)
	{
		printf("1. ���� ����\n");
		printf("2. ���� ���\n");
		printf("3. ���� â����\n");
		printf("4. ���� ����\n");
		printf("���ڸ� �Է��ϼ��� : ");
		scanf_s("%d", &playerinput);
		if (playerinput == 1)
		{
			printf("���� ����");
		}
		if (playerinput == 2)
		{
			printf("���� ���");
		}
		if (playerinput == 3)
		{
			system("cls");
		}
		if (playerinput == 4)
		{
			printf("������ �����߽��ϴ�");
			break;
		}
	}
}