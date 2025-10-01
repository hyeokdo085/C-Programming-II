/*
프로그램명 : ch09-ass01.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.09.24
난이도 : ★
내용 : 한 줄 문자열 입력받아 공백문자 개수 세는 프로그램
조건 : 공백문자는 ' ', '\n', '\t', '\f', '\r', '\v' 6가지
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_space();


int main() {
	int count = count_space();
	printf("공백문자 개수: %d\n", count);
	return 0;
}


// 함수1 : 문자열에서 공백문자 개수를 세는 함수
int count_space() {
	int count = 0;
	char str[100] = "";
	printf("문자열? ");
	gets_s(str, sizeof(str));

	for (int i = 0; i < strlen(str); i++) {
		if (isspace(str[i])) {
			count++;
		}
	}
	return count;
}