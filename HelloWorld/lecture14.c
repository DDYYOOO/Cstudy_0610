/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-06-27
	�н� ��ǥ : �Լ�
*/

// �Լ��� ����ϴ� ����
// C���� ����(Procedual)����(Orient) ���α׷��� ���
// ���� = �Լ� <- C���� �Լ��� �����ϴ� ���

// 1. main �Լ����� ���۵Ǵ� ���α׷��ֿ� �ڵ� ������ ��������� �ڵ带 �ľ��ϱ� �����, ��� ���� ������ ���������, �ݺ����� �ڵ尡 ��� �߻�
// �Լ��� �ÿ��ؼ� �ڵ带 �ľ��ϱ� ���� �����.
// ���� ������ ���� �����.
// �ݺ����� �ڵ带 ���δ�.

// �Լ��� ����
// ��ȯ���� �ִ��� ������
// �Ű������� �ִ��� ������

// (��ȯ�ϰ� ���� ������ ����)(�Լ� �̸�)( ) : �Լ��� ����
// {
//		�Լ��� ��ü;	
// }

// ����1. ��ȯ���� �ְ� �Ű������� �ִ� �Լ�
// �Ű����� �ۼ��� 
// ��ġ : ��ȯ�� �Լ��̸�(�Ű����� �ۼ��ϴ� ��)
// ������ ���� �Ű������� �̸��� �ۼ�
int AddTwoNumer(int a, int b)
{
	int result = a + b;
	// �Լ��� ��ǥ�� ���� ��ġ�� ��ȯ�ϴ� ������� : return ���
	printf("a�� ���� %d�̴�\n", a);
	return result;
}

// ���� 2. ��ȯ���� ���� �Ű������� ���� �Լ�
void ShowResult() 
{
	printf("����� ����ϰڽ��ϴ�.\n");
	printf("������ �����մϴ�.\n");
}

// ���� 3. ��ȯ���� ���� �Ű������� �ִ� �Լ�
void ChangeResult(int result)
{
	//printf("%d�� ����� ����Ǿ����ϴ�.\n", result);
	//return;
	printf("%d�� ����� ����Ǿ����ϴ�.\n", result);
}

// ���� 4. ��ȯ���� �ְ� �Ű������� ���� �Լ�
int InputNumber()
{
	int number;
	scanf_s("%d", &number);
	return number;
}

#include"lectures.h"

void lectures14() // �Լ��� ����
{
	// �Լ��� ȣ��
	// 5 + 7 ����� a��� ������ ������ �ִ� �ڵ带 �ۼ�
	//int a = 5 + 7;
	//a = AddTwoNumer(5, 7);
	//
	//ShowResult();

	// a������ �Ű������� ChangeResult�Լ��� ȣ��
	//ChangeResult(a);
	//ChangeResult(AddTwoNumer(5, 7));
	
	//int c = InputNumber();
	//printf("%d ���� ��µǾ����ϴ�\n", c);

	// �Ʒ��� �Լ��� ȣ��
	
	int FirstNum, SecondNum;
	
	FirstNum = InputNumber();
	SecondNum = InputNumber();
	int CompareValue = Compare(AbsoluteNum(FirstNum), AbsoluteNum(SecondNum));
	printf("�� ���� �������� ��ȯ�� �� �� ū �� : %d", CompareValue);
}

// �� ���� ���ؼ� ū ���� �����ϴ� �Լ��� �ۼ�
// �ΰ��� ������ �Ű������� �޴� �Լ�
// �̸� : Compare   ������ �����͸� ��, �Ǽ����� ����
int Compare(int a, int b)
{
	
	if (a < b)
	{
		printf("%d�� %d���� �۽��ϴ�.\n", a, b);
		return b;
	}
	else
	{
		printf("%d�� %d���� Ů�ϴ�.\n", a, b);
		return a;
	}
}
// ���� �ϳ��� �޾Ƽ� �� ���� �������� �������ִ� �Լ��� ������
// �̸� : AbsoluteNum
int AbsoluteNum(int num)
{
	if (num > 0)  // ����
	{
		return num * (-1);
	}
	else
	{
		return num;
	}
}

// �� ���� �������� ������ �� ���� ���ϴ� �Լ��� ������
