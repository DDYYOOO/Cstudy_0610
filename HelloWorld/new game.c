#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main1()
{
    char targetWord[] = "apple"; // ������ �ܾ�
    char guess[20]; // ������� ������ ������ �迭
    int attempt = 0; // �õ� Ƚ��

    printf("�ܾ� ������ ������ �����մϴ�!\n");
    printf("�ܾ��� ���̸� ���纸����.\n");

    while (1) {
        printf("\n�ܾ �����غ�����: ");
        scanf("%s", guess);
        attempt++;

        if (strcmp(guess, targetWord) == 0) {
            printf("\n�����մϴ�! �����Դϴ�.\n");
            printf("�õ� Ƚ��: %d\n", attempt);
            break;
        }
        else {
            printf("Ʋ�Ƚ��ϴ�. �ٽ� �õ��غ�����.\n");
        }
    }

    return 0;
}