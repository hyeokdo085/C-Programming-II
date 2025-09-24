/*
프로그램 명 : 예제 9-7 문자열의 토큰 나누기
학번 : 202010853
이름 : 안도혁
날짜 : 2025_09_24
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void tok_str(void);

int main(void) {
	tok_str();
	return 0;
}

void tok_str(void) {
	char phone[] = "02-123-4567";
	char* p = NULL;

	p = strtok(phone, "-");
	printf("area code: %s\n", p);
	p = strtok(NULL, "-");
	printf("prefix: %s\n", p);
	p = strtok(NULL, "-");
	printf("line number: %s\n", p);

	return;
}