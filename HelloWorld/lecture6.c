/*
* �ۼ��� : �̵���
* �ۼ��� : 2024-06-17
* �н� ��ǥ : �����
* 
* �����
*	������� �ؾ� �ϴ� ����
*	���α׷����� �ϸ鼭 �ۼ��� ������ ������ �ذ��ϱ� ���ؼ� 
*	������ �ǽɰ��� �κп� �ڵ��� �ߴ����� �����ϰ� ������ ��ǻ���� ������� ������ Ȯ���� �� �ִ�.
*	������ �ذ� �ϱ� ���� ����̴�(With Computer Debuging System)
* ����Ű
*	
*/

//operator ������
//����, ���, ������
// '=', -, + , *, /, %
//"=" : A = B ����. (�� ������ - ����) (���Կ�����);
//int num = 30;  Left Value = Right Value; ������ ���� ���� ������ �־��ִ� ���
//���� ������ (a <- b) �������ִ�.

// ���� ���� ����
// ���� : a = a + b; a += b;
//       a = a - b; a -= b;
//		 a = a * b; a *= b;
//		 a = a >> b; a >>= b;
//		 a = a & b; a &= b;
//		 a = a | b; a |= b;

/*
*	����, ���� ������
*	num++;		
*	++nume;
*	num--;
*	--num;
*	++ : ���� +=�� ���� ��.
*	-- : ���� -=�� ���� ��.
* 
*	���� ���� : ������ 1�� ���� �� ���� ��, ������ ������ �����Ѵ�.
*	���� ���� : ������ ������ ���� ���� �� ������ ���� ��ȭ ��Ų��.
* 
*/

/*
	���� ������
	�� ������. �� ���� ���� ���Ͽ� �� ���踦 ǥ���ϴ� ������.
	a, b;
	a = 10, b = 12
	��� ���� True(��), False(����)���� ���´�.
	True : 1, False : 0
	result = (a < b);
*/

/*�� ������ 
	AND, OR, XOR
	AND :  && -> A�� B�� ��� ���̸� ����� ���� ����� ��ȯ�Ѵ�. "1"
	OR  :  || ->  A�� B�� �ϳ��� ���̸� 1�� ����� ��ȯ�Ѵ�.
	XOR :  |���� -> A�� True�̸� False��ȯ, False�̸� True��ȯ�Ѵ�.
*/

//���� ���� ����
// int A = (a == 10 && b == 12);
// int B = (a < 12 || b > 12);
// int C = 
#include"lectures.h"

void lectures6()
{
	printf("����� ���� ����\n");
	char a, b, c;
	a = 100;
	b = 300;
	c = a + b;
	printf("%d + %d = %d\n", a, b, c);

	printf("������ ��������\n");

	//9 + 2 = 11, 9 - 2 = 7;

	int num1, num2, num3, result;
	result = 0;
	scanf_s(" %d %d %d", &num1, &num2, &num3);
	printf("��� ���(L-Value) = %d * %d + %d = %d\n", num1, num2, num3, num1 * num2 + num3);
	printf("���� ���� ������(��� %d += %d)\n", result, num1);

	print("����, ���� ������ ���� ����\n");
	int PlueA = 10;
	int PlusB = (PlueA++) + 2;
	printf("PlusB�� ���� �󸶰� ���ñ��? : %d\n", PlusB);
	printf("PlusA�� ���� �󸶰� ���ñ��? : %d\n", PlueA);

	printf("��� �� = (%d)\n", num1 < num3);


	// ����
	// ���� A�� ���� 3 + 4 * 5 �̸�, ���� B�� ���� 7 / 3 % 2 �̴�.
	//���� A�� B�� ���� ���� ���� Result ������ �����Ͽ� ����Ͽ� ������.

	printf("������ �켱 ���� ������ ����\n");

	int variableA;  // 3 + 4 * 5;
	int variableB;	// 7 /3 % 2;
	int Final;		// variableA�� variableB�� ���迬���ڸ� ����Ͽ� Final �����ϼ���.

	int cal1, cal2, cal3;
	scanf_s("%d %d %d\n", &cal1, &cal2, &cal3);
	variableA = cal1 + cal2 * cal3;
	printf("variableA�� ���� : %d", variableA);
	variableB = 7 / 3 % 2;
	Final = (variableA < variableB);
	printf("%d�� %d�� ���� ������ ���� : %d", variableA, variableB, Final);
}