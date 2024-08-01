#pragma once
// ~~~.h : 함수의 원형을 선언
// 1. (데이터 타입) - void, 2. (반환값 데이터형) - int, char, int*, char*.... , struct people
// int함수 이름() : 

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

