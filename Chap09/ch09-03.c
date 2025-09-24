/*
프로그램 명 : 예제 9-3 문자열의 교환
학번 : 202010853
이름 : 안도혁
날짜 : 2025_09_24
*/

#define _CRT_SECURE_NO_WARNINGS //헤더 앞
#include <stdio.h>
#include <string.h>
#define SIZE 32

void swap_str(void);

int main(void) {
	swap_str();
	return 0;
}

void swap_str(void) {
	char str1[SIZE] = "";
	char str2[SIZE] = "";
	char temp[SIZE];

	printf("두 개의 문자열? ");
	scanf("%s %s", str1, str2);
	printf("str1 = %s, str2 = %s\n", str1, str2);

	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
	printf("str1 = %s, str2 = %s\n", str1, str2);
	return;
}