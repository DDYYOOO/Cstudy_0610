#pragma once
#include <stdio.h>
#include <string.h>

typedef struct Monster
{
	char name[30];
	char region[30];
	char grade[30];

}Monster;

int Compare(char* str1, char* str2);
void SearchMonsterName(Monster monster[100], int* totalmonsterCount);
void AddMosnterInfo(Monster monster[100], int* monsterIndexPtr);
void ShowAllMonster(Monster monster[100], int total);