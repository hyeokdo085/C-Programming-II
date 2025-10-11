/*
프로그램명 : ch09-ass04.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.10.02
난이도 : ★
내용 : 문자열 입력받아 역순으로 출력하는 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse_string();

int main() {
	reverse_string();
	return 0;
}

// 함수1 : 문자열을 받아 역순으로 출력하는 함수
void reverse_string() {
	char str[100] = "";
	printf("문자열? ");
	gets_s(str, sizeof(str));
	int len = strlen(str);

	printf("역순으로 된 문자열: ");
	for (int i = len - 1; i >= 0; i--) {
		printf("%c", str[i]);
	}
	printf("\n");
}