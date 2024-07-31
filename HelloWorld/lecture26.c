/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-07-31
	�н� ��ǥ : ���� �����
*/

// printf : ����Ϳ� ���
// scanf  : Ű����κ��� �Է¹��� ���� �ּҸ� �����ؼ� �ּҿ� ����
// fopen  : ������ ���ų� ���� ���ؼ� �ü���� �������ִ� �Լ�
// ������, ������, ��... : Ű����, ���콺, ����͵� �ϵ��� ��ǻ�Ϳ��� �۵��ϵ��� �������ش�
// ��Ʈ�� : ���� �ٸ� �ϵ��� �������ִ� ��(����� <- Ű����, ����� <- ���콺)

// ������ ���� -> RAM : �ֹ߼� �޸� : ��ǻ�� �Ǵ� ���α׷��� ����Ǹ� ������� �޸�
// ���ֹ߼� �޸� : ���α׷��� ����ǰų� ��ǻ�Ͱ� ����ǵ� ����Ǵ� �޸�(HDD, SSD)
// �ü���� �ٸ��� ������ �� �ٸ� �����͸� �����Ϸ���, ���� ��Ʈ�� ���������� �Ѵ�
// ����ü File

// ������ ����Ǵ� ��ġ
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
	// fopen : ��Ʈ��
	FILE* fp = fopen(filename, "w"); // a.txt���ϰ� �ü���� ���� ��Ʈ���� ����

	// fopen ��Ʈ���� �������ִ� �Լ��� ���������� ����������� �� ����
	if (fp == NULL)
	{
		printf("Write Error!\n");
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
		printf("Read Error!\n");
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
		printf("Write Error!\n");
		return 0;
	}

	//fprintf(fp, "%s", people[0].name);

	for (int i = 0; i < 3; i++)
	{
		fprintf(fp, "�̸� : %s, ���� : %d\n", people[i].name, people[i].age);
	}
	fclose(fp);
}

void lectures26()
{
	WriteFile();		// ������ �Ἥ �����ϴ� �Լ�
	ReadFile();		// ������ �ҷ����� �Լ�
	// test���� �ȿ�, Cprogram �̸����� ������ Today is 2024-07-31 �ؽ�Ʈ�� ��µǵ��� ������ �ϳ� ����
	// ������ ������ �о�ͼ� �ܼ�â�� ���

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
		fscanf_s(fp, "�̸� : %s, ���� : %d", people[i].name, 30, &people[i].age);
		printf("�̸� : %s, ���� : %d\n", people[i].name, people[i].age);
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