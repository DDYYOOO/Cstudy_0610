#include"lectures.h"

//int   : ������(����), 
//float : ������(�Ǽ�),

//������
//������ ���� �ۼ�(int, float) ���� �̸�(a)
//���� : int a;

//�Ҵ�(assignMent)
//������ ������ �����͸� �ִ� ��
//a�̸��� ������ ���� ������ �����͸� ���� �� �ְ� �ȴ�.
//int a = 10;

//�ʱ�ȭ(Initialize)
//������ ó������ �����͸� �Ҵ��ϴ� ��


void lectures3()
{
	printf("Hello World! �̰���3���� �����Դϴ�.\n");
	int a = 5 + 3; //int a �Լ� �� 8

	a = 4 + 7; // int a �Լ����� ����8������ 4+7�� ���� 11�� ����
	printf("%d \n", a);

	float b = 3.2f + 4.7f;
	printf("%f\n", b);

	//���� 1
	//������ �̸� width, height, length ������ ���� �� �ִ� ���� ����

	int width = 12;
	int height = 10;
	int length = 8;

	//���� 2
	//�� ���� ���� ��(����) Volume ������ �����ϼ���

	int Volume = width * height * length;

	//���� 3
	// volume / 165�� ������ ���ϴ� ��� ���� ���� �� printf�Լ��� ����ϼ���.

	//Volume = Volume / 165;
	Volume = (Volume + 164) / 165; //�ݿø�
	printf("���� 3�� ������ ���� %d\n", Volume);

	//int Volume2 = Volume / 165;
	//printf("���� 3�� ������ ���� %d\n", Volume2);

	float Volume_f = width * height * length;
	Volume_f = Volume_f / 165.0f;
	printf("���� 3�� �Ǽ��� ���� %f\n", Volume_f);

	//float Volume3 = Volume / 165.0f;
	//printf("���� 3�� �Ǽ��� ���� %f", Volume3);

	//���� 2-1 ����, ȭ��
	//ȭ�� = 9/5 * ���� + 32
	//ȭ���� �Ǽ��� ǥ���� �� �ֵ��� ������ �������ּ���.
	//9/5�� ���� 1�� �ƴ� 1.8�� ���;� �մϴ�.
	//���� 1, ȭ�� 33.8

	float Celsius = 1.5f;    //����
	float Fahrenheit = 9.0f / 5.0f * Celsius + 32;  //ȭ��

	printf("���� to ȭ�� : %.2f\n", Fahrenheit); //%.2f : �Ҽ��� 2�ڸ����� ���
}

