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

// 파일 입출력2
// 강화된 쓰기(Appendix) "w+"
// 기능 : 파일을 읽고 쓰기 위한 모드, 파일이 존재하지않으면 파일을 새로 생성하고, 파일이 존재하면 내용을 모두 지우고 다시 쓴다.

// fseek 함수 : 파일을 입출력할 때 파일의 크기만큼 file pointer 가리키는 값이 달라지게 된다
// fp를 이용해서 쓰기와 읽기를 동시에 한다면 처음에 쓰기를 fp 마지막 값을 가리키게 된다
// 처음부터 읽기 위해서 fp를 다시 지작점으로 돌려야할 필요가 있다.
// fseek(fp, 0, SEEK_SET)
// SEEK_SET : 파일의 시작점
// SEEK_END : 파일의 끝
// SEEK_CUR : 파일의 현재 시작점 

// "r+"모드
// 기능 : 파일을 읽은 후 쓰기 위한 모드, 파일이 존재하지 않으면 에러가 발생
// a모드(appendix) : 파일을 추가 모드로 열기 위한 모드, 파일의 마지막에 새로운 데이터를 쓰기 위한 모드
// a+모드 : 파일을 추가한 후에 읽기 까지 가능한 모드

// 정리 
// w+ : 쓰기/읽기 가능한 모드. 파일이 존재하면 내용을 모두 지우고 새로 시작
// r+ : 읽기/쓰기 가능한 모드. 파일을 읽은 후에 다시 쓰기가 가능한 모드
// a : 파일이 가리키는 마지막 위치에서 데이터를 추가하는 모드
// a+ : 파일을 추가한 후에 읽기 까지 가능한 모드

#include"lectures.h"
#include"FileFunc.h"

void AppendixMode()
{
	FILE* fp = fopen(filename3, "a");

	if (fp == NULL)
	{
		perror("Appendix Mode Error!\n");
	}
	
	fputs("Appendix Mode Text\n", fp);
	fclose(fp);
}

void AppendixPlusMode()
{
	FILE* fp = fopen(filename3, "a+");

	if (fp == NULL)
	{
		perror("Appendix Plus Mode Error!\n");
	}

	fputs("Append even Mode Text\n", fp);
	fseek(fp, 0, SEEK_SET);

	char buffer[100];
	
	fgets(buffer, sizeof(buffer), fp);
	printf("Read from this File : %s", buffer);
	fclose(fp);
}

void lectures26()
{
	//WriteFile();		// 파일을 써서 저장하는 함수
	//ReadFile();		// 파일을 불러오는 함수
	// test폴더 안에, Cprogram 이름으로 내용은 Today is 2024-07-31 텍스트가 출력되도록 파일을 하난 생성
	// 생성된 파일을 읽어와서 콘솔창에 출력

	//WriteFileByFile();
	//ReadFileByFile();
	//WritePlus();
	//FileIndicator();
	//ReadPlus();
	AppendixPlusMode();
	
}