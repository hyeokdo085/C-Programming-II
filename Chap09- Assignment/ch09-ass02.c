/*
프로그램명 : ch09-ass02.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.09.24
난이도 : ★★
내용 : 문자열 입력받아 공백문자 제거 후 출력하는 프로그램
조건 : 공백문자는 ' ', '\n', '\t', '\f', '\r', '\v' 6가지
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void remove_space();

int main() {
	remove_space();
	return 0;
}

// 함수1 : 문자열을 받아 공백문자를 제거하는 함수

void remove_space() {
	char str[100] = "";
	char result[100] = "";
	printf("문자열? ");
	gets_s(str, sizeof(str));

	int index = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (!isspace(str[i])) {
			result[index++] = str[i];
		}
	}
	result[index] = '\0'; // 문자열 종료 문자 추가
	printf("공백 문자 제거 후: %s\n", result);
}
