/*
프로그램 명 : 예제 9-6 문자열의 검색
학번 : 202010853
이름 : 안도혁
날짜 : 2025_09_24
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void chr_str(char* str1, char* p);
void str_str(char* str1, char* p);

int main(void) {
	char filename[] = "readme.txt";
	char* p = NULL;
	chr_str(filename, p);
	str_str(filename, p);
	return 0;
}

void chr_str(char* str1, char* p) {
	p = strchr(str1, '.'); //문자 검색
	if (p != NULL)
		printf("file extension: %s\n", p + 1);
}

void str_str(char* str1, char* p) {
	p = strstr(str1, ".txt"); //문자열 검색
	if (p != NULL)
		printf("file type: TEXT file\n");
	return;
}