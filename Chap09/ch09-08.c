/*
프로그램 명 : 예제 9-8 문자열의 입출력
학번 : 202010853
이름 : 안도혁
날짜 : 2025_09_24
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void io_str(void);

int main(void) {
	io_str();
	return 0;
}

void io_str(void) {
	char in_str[128];
	char out_str[128];
	int hour = 12, min = 30, sec = 45;

	printf("문자열? ");
	gets_s(in_str, sizeof(in_str)); //빈칸 포함 문자열 입력
	puts(in_str); //문자열과 줄바꿈 문자 함께 출력
	sprintf(out_str, "%02d:%02d:%02d", hour, min, sec); //문자열 생성
	puts(out_str);
	return;
}