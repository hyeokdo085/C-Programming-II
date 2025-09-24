/*
프로그램 명 : 예제 9-4 문자열의 비교
학번 : 202010853
이름 : 안도혁
날짜 : 2025_09_24
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 10

void cmp_str(void);
void password(void);

int main(void) {
	cmp_str();
	password();
	return 0;
}

void cmp_str(void) {
	char s1[SIZE] = "apple";
	char s2[SIZE] = "apple";
	
	if (s1 == s2) //주소 비교
		printf("same address\n");
	
	if (strcmp(s1, s2) == 0)
		printf("same string\n");
}

void password(void) {
	char password[SIZE];
	printf("패스워드? ");
	scanf("%s", password);
	if (strcmp(password, "abcd1234") == 0)
		printf("login succeeded\n");
	else 
		printf("login failed\n");
	return;
}