#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	// printf�Լ��� scanf�Լ��� �ÿ��ؼ� ������ ������ ����
	// �÷��̾ ȯ���ϴ� �ؽ�Ʈ�� ��� �١�
	// printf(���ڸ� �Է��ϸ� ������ �����մϴ�)
	// scanf -> �Է��� �޴´�  Ŀ���� ������·� ����ϰ� �ִ�

	//���� �Ǵ� �Ǽ� �����͸� ���� ��ǻ�Ͱ� �����ϴ� ����� ����ϰ�, ���� �����ϴ� ����� ���� ����ϴ� ���α׷��� ����� ������

	printf("�١ڰ��� ���ۡڡ�\n");

	srand(time(NULL));
	int computerValue = rand() % 100 + 1; // 1 ~ 100�� ������ ���ڰ� computerValue�� �Է��� �ȴ�.
	int userValue;
	int startValue;
	int playerHP = 5;
	printf("�������. ���ڸ� �Է��ϸ� ������ ���۵˴ϴ� : ");
	scanf_s("%d", &startValue);

	printf("�÷��̾��� ���� �Է��ϼ��� : ");
	scanf_s("%d", &userValue);
	printf("��ǻ���� ������ �� : %d\n", computerValue);
	printf("�÷��̾��� �Է� �� : %d\n", userValue);
	
	if (computerValue > userValue)
	{
		printf("��ǻ���� ������ �� : %d�� �÷��̾��� �Է� �� : %d���� Ů�ϴ�\n", computerValue, userValue);
	}
	else
	{
		printf("��ǻ���� ������ �� : %d�� �÷��̾��� �Է� �� : %d���� �۽��ϴ�\n", computerValue, userValue);
	}

	while (1)
	{
		if (computerValue == userValue)
		{
			// �Լ�ȭ 1 : GameWin���ӿ��� �¸��� �����ϴ� �Լ� ����
			GameWin();
			break;
		}
		else
		{
			// ���� �÷��̾��� ���� ü���� 0���� �۰ų� ������ ������ ����
			if (playerHP <= 0)
			{
				printf("���� ����\n");
				break;
			}
		}
	}


	// if���� �̿��� ������ ���� ���߱� ����

	//if (computerValue != userValue)
	//{
	//	printf("Ʋ�Ƚ��ϴ�. 3�� ���ҽ��ϴ�. �ٽ� �Է��ϼ��� :");
	//	scanf_s("%d", &userValue);
	//	printf("��ǻ���� ������ �� : %d\n", computerValue);
	//	printf("�÷��̾��� �Է� �� : %d\n", userValue);
	//
	//
	//	if (computerValue != userValue)
	//	{
	//		printf("Ʋ�Ƚ��ϴ�. 2�� ���ҽ��ϴ�. �ٽ� �Է��ϼ��� :");
	//		scanf_s("%d", &userValue);
	//		printf("��ǻ���� ������ �� : %d\n", computerValue);
	//		printf("�÷��̾��� �Է� �� : %d\n", userValue);
	//
	//		if (computerValue != userValue)
	//		{
	//			printf("Ʋ�Ƚ��ϴ�. 1�� ���ҽ��ϴ�. �ٽ� �Է��ϼ��� :");
	//			scanf_s("%d", &userValue);
	//			printf("��ǻ���� ������ �� : %d\n", computerValue);
	//			printf("�÷��̾��� �Է� �� : %d\n", userValue);
	//			
	//			if (computerValue != userValue)
	//			{
	//				printf("Ʋ�Ƚ��ϴ�. ���ӿ��� �й��߽��ϴ�\n");
	//			}
	//			else
	//			{
	//				printf("�����մϴ�. ���ӿ��� �̰���ϴ�.\n");
	//			}
	//		}
	//		else
	//		{
	//			printf("�����մϴ�. ���ӿ��� �̰���ϴ�.\n");
	//		}
	//	}
	//	else
	//	{
	//		printf("�����մϴ�. ���ӿ��� �̰���ϴ�.\n");
	//	}
	//}
	//else
	//{
	//	printf("�����մϴ�. ���ӿ��� �̰���ϴ�.\n");
	//}

	// for���� �̿��� ������ ���� ���߱� ����

	//int counter = 0;
	//int life = 5;
	
	//for (; ;)
	//{
	//	life--;
	//
	//	if (computerValue != userValue)
	//	{
	//		printf("\nƲ�Ƚ��ϴ�. %d�� ���ҽ��ϴ�.\n�ٽ� �Է��ϼ��� :", life);
	//		scanf_s("%d", &userValue);
	//		printf("��ǻ���� ������ �� : %d\n", computerValue);
	//		printf("�÷��̾��� �Է� �� : %d\n", userValue);
	//
	//		if (life == 1) 
	//		{
	//			printf("��ȸ�� ��� ����߽��ϴ�. ���ӿ��� �й��߽��ϴ�\n");
	//			break;
	//		}
	//
	//		if (computerValue > userValue)
	//		{
	//			printf("��ǻ���� ������ �� : %d�� �÷��̾��� �Է� �� : %d���� Ů�ϴ�\n", computerValue, userValue);
	//		}
	//		else
	//		{
	//			printf("��ǻ���� ������ �� : %d�� �÷��̾��� �Է� �� : %d���� �۽��ϴ�\n", computerValue, userValue);
	//		}
	//	}
	//	else
	//	{
	//		printf("�����մϴ�. ���ӿ��� �̰���ϴ�.\n");
	//		break;
	//	}
	//}
	//printf("��ȸ�� ��� ����߽��ϴ�. ���ӿ��� �й��߽��ϴ�\n");

	 //while���� �̿��� ������ ���� ���߱� ����

	//int countNum = 5;
	//while (countNum > 1)
	//{
	//	countNum--;
	//	if (computerValue != userValue)
	//	{
	//		printf("Ʋ�Ƚ��ϴ�. %d�� ���ҽ��ϴ�. �ٽ� �Է��ϼ��� :", countNum);
	//		scanf_s("%d", &userValue);
	//		printf("��ǻ���� ������ �� : %d\n", computerValue);
	//		printf("�÷��̾��� �Է� �� : %d\n", userValue);
	//		
	//		if (computerValue > userValue)
	//		{
	//			printf("��ǻ���� ������ �� : %d�� �÷��̾��� �Է� �� : %d���� Ů�ϴ�\n", computerValue, userValue);
	//		}
	//		else
	//		{
	//			printf("��ǻ���� ������ �� : %d�� �÷��̾��� �Է� �� : %d���� �۽��ϴ�\n", computerValue, userValue);
	//		}
	//
	//	}
	//	else
	//	{
	//		printf("�����մϴ�. ���ӿ��� �̰���ϴ�.\n");
	//		break;
	//	}
	//}
	//printf("Ʋ�Ƚ��ϴ�. ���ӿ��� �й��߽��ϴ�\n");
	return 0;
}