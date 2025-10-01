/*
프로그램명 : ch10-ass01.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.10.01
난이도 : ★
내용 : 아이디와 패스워드 관리를 위한 LOGIN 구조체
조건 :
1. 아이디와 패스워드는 각각 최대 20글자
2. 아이디와 패스워드를 입력 받아 저장, 출력
3. 패스워드 출력 시, 별표(*)로 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct login {
	char ID[20]; // 아이디
	char PW[20]; // 패스워드
} LOGIN;

void ass01(void);

// 함수1 : 메인함수
int main() {
	ass01(); //함수 호출
	return 0;
}

// 함수2 : 아이디와 패스워드 입력받고 출력하는 함수
void ass01(void) {
	LOGIN user; // LOGIN 구조체 변수 선언
	// 1. 아이디와 패스워드 입력받기
	printf("ID? ");
	scanf("%s", user.ID);
	printf("Password? ");
	scanf("%s", user.PW);
	// 2. 아이디와 패스워드 출력하기
	printf("ID: %s\n", user.ID);
	printf("PW: ");
	for (int i = 0; (i < 20) && (user.PW[i] != '\0'); i++) {
		printf("*");
	}
	return;
}