/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-06-20
	�н� ��ǥ : C����� �⺻ �ڷ��� + ���
*/

// �ڷ����� �����ΰ�?
// ���� => (�ڷ���) (�����̸�)
// �ڷ����� ������ ����� ���ؼ� �ʿ��ѰŴ�.
// ���� ������ �ʿ䰡 �ִ�. <����, �Ǽ�>
// ������ ��� -> �󸶸�ŭ �����͸� ������ ���ΰ�?
// char �����̸� = 0b0000001;
// int �����̸� = 0b 00000000 00000000 00000000 00000001;
// long long �����̸� = 0b 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000001;
// �����Ͱ� ����� �޸��� ũ���� �����ϱ� ���� ����Ѵ�.
// � ������ Ÿ��(����, �Ǽ�)����� �� ������ �� �� �������� ũ�⸦ ������ Ű���带 data type(�ڷ���)�̶� �Ѵ�.
// "int" : 4����Ʈ ����, ������ ������ ������ ���� -> �����̸�.

/*
	�⺻ �ڷ����� ������ �������� ǥ������
	(1)������
	char	  : 1����Ʈ(8��Ʈ) 2e8(256)  -2e7 ~ 2e7 -1 ǥ���Ѵ�(-128 ~ 127 -> 256��)
	short	  : 2����Ʈ(16��Ʈ) -2e15 ~ 2e15 -1
	int		  : 4����Ʈ(32��Ʈ) -2e31 ~ 2e31 -1
	long	  : 4����Ʈ(32��Ʈ) ~ 8����Ʈ(64��Ʈ)
	long long : 8����Ʈ(64��Ʈ) -2e63 ~ 2e63 -1

	ANSI : American National Standards Institue(C����� ǥ���� ���ϴ� ��ȸ)
		   �����Ϸ��� ���������� �ּ� ũ�⸦ ���Ѷ�

	(2)�Ǽ���
	float	   : 4����Ʈ (��ȣ)(������)(������) -> �Ҽ��� 6�ڸ� ǥ��
	double	   : 8����Ʈ �Ҽ��� 15�ڸ� ǥ��
	long float : 8����Ʈ �Ҽ��� 18�ڸ� ǥ��
*/

/*
	1��ȣ(MSB) 0, 1 ����, ���...
	��ȣ�� �ʿ� ���� -> unsigned
	unsigned char ���� �̸� : 0 ~ 2e8�� ����. ��ȣ���� ���� ǥ����.
	unsigned int ���� �̸� : 0 ~ 2e32�� ����.
*/

/*
	sizeof ������ -> ���� (n)����Ʈ..
	int a = 10;
	int i_num = sizeof(int);    4
	int i_num = sizeof a;       sizeof() �Ѵٰ��ؼ� �Լ��� �ƴѴ�.
	int i_num = sizeof (a);     �Ϲ������� ()�� �Բ� ����Ѵ�.
*/

/*
	���
	������ �ʴ� ��
	���� - �ڷ���.

	���� : �̸��� ���� ���, �̸��� ���� �ʴ� ���
	���ͷ� ��� (literal) : ���� �״�� ������ �ʴ� ��.
	double my_double = 3.15;

	int my_int = 10;    int�� ���
	char my_char = 5;   int�� ���
	short my_short = 7; int�� ���
	int my_int = 30�ﺸ�� ū �� 2e31 -1 

	���ͷ����
	������ �⺻ �ڷ����� int
	int���� ū ���� �Է��� �Ǹ� �ڵ����� int ���� ū ���������� ����

	int ���� ����, char, short�� �� int�� �����Ϸ��� ������ �ɱ�>
	���� ���� ó���ϴ� ������ Ÿ�� int
	short -> char int���� �༮��� ������ �ؾ� �ϴ� ��찡 ���
	��ǻ�Ͱ� ó���� �� �ִ� ���� ���� ����(int) �����ؼ� ������ Ÿ���� �ٲپ� �ְ� �ִ�. (�����Ϸ�, ���)

	�Ǽ��� �⺻ �ڷ����� double
	double my_double = 3.15;
	float my_float = 3.15;

	my_long = 3.15l;
	UL       : unsigned long
	LL       : long long
	UL:      : unsigned long long
	
	F      : float
	L      : long float
*/

/*
	�̸� �ִ� ��� : �ɺ��� ���(const, define)
	�߷��� ũ�� : -9.8f
	����		   : 3.141592.....

	float gravity = -9.8f;  // �߷��� ũ��� ���ϸ� �ȵ�
	const gravity = -9.8f;   // const ����� ���ÿ� �ʱ�ȭ�� ����� �Ѵ�.
	const gravity = -9.0f;  // ������ ���ο� ���� ���� ������ ������ �߰� ��

	��ó���Ⱑ �������ϱ� ���� GRAVITY��� ������ -9.8�� ��ȯ��Ų��.
	#define GRAVITY = -9.8f

	����� �ۼ��� �� �̸� ��� ���
	�빮�ڷ� �ۼ��� ���ֵ�, �ܾ ��� ����� ��� '_'�� �ۼ�(GET_TIME_PRINCPLE)

*/

#include"lectures.h"

void lectures9()
{
	printf("9�� ����\n");

	printf("�ڡڱ⺻ �ڷ��� ���� �����ڡ�\n");

	// sizeof �����ڸ� ����ؼ� ���������� ����ϱ� 
	// char, short, int long, long long, float, double, long float

	printf("char ������ ũ�� : %d\n", sizeof(char));
	printf("short ������ ũ�� : %d\n", sizeof(short));
	printf("int ������ ũ�� : %d\n", sizeof(int));
	printf("long ������ ũ�� : %d\n", sizeof(long));
	printf("long long ������ ũ�� : %d\n", sizeof(long long));
	printf("float ������ ũ�� : %d\n", sizeof(float));
	printf("double ������ ũ�� : %d\n", sizeof(double));
	printf("float long ������ ũ�� : %d\n", sizeof(float long));

	char my_char;
	printf("char ������ ũ�� : %d\n", sizeof(my_char));
	short my_short;
	printf("short ������ ũ�� : %d\n", sizeof(my_short));
	int my_int;
	printf("int ������ ũ�� : %d\n", sizeof(my_int));
	long my_long;
	printf("long ������ ũ�� : %d\n", sizeof(my_long));
	long long my_longlong;
	printf("long long ������ ũ�� : %d\n", sizeof(my_longlong));
	float my_float;
	printf("float ������ ũ�� : %d\n", sizeof(my_float));
	double my_double;
	printf("double ������ ũ�� : %d\n", sizeof(my_double));
	long float my_longfloat;
	printf("long float ������ ũ�� : %d\n", sizeof(my_longfloat));

	//���� 2. ���ͷ� ����� sizeof�����ڷ� ���
	// �Ǽ�(3.15, 3.15f....), ����(10, 11, 12...)
	// sizeof(5); ����� ����ϴ� �Լ��� ǥ��


	// ����3 ���簢���� ���̸� ���ϴ� ���α׷��� �ۼ�
	// ����1 : ��ǥ�� �ΰ� �����޾ƾ��Ѵ� (xpos1, ypos1), (xpos2, ypos2)
	// ����2 : xpos2�� xpos1���� Ŀ���Ѵ�(���� ó��x)
	// xpos2 - xpos1 ���̷� �ϴ� ���簢���� ���ؾ� �Ѵ�
	// (4, 6) (6, 8) 2*2 = 4

}