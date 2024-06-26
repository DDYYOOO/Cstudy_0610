/*
  �ۼ��� : �̵���
  �ۼ��� : 2024-06-25
  �н� ��ǥ : �ݺ����� ���ؿ� �ǽ�
*/

/*
  �ݺ����� ��� �ϴ� ����
  ���ʿ��� �ݺ����� �ڵ带 �����ϰ� ǥ���� �� �ִ�.
*/

// ���� : for�ݺ���, while�ݺ���

/*
  for(�ʱ��; ���ǽ�; ��ȭ��) // loop statement(���� ����)
  {
	�ڵ� ����;				// loop body(���� ����)
  }

  �ʱ�� : int i = 0; �ݺ����� ������ �� �ʿ��� ������ ���� �� �Ҵ��� �̷������ ���� ';'
  ���ǽ� : i < 10	 ���ǽ��� ���̸� ���� ��ü�� �ڵ带 ������ �� ��ȭ���� �����Ѵ�     
  ��ȭ�� : i++		 �ʱ���� �������� ��ȭ���Ѽ� ������ Ż���� �� �ֵ��� �ϴ� ��

*/


#include"lectures.h"

void lectures12()
{
	// 1. for �ݺ���
	// for �ݺ��� ����

	// i++ = i + 1; (���� ������ ���� �ʰ� ó��)
	// ++i = i + 1; (���� ������ ���� ���� ó��)

	// c = a + b++; -> c�� ���� 1�� ������ ��
	// c = a + ++b; -> c�� ���� 1�� ������ ��

	// Hello World 10�� ���
	for (int i = 0; i < 10; i++)
	{
		printf("Hello World\n");
	}

	// �ʱ��, ��ȭ���� ��ȭ�� �ش�
	int index;

	for (index = 10; index > 0; index--)
	{
		printf("Index print! %d\n", index);
	}

	for (int i_num = 0; i_num < 10; i_num += 2)
	{
		printf("i_num Printf! %d\n", i_num);
	}

	// for(~; ~; ~); // ���� �ڿ� ; ���̸� �Ʒ��� ���� �ٵ�� ������ �۵�
	
	for (; ;)  // �ش� �ݺ����� ǥ���� �ڵ� ���� �ݺ����� ������ �ܼ�â���� Ctrl + c�� ������ �ȴ�
	{
		printf("Hi\n");
	}
}

void lectures12_2()
{
	// scanf ��� �ݺ����� �����ֱ�
	int i_scanfNum;
	printf("��� �ݺ����� ���� �� ���� ���ڸ� �Է� �ϼ��� :");
	scanf_s("%d", &i_scanfNum);
	// for���� printf����ؼ� i_scanfNum�� ���� ���� "�ݺ��� �ǽ�", i_scanfNum�� ���� : \n

	// i_scanfNum�� ���� ���� "�ݺ��� �ǽ�", i_scanfNum�� ���� : \n
	// ������ ������ ���. printf�Լ��� ����ؼ�, �տ� "�ݺ��� �ǽ� i_scanfNum�� ���� :"

	for (int i = 0; i < i_scanfNum; i++)
	{
		printf("�ݺ��� �ǽ� i_scanfNum�� ���� : %d\n", i_scanfNum);
	}

	// for �ݺ����� �ݺ� Ƚ���� �������ִ� �ڵ带 �ۼ��� �� ����

	// for ���� 2
	printf("�ݺ��� ���� ����2\n");

	// 1�̻� 100�̸��� ������ �߿��� 7�� ����� 9�� ����� ����ϴ� ���α׷��� �ۼ�
	// ����� ���ڰ� �� ���� ��µǵ��� �ڵ带 �ۼ�

	for (int i = 1; i < 100; i++)
	{
		// 7�� ����� 9�� ��� �϶��� ���
		if(i % 7 == 0 || i % 9 == 0) // 7�� ����� 9�� ����� 7�� 9�� ���� ������ ���� ǥ��
			printf("%d\n", i);
	}
 
	// for ���� 1�� ������ while������ �ٲپ ����
	// ������ ���� ���� or �ٸ� ���� ���� OK
	printf("�ݺ��� ���� ����3\n");

	int w_num;
	scanf_s("%d", &w_num);
	while (w_num > 0)
	{
		printf("%d\n", w_num);
		w_num--;
	}
}