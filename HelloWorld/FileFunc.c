#include<stdio.h>
#include"FileFunc.h"


void WriteFile()
{
	// fopen : 스트림
	FILE* fp = fopen(filename, "w"); // a.txt파일과 운영체제와 파일 스트림과 연결

	// fopen 스트림을 연결해주는 함수가 정상적으로 실행되지않을 때 보안
	if (fp == NULL)
	{
		perror("Write Error!\n");
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
		perror("Read Error!\n");
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
		perror("Write Error!\n");
		return 0;
	}

	//fprintf(fp, "%s", people[0].name);

	for (int i = 0; i < 3; i++)
	{
		fprintf(fp, "이름 : %s, 나이 : %d\n", people[i].name, people[i].age);
	}
	fclose(fp);
}

void ReadFileByFile()
{
	FILE* fp = fopen(filename, "r");

	if (fp == NULL)
	{
		perror("Read Error!\n");
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
		perror("Write Error!\n");
		return 0;
	}

	fputs("Today is 2024-07-31", fp2);
	fclose(fp2);

	FILE* fp3 = fopen(filename2, "r");

	if (fp3 == NULL)
	{
		perror("Read Error!\n");
		return 0;
	}

	char buffer[100];

	fgets(buffer, sizeof(buffer), fp3);
	printf("%s\n", buffer);
	fclose(fp3);
}

void WritePlus()
{
	FILE* fp = fopen(filename3, "w+");

	if (fp == NULL)
	{
		perror("WritePlus Error!\n");
		//ferror(fp);
		//return 0;
	}

	// 파일 입력
	fputs("Hello World!\n", fp);

	// 파일을 읽어와서 파일의 끝 '\0'(nullPtr)   End of File : 각각의 운영체제가 표현하는 값이 다르다
	fseek(fp, 0, SEEK_SET);

	// 파일 출력
	char buffer[100];

	fgets(buffer, sizeof(buffer), fp);
	printf("Write form this file : %s", buffer);
	fclose(fp);
}

void FileIndicator()
{
	FILE* fp = fopen(filename3, "r");

	if (fp == NULL)
	{
		perror("FileIndicator Error!\n");
		//ferror(fp);
		//return 0;
	}

	fgetc(fp);	// File에서 fp의 주소가 가리키고 있는 char를 가져온 후, fp는 다음 주소를 가리킨다.
	fgetc(fp);
	fgetc(fp);
	fgetc(fp);
	fgetc(fp);
	fgetc(fp);
	//fseek(fp, 0, SEEK_SET);
	//printf("현재 가리키고 있는 인덱스 값 : %d\n", SEEK_CUR);
	printf("현재 포인터가 가리키고있는 문자 : %c\n", fgetc(fp));
	fclose(fp);
}

void ReadPlus()
{
	FILE* fp = fopen(filename3, "r+");

	if (fp == NULL)
	{
		perror("ReadPlus Error!\n");
	}

	char buffer[100];

	fgets(buffer, sizeof(buffer), fp);
	printf("Read form this File : %s", buffer);

	fseek(fp, 0, SEEK_END);
	fputs("Append.text\n", fp);
	fclose(fp);
}