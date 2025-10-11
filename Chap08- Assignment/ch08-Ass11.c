/*
프로그램명 : ch08-ass11.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.09.24
난이도 : ★★★
내용 : 가로, 세로 길이 입력받아 함수를 이용해 
직사각형의 넓이와 둘레 구하는 프로그램
조건 : 직사각형의 넓이와 둘레를 구하는 get_rect_info 함수 정의
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void get_rect_info(int* width, int* height);
void input_values();

int main() {
	input_values();
	return 0;
}

// 함수1 : 가로와 세로 길이를 입력받고 get_rect_info 함수 호출하는 함수
void input_values() {
	int width, height;

	printf("가로? ");
	scanf("%d", &width);
	printf("세로? ");
	scanf("%d", &height);

	get_rect_info(&width, &height); // 직사각형의 넓이와 둘레를 구하는 함수 호출
	return;
}

// 함수2 : 가로와 세로 길이를 매개변수로 받아 직사각형의 넓이와 둘레를 구하는 함수
void get_rect_info(int* width, int* height) {
	int area = (*width) * (*height); // 넓이 계산
	int perimeter = 2 * ((*width) + (*height)); // 둘레 계산
	printf("넓이: %d, 둘레: %d\n", area, perimeter);
	return;
}