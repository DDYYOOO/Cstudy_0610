/*
	�н���ǥ : while �ݺ���
	while �ݺ������ε� �ݺ��� ǥ���� �� �ִ�
*/

/*
  while(���ǽ�)  // ���ǽ��� True�� ���� ��ü�� �����ϰ�, ���ǽ��� False�� ���� �ڵ带 ����
  {
	�ڵ峻�� ;  // ���� ��ü
	��ȭ��;
  }

  do ~ while

  do
  {
	�ݺ���ų �ڵ�;
  }while(���ǽ�);
*/
#include"lectures.h"

void lectures12_3()
{
	int i = 0;

	while (i < 10)  // 1�� 10���� ������ ��� �ݺ�
	{
		i = i + 2;  // ��ȭ��
		printf("Hello World\n");
	}

	//while (100)    // ���� ����
	//{
	//	printf("Hello World\n");
	//}

	int index;
	scanf_s("%d", &index);

	while (index != 3)  // while ���ǽĿ� �������� ���� �����ڸ� ����ϸ� ���� ������ ������ �����Ƿ� �����ؾ� ��
	{
		printf("Hello World\n");
		scanf_s("%d", &index);
	}

	// while�ݺ����� ���� - �� �� �ݺ����� �𸣴� �ڵ忡�� ����ϱ� ����

	// do ~ while
	// �� ���� �ݵ�� ����ϵ��� ������ �Ǿ� �ִ� �ڵ�
	int i_doNum = 1;
	do
	{
		printf("�ѹ��� �ݵ�� ����ϴ� do ~ while��.\n");
		i_doNum = i_doNum * 3;
	} while (i_doNum < 10);



}