#include<stdio.h>

/*
	4��. �̽������� ����
	�ۼ���   : �̵���
	�ۼ���   : 2024-06-13
	�н���ǥ : �̽������� ���� ���

	�Է�
	scanf �Լ��� �ǽ�
	���� �̸� ����(�Է��� �޾Ƽ� ������ ������ �̸� ����)
	�⺻ ���� : scanf("%d", &������ �̸�);
	scanf_S("%d", &num);

*/

void lectures4()
{
	printf("Hello World! �̰���4���� �����Դϴ�.\n");
	int num = 500;
	printf("���� ������ �ݾ� : 450�� \n");
	printf("\"���� ������ �ݾ� : %d��\" \n", num);

	// ��ӵ� ��Ģ���� ���� ����� �� �� ���� ���ڵ��� �ִ�.
	// �̷��� ���ڵ��� ����ϰ� ���� �� �̽������� : "\"
	// \ + (��ӵ� ����) : ���ο� ����� ������ �� �ִ�.
	// ���� : \n , \a ,  \t, \b, \r , \\, \? , \", \'

	/*
	   \n :	�� ���� ����ش�. ����. new line
	   \a :	alarm. ������ ������� ����Ѵ�.
	   \t :	tab ���� ���ڻ����� ������ ����(tab) ���.
	   \b : backSpace, �ܼ� Ŀ���� �� ĭ �ڷ� �̵���Ų��.
	   \r :	ĳ���� ����(return), ���콺 Ŀ���� �ش� ���� �� ó������ �̵���Ų��.
	   \\, \?, \", \' :	�ý��� ��� �� �⺻�� ����� �� ���� ���ڸ� ����ϰ� ���ش�.
	*/

	printf("���� ������ �ݾ� : %d�� \n", num);
	printf("\a");
	printf("hello\b\bhi\n");
	printf("�ǳ��ϼ���\r�ȳ�\n");
	printf("�ݰ�\t���ϴ�. \n");
	printf("\\ \' \" \? ������ �߻� �ϳ���? \n");

	// ������ �̿��� �������� ����.
	// ������ �����ϴ� �پ��� ���
	// (1) ������ ����, ���� �Ҵ�
	int num1;
	num1 = 10;
	// (2) ���� �ʱ�ȭ. (����� �Ҵ�)
	int num2 = 20;
	// (3) ������ ���ÿ� ����, �� ������ ���� ���� �͸�!
	int num3, num4, num5;
	num3 = 10, num4 = 20, num5 = 30;
	printf("%d %d %d", num3, num4, num5);
	// (4) ������ ���ÿ� ����� �Բ� �Ҵ�;

	// ���� �̸� �ۼ� �� ���� ����(���� ����)

	// ������ ù ���ڿ� ���ڰ� ���� �ȵȴ�.
	//int 776num;
	// #,$ Ư�� ��ȣ�� �̸��� ����� �� ����.
	//int #num;
	// ���� �̸� ���̿� ����(���� ����)�� �� �� ����.
	//int your function;
	// Ű���嵵 �̸����� ����� �� ����.
	// auto, enum, break, return, void, float, short, while
	//int union;

	// ������ �̸��� �� ���� ���� ������ �ؾ��մϴ�.

	//int abc = 10;
	int playerHP = 100;

	int Num;
	//scanf_s�Լ� ���
	//�������� �Է��Ѽ��ڸ� "Num�� �� ���� : n" ���·� ����ϴ� ���α׷����Դϴ�.
	//printf("���ڸ� �Է��ϼ��� : ");
	//scanf_s("%d", &Num);
	//printf("Num�� �� ���� : %d", Num);

	//���� 1. 2���� ������ �Է� �޾Ƽ� �� ���� �E���� ������ ����� ����ϼ���.
	//������ �̸� : FirstNum, FirstNum2, FirstNum3
	//int FirstNum, FirstNum2;
	//�� ���� �E�� : ���
	//�� ���� ���� : ���
	printf("����1\n");

	int FirstNum1, FirstNum2;

	printf("ù��° ������ �Է����ּ��� : ");
	scanf_s("%d", &FirstNum1);
	printf("�ι�° ������ �Է����ּ��� : ");
	scanf_s("%d", &FirstNum2);
	printf("�� ���� �E�� : %d\n", FirstNum1 - FirstNum2);
	printf("�� ���� ���� : %d\n", FirstNum1 * FirstNum2);

	//scanf_s("%d %d", &FirstNum1, &FirstNum2);
	//int minus = FirstNum1 - FirstNum2;
	//int multi = FirstNum1 * FirstNum2;
	//printf("�� ���� �E�� : %d\n", minus);
	//printf("�� ���� ���� : %d\n", multi);


	//����2. 3���� ������ �Է� �޾Ƽ�, SecondNum + SecondNum2 + SecondNum3�� ����ϴ� �ڵ带 �ۼ��ϼ���.

	printf("����2\n");

	int SecondNum1, SecondNum2, SecondNum3;

	printf("ù��° ������ �Է����ּ��� : ");
	scanf_s("%d", &SecondNum1);
	printf("�ι�° ������ �Է����ּ��� : ");
	scanf_s("%d", &SecondNum2);
	printf("����° ������ �Է����ּ��� : ");
	scanf_s("%d", &SecondNum3);
	printf("%d * %d * %d ���� : %d\n", SecondNum1, SecondNum2, SecondNum3, SecondNum1 * SecondNum2 * SecondNum3);

	//scanf_s("%d %d %d", &SecondNum1, &SecondNum2, &SecondNum3);
	//int sum = SecondNum1 + SecondNum2 + SecondNum3;
	//printf("�� ���� ���� ���� : %d \n", sum);

	//����3. �� ���� ������ �Է¹޾Ƽ� ��� �������� ����ϴ� �ڵ带 �ۼ��غ�����.
	//���� ���ϴ� ��� : a/b(���� ������ ���� �κ��� ��)
	//a%b = a�� b�� ���� ������ ��

	//���� 4. �ϳ��� ������ �޾Ƽ� ������ ����ϴ� �ڵ� �ۼ�

	printf("����4\n");

	int fourthNum;

	printf("������ �Է����ּ��� : ");
	scanf_s("%d", &fourthNum);
	printf("%d�� �������� : %d\n", fourthNum, fourthNum * fourthNum);
	//���� 5. �� ���� ������ �Է��� �޾Ƽ�, {fifthNum1 - fifthNum2} * {fifthNum2 + fifthNum3} * {fifthNum2 * fifthNum1}�� ����� �ڵ�� �ۼ��غ�����

	printf("����5\n");

	int fifthNum1, fifthNum2, fifthNum3;

	printf("ù��° ������ �Է����ּ��� : ");
	scanf_s("%d", &fifthNum1);
	printf("�ι�° ������ �Է����ּ��� : ");
	scanf_s("%d", &fifthNum2);
	printf("����° ������ �Է����ּ��� : ");
	scanf_s("%d", &fifthNum3);

	printf("{%d - %d} * {%d + %d} * {%d * %d}�� ���� : %d", fifthNum1, fifthNum2, fifthNum2, fifthNum3, fifthNum2, fifthNum1);


}