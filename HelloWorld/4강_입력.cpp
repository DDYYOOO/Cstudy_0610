//�Է�
//scanf �Լ��� �ǽ�
//���� �̸� ����(�Է��� �޾Ƽ� ������ ������ �̸� ����)
//�⺻ ���� : scanf("%d", &������ �̸�);    
//scanf_S("%d", &num);
#include<stdio.h>

int main(void)
{
	int num;
	//scanf_s�Լ� ���
	//�������� �Է��Ѽ��ڸ� "num�� �� ���� : n" ���·� ����ϴ� ���α׷����Դϴ�.
	//printf("���ڸ� �Է��ϼ��� : ");
	//scanf_s("%d", &num);
	//printf("num�� �� ���� : %d", num);
	
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
	printf("%d * %d * %d ���� : %d", SecondNum1, SecondNum2, SecondNum3, SecondNum1 * SecondNum2 * SecondNum3);

	//scanf_s("%d %d %d", &SecondNum1, &SecondNum2, &SecondNum3);
	//int sum = SecondNum1 + SecondNum2 + SecondNum3;
	//printf("�� ���� ���� ���� : %d \n", sum);

	//����3 , �� ���� ������ �Է¹޾Ƽ� ��� �������� ����ϴ� �ڵ带 �ۼ��غ�����.
	//���� ���ϴ� ��� : a/b(���� ������ ���� �κ��� ��)
	//a%b = a�� b�� ���� ������ ��


	return 0;
}