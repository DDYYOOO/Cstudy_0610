#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	// printf�Լ��� scanf�Լ��� �ÿ��ؼ� ������ ������ ����
	// �÷��̾ ȯ���ϴ� �ؽ�Ʈ�� ��� �١�
	// printf(���ڸ� �Է��ϸ� ������ �����մϴ�)
	// scanf -> �Է��� �޴´�  Ŀ���� ������·� ����ϰ� �ִ�

	//���� �Ǵ� �Ǽ� �����͸� ���� ��ǻ�Ͱ� �����ϴ� ����� ����ϰ�, ���� �����ϴ� ����� ���� ����ϴ� ���α׷��� ����� ������

	printf("�١ڰ��� ���ۡڡ�\n");

	srand(time(NULL));
	int computerValue = rand() % 100 + 1; // 1 ~ 100�� ������ ���ڰ� computerValue�� �Է��� �ȴ�.
	int userValue;
	int startValue;
	printf("�������. ���ڸ� �Է��ϸ� ������ ���۵˴ϴ� : ");
	scanf_s("%d", &startValue);
	
	printf("�÷��̾��� ���� �Է��ϼ��� : ");
	scanf_s("%d", &userValue);
	printf("��ǻ���� ������ �� : %d\n", computerValue);
	printf("�÷��̾��� �Է� �� : %d\n", userValue);

	if (computerValue == userValue)
		printf("�����մϴ�.\n");
	else
		printf("Ʋ�Ƚ��ϴ�.\n");

	return 0;
}