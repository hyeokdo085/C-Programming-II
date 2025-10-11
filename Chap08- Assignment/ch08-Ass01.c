/*
프로그램명 : ch08-ass01.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.09.24
난이도 : ★
내용 : 크기가 3인 double형 배열의 모든 원소의 주소를 출력하는 프로그램
조건 : 주소 구하기 연산자 사용 금지(포인터 활용)
*/

#include <stdio.h>

void find_address();

int main() {
	find_address();
	return 0;
}

// 함수1 : double형 배열의 모든 원소의 주소를 출력하는 함수(포인터)
void find_address() {
	double arr[3] = { 1.1, 2.2, 3.3 }; // 크기가 3인 double형 배열 선언 및 초기화
	for (int i = 0; i < 3; i++) {
		printf("arr[%d]의 주소: %p\n", i, (arr + i)); // 포인터 연산을 이용해 주소 출력
	}
	return;
}