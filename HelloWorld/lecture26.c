/*
	작성자 : 이동윤
	작성일 : 2024-07-31
	학습 목표 : 파일 입출력
*/

// printf : 모니터에 출력
// scanf  : 키보드로부터 입력받은 값을 주소를 전달해서 주소에 저장
// fopen  : 파일을 열거나 쓰기 위해서 운영체제가 지원해주는 함수
// 윈도우, 리눅스, 맥... : 키보드, 마우스, 모니터등 하드웨어가 컴퓨터에서 작동하도록 관리해준다
// 스트림 : 서로 다른 하드웨어를 연결해주는 것(모니터 <- 키보드, 모니터 <- 마우스)

// 변수를 저장 -> RAM : 휘발성 메모리 : 컴퓨터 또는 프로그램이 종료되면 사라지는 메모리
// 비휘발성 메모리 : 프로그램이 종료되거나 컴퓨터가 종료되도 저장되는 메모리(HDD, SSD)
// 운영체제도 다르고 종류도 다 다른 데이터를 저장하려면, 파일 스트림 연결시켜줘야 한다
// 구조체 File

// 파일이 저장되는 위치
// 

#include"lectures.h"

#define filename "test\\people.txt"
#define filename2 "test\\CProgram.txt"

typedef struct Person
{
	char name[30];
	int age;
}Person;


void WriteFile()
{
	// fopen : 스트림
	FILE* fp = fopen(filename, "w"); // a.txt파일과 운영체제와 파일 스트림과 연결

	// fopen 스트림을 연결해주는 함수가 정상적으로 실행되지않을 때 보안
	if (fp == NULL)
	{
		printf("Write Error!\n");
		return 0;
	}

	fputs("Hello World!\n", fp); // fputs(입력하고 싶은 값, 스트림 인자);

	// FILE* 파일 스트림을 저장하는 구조체, stdout : 모니터에 연결해주는 스트림
	fputs("Hello World!\n", stdout);

	// 메모리에 저장된 데이터 해제?
	fclose(fp);
}

void ReadFile()
{
	FILE* fp = fopen(filename, "r");

	if (fp == NULL)
	{
		printf("Read Error!\n");
		return 0;
	}

	// string, char
	// fgets : 문자열로 읽어오는 함수
	// fgetc : 문자 한개씩 읽어오는 함수

	char buffer[100];	// 버퍼 : 데이터를 임시적으로 보관했다가 필요할 때 꺼내서 쓰는 용도

	fgets(buffer, 100, fp);
	printf("%s\n", buffer);
	fclose(fp);
}

void WriteFileByFile()
{
	Person people[3] = {
		{"이순신", 31},
		{"강감찬", 32},
		{"장보고", 33}
	};

	for (int i = 0; i < 3; i++)
	{
		printf("이름 : %s, 나이 : %d\n", people[i].name, people[i].age);
	}

	FILE* fp = fopen(filename, "w");

	if (fp == NULL)
	{
		printf("Write Error!\n");
		return 0;
	}

	//fprintf(fp, "%s", people[0].name);

	for (int i = 0; i < 3; i++)
	{
		fprintf(fp, "이름 : %s, 나이 : %d\n", people[i].name, people[i].age);
	}
	fclose(fp);
}

void lectures26()
{
	WriteFile();		// 파일을 써서 저장하는 함수
	ReadFile();		// 파일을 불러오는 함수
	// test폴더 안에, Cprogram 이름으로 내용은 Today is 2024-07-31 텍스트가 출력되도록 파일을 하난 생성
	// 생성된 파일을 읽어와서 콘솔창에 출력

	WriteFileByFile();

	FILE* fp = fopen(filename, "r");

	if (fp == NULL)
	{
		printf("Read Error!\n");
		return 0;
	}

	Person people[3];

	for (int i = 0; i < 3; i++)
	{
		fscanf_s(fp, "이름 : %s, 나이 : %d", people[i].name, 30, &people[i].age);
		printf("이름 : %s, 나이 : %d\n", people[i].name, people[i].age);
	}

	fclose(fp);

	FILE* fp2 = fopen(filename2, "w");
	
	if (fp2 == NULL)
	{
		printf("Write Error!\n");
		return 0;
	}
	
	fputs("Today is 2024-07-31", fp2);
	fclose(fp2);
	
	FILE* fp3 = fopen(filename2, "r");
	
	if (fp3 == NULL)
	{
		printf("Read Error!\n");
		return 0;
	}
	
	char buffer2[100];
	
	fgets(buffer2, 100, fp3);
	printf("%s\n", buffer2);
	fclose(fp3);
}