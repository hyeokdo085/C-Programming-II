/*
프로그램명 : ch10-ass13.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.10.01
난이도 : ★★
내용 : 직사각형 정보를 나타내는 RECT 구조체
조건 :
1. 직사각형은 좌하단점과 우상단점으로 구성, 좌표는 구조체로 표현
2. 직사각형 정보를 출력하는 print_rect 함수 작성
3. RECT 구조체 변수 선언하여 직사각형 정보 입력받아 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct rect {
	int x1, y1; // 좌하단점 좌표
	int x2, y2; // 우상단점 좌표
} RECT;

void ass13(void);
void print_rect(RECT r);

// 함수1 : 메인함수
int main() {
	ass13(); //함수 호출
	return 0;
}

// 함수2 : 직사각형 정보를 입력받고 출력하는 함수
void ass13(void) {
	RECT r; // RECT 구조체 변수 선언
	// 1. 좌하단점과 우상단점 좌표 입력받기
	printf("직사각형의 좌하단점(x,y)? ");
	scanf("%d %d", &r.x1, &r.y1);
	printf("직사각형의 우상단점(x,y)? ");
	scanf("%d %d", &r.x2, &r.y2);
	// 2. 직사각형 정보 출력하기
	print_rect(r);
	return;
}

// 함수3 : RECT 구조체를 매개변수로 받아 직사각형 정보를 출력하는 함수
void print_rect(RECT r) {
	printf("[RECT 좌하단점:(%d, %d) 우상단점:(%d,%d)]\n", r.x1, r.y1, r.x2, r.y2);
	return;
}