#pragma once
// ~~~.h : �Լ��� ������ ����
// 1. (������ Ÿ��) - void, 2. (��ȯ�� ��������) - int, char, int*, char*.... , struct people
// int�Լ� �̸�() : 

#include<stdio.h>

#define filename "test\\people.txt"
#define filename2 "test\\CProgram.txt"
#define filename3 "test\\filemode.txt"


typedef struct Person
{
	char name[30];
	int age;
}Person;


void WriteFile();
void ReadFile();
void WriteFileByFile();
void ReadFileByFile();
void WritePlus();
void FileIndicator();
void ReadPlus();

