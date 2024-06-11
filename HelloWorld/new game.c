#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main1()
{
    char targetWord[] = "apple"; // 추측할 단어
    char guess[20]; // 사용자의 추측을 저장할 배열
    int attempt = 0; // 시도 횟수

    printf("단어 맞히기 게임을 시작합니다!\n");
    printf("단어의 길이를 맞춰보세요.\n");

    while (1) {
        printf("\n단어를 추측해보세요: ");
        scanf("%s", guess);
        attempt++;

        if (strcmp(guess, targetWord) == 0) {
            printf("\n축하합니다! 정답입니다.\n");
            printf("시도 횟수: %d\n", attempt);
            break;
        }
        else {
            printf("틀렸습니다. 다시 시도해보세요.\n");
        }
    }

    return 0;
}