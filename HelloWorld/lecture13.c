/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-06-26
	�н� ��ǥ : break, continue
*/

/*
  for�ݺ���, while�ݺ���
  �ݺ����� ������ �����ϰ� ǥ��
  break, continue  (�ݺ���, ���ǹ� - ���) �������ִ� ���
  for, while, do ~ while, switch ���
*/

/*
  break : �����帧���� ����� ���� ���. break ����Ǹ� �ش� ������� ���� ����
  continue : �����帧�� ������ ���·� �ش� �ڵ��� ���ุ �ǳ� �ٴ� ����� ��
*/


#include"lectures.h"

void lectures13()
{
	// printf 10�� �ݺ��ϴ� for�ݺ���
	// 0 ~ Ư�� ���ڱ��� �ݺ��ؼ� �Ʒ��� �ڵ带 �����ϴµ�, ���� ���ϴ� �������� �����ϸ� 
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("Hi%d\n", i);
	//
	//	if (i == 7)
	//	{
	//		printf("i�� 7�϶� ��µ�\n");
	//		break;
	//	}
	//}
	//
	//int index = 0;
	//for (; ;)
	//{
	//	index++;
	//	printf("hi\n");
	//	if (index == 7)
	//	{
	//		printf("7�� ��µǾ����ϴ�\n");
	//		break;
	//	}
	//}

	// for�ݺ���
	//int targetNumber; // ����ϰ��� �ϴ� ��ǥ ����
	//scanf_s("%d", &targetNumber);

	//int counter = 0;  // �ݺ������� targetNumber�� ã�� ���� ����
	//for (; ;)
	//{
	//	counter++;
	//	printf("idid\n");
	//	if (targetNumber == counter)
	//	{
	//		printf("���ϴ� ������� ��µǾ����ϴ�. %d\n ", targetNumber);
	//		break;
	//	}
	//}

	// while�ݺ���
	//int w_counter = 0;
	//while (1)
	//{
	//	w_counter++;
	//	printf("IDID %d\n", w_counter);
	//	if (targetNumber == w_counter)
	//	{
	//		printf("���ϴ� ������� ��µǾ����ϴ� %d\n", targetNumber);
	//		break;
	//	}
	//}

	// continue ��� ����
	//int w_num = 0;
	//while (w_num < 10)
	//{
	//	w_num++;
	//	if (w_num % 2 == 0) // 2�� �������� �������� 0 (¦��), �ƴ� ���ڵ��� Ȧ��
	//	{
	//		printf("�ǳ� �� w_num�� �� : %d\n", w_num);
	//		continue;
	//	}
	//	printf("w_num�� �� : %d\n", w_num);
	//}

	// �ֻ������� 12�� ���� �ִ� scanf�Լ��� �ֻ����� ���� ����
	// ���� �ֻ����� ¦���� ���´ٸ� ���� ���� �ִ� ���� �������� 2��, Ȧ���� ���� �ִ� ���� �������� 0���� �Ǵ� �ڵ� �ۼ�
	// ���� �������� 0�̸� ���α׷��� ����
	printf("�ֻ��� ���� ����\n");

	// 0 ~ 12 ���ڸ� scanf_s���
	printf("�������� ���� Ÿ¥���� �ֻ����� ���ڸ� ����ּ���(0 ~ 12) :");
	int diceNum, gameMoney;
	// ���� �ڵ��� ������ 12���� ū ����, 0���� ���� ���ڸ� �Է��ϸ� �� ���ڰ� diceNum�� ��� <- �̰��� �����ϴ� �ڵ�
	scanf_s("%d\n", &diceNum);
	gameMoney = 1000;  // �⺻ ������

	while (1)
	{
		if (diceNum < 1 || diceNum > 12) // 
		{
			printf("���� �߸��� �ֻ��� ũ�⸦ �Է��߽��ϴ�. \n �ֻ����� �ٽ� �Է����ּ��� : \n");
			scanf_s("%d\n", &diceNum);
		}
		else // ���� ���� �۵� ����
		{
			// ¦������ Ȧ������ �Ǻ��ϴ� �ڵ� �ۼ�
			if (diceNum % 2 == 0)  // ¦��
			{
				gameMoney = gameMoney * 2;

				if (gameMoney > 5000)
				{
					printf("���ӿ��� �¸��߽��ϴ�. ���� �ݾ� : %d", gameMoney);
					scanf_s("%d\n", &diceNum);
				}
				else
				{
					printf("���� �������� �ݾ� : %d\n", gameMoney);
				}
			}
			else // Ȧ��
			{
				gameMoney = 0;
				printf("���ӿ��� �����ϴ� ���� �ݾ��� : %d", gameMoney);
				break;
			}

		}

	}


}