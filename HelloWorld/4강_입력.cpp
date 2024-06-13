//입력
//scanf 함수의 실습
//변수 미리 선언(입력을 받아서 저장할 변수를 미리 선언)
//기본 사용법 : scanf("%d", &변수의 이름);    
//scanf_S("%d", &num);
#include<stdio.h>

int main(void)
{
	int num;
	//scanf_s함수 사용
	//여러분이 입력한숫자를 "num의 들어간 숫자 : n" 형태로 출력하는 프로그래밍입니다.
	//printf("숫자를 입력하세요 : ");
	//scanf_s("%d", &num);
	//printf("num의 들어간 숫자 : %d", num);
	
	//문제 1. 2개의 정수를 입력 받아서 두 수의 뺼셈과 곱셈의 결과를 출력하세요.
	//변수의 이름 : FirstNum, FirstNum2, FirstNum3
	//int FirstNum, FirstNum2;
	//두 수의 뺼셈 : 결과
	//두 수의 곱셈 : 결과
	printf("문제1\n");

	int FirstNum1, FirstNum2;

	printf("첫번째 정수를 입력해주세요 : ");
	scanf_s("%d", &FirstNum1);
	printf("두번째 정수를 입력해주세요 : ");
	scanf_s("%d", &FirstNum2);
	printf("두 수의 뺼셈 : %d\n", FirstNum1 - FirstNum2);
	printf("두 수의 곱셈 : %d\n", FirstNum1 * FirstNum2);

	//scanf_s("%d %d", &FirstNum1, &FirstNum2);
	//int minus = FirstNum1 - FirstNum2;
	//int multi = FirstNum1 * FirstNum2;
	//printf("두 수의 뺼셈 : %d\n", minus);
	//printf("두 수의 곱셈 : %d\n", multi);
	

	//문제2. 3개의 정수를 입력 받아서, SecondNum + SecondNum2 + SecondNum3을 출력하는 코드를 작성하세요.

	printf("문제2\n");

	int SecondNum1, SecondNum2, SecondNum3;

	printf("첫번째 정수를 입력해주세요 : ");
	scanf_s("%d", &SecondNum1);
	printf("두번째 정수를 입력해주세요 : ");
	scanf_s("%d", &SecondNum2);
	printf("세번째 정수를 입력해주세요 : ");
	scanf_s("%d", &SecondNum3);
	printf("%d * %d * %d 값은 : %d", SecondNum1, SecondNum2, SecondNum3, SecondNum1 * SecondNum2 * SecondNum3);

	//scanf_s("%d %d %d", &SecondNum1, &SecondNum2, &SecondNum3);
	//int sum = SecondNum1 + SecondNum2 + SecondNum3;
	//printf("세 수의 더한 값은 : %d \n", sum);

	//문제3 , 두 개의 정수를 입력받아서 몫과 나머지를 출력하는 코드를 작성해보세요.
	//몫을 구하는 방식 : a/b(나눈 값에서 정수 부분이 몫)
	//a%b = a를 b로 나눈 나머지 값


	return 0;
}