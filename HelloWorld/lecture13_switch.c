/*
  switch���ǹ�

  switch(����)
  {
	case ������ �� :
	����Ǵ� �ڵ�
	break;

	case ������ �� :
	����Ǵ� �ڵ�
	break;

	case ������ �� :
	����Ǵ� �ڵ�
	break;

	...
	...
	...

	default :
	break;
  }

*/

/*
  ������ ������ ��, ó���ؾ��� ������ �پ��� �� ����ϴ� ���ǹ�
*/

#include"lectures.h"

void lectures13_switch()
{
	int num;
	scanf_s("%d", &num);

	//switch (num)
	//{
	//case 0:
	//	printf("0�Դϴ�\n");
	//	break;
	//case 1:
	//	printf("1�Դϴ�\n");
	//	break;
	//case 2:
	//	printf("2�Դϴ�\n");
	//	break;
	//default:
	//	printf("num�� 0 ~ 2�̿��� ���Դϴ�.\n");
	//	break;
	//}

	// ���� switch���� if else if�� �ٲ�
	//if (num == 0)
	//	printf("0�Դϴ�\n");
	//else if (num == 1)
	//	printf("0�Դϴ�\n");
	//else if (num == 2)
	//	printf("0�Դϴ�\n");
	//else
	//	printf("num�� 0 ~ 2�̿��� ���Դϴ�.\n");

	switch (num)
	{
	case 0:
	case 1:
		printf("0 ~1�� ���� ���� Ȯ�� : \n");
		break;
	case 2:
	case 3:
	case 4:
		printf("2, 3, 4�� ���� ���� Ȯ�� : \n");
	default:
		printf("num�� 0 ~ 2�̿��� ���Դϴ�.\n");
		//break;
	}

	// switch()  - ( )�ȿ� �� �� �ִ� ������ Ÿ���� �������� ����. �Ǽ��� ������ Ÿ���� ������ ������ ��

	//double d_num = 1.25;
	char c_num = 'A';
	switch (c_num)		// case�� �ݷ�(:) ���̿� ���� ���� ������ �ƴϰ�, ������ ������ ��ȯ�Ǵ� ���̿��� �������.
	{
	case 1<<2 :
		break;
	case 'A':
		break;
	case 2+3+4:
		break;
	}
}