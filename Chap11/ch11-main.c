/*
프로그램 명 : 수업 중 실습(변수)
학번 : 202010853
이름 : 안도혁
날짜 : 2025_10_14
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

//extern int get_id();
//extern int last_id;

int main(int argc, char* argv[]) {

	printf("추석 잘 보내셨어요?\n");

	printf("회원1의 id = %d\n", get_id()); // 1001
	printf("회원2의 id = %d\n", get_id()); // 1002
	printf("회원3의 id = %d\n", get_id()); // 1003

	//printf("last_id = %d\n", last_id++);

	return 0;
}