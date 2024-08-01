#include<stdio.h>
#include"FileFunc.h"


void WriteFile()
{
	// fopen : ��Ʈ��
	FILE* fp = fopen(filename, "w"); // a.txt���ϰ� �ü���� ���� ��Ʈ���� ����

	// fopen ��Ʈ���� �������ִ� �Լ��� ���������� ����������� �� ����
	if (fp == NULL)
	{
		perror("Write Error!\n");
		return 0;
	}

	fputs("Hello World!\n", fp); // fputs(�Է��ϰ� ���� ��, ��Ʈ�� ����);

	// FILE* ���� ��Ʈ���� �����ϴ� ����ü, stdout : ����Ϳ� �������ִ� ��Ʈ��
	fputs("Hello World!\n", stdout);

	// �޸𸮿� ����� ������ ����?
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
	// fgets : ���ڿ��� �о���� �Լ�
	// fgetc : ���� �Ѱ��� �о���� �Լ�

	char buffer[100];	// ���� : �����͸� �ӽ������� �����ߴٰ� �ʿ��� �� ������ ���� �뵵

	fgets(buffer, 100, fp);
	printf("%s\n", buffer);
	fclose(fp);
}

void WriteFileByFile()
{
	Person people[3] = {
		{"�̼���", 31},
		{"������", 32},
		{"�庸��", 33}
	};

	for (int i = 0; i < 3; i++)
	{
		printf("�̸� : %s, ���� : %d\n", people[i].name, people[i].age);
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
		fprintf(fp, "�̸� : %s, ���� : %d\n", people[i].name, people[i].age);
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
		fscanf_s(fp, "�̸� : %s, ���� : %d", people[i].name, 30, &people[i].age);
		printf("�̸� : %s, ���� : %d\n", people[i].name, people[i].age);
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

	// ���� �Է�
	fputs("Hello World!\n", fp);

	// ������ �о�ͼ� ������ �� '\0'(nullPtr)   End of File : ������ �ü���� ǥ���ϴ� ���� �ٸ���
	fseek(fp, 0, SEEK_SET);

	// ���� ���
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

	fgetc(fp);	// File���� fp�� �ּҰ� ����Ű�� �ִ� char�� ������ ��, fp�� ���� �ּҸ� ����Ų��.
	fgetc(fp);
	fgetc(fp);
	fgetc(fp);
	fgetc(fp);
	fgetc(fp);
	//fseek(fp, 0, SEEK_SET);
	//printf("���� ����Ű�� �ִ� �ε��� �� : %d\n", SEEK_CUR);
	printf("���� �����Ͱ� ����Ű���ִ� ���� : %c\n", fgetc(fp));
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