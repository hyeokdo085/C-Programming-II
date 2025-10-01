/*
프로그램 명 : ch07-ass01.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.09.10
난이도 : ★
내용 : 크기가 10인 정수형 배열에 대해 등차수열로 값을 채우는 프로그램
조건 : 첫번째 항과 공차는 사용자로부터 입력받음
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input();
void fill(int arr[], int first, int cd);

// 함수1. 메인함수
int main() {
	input();
	return 0;
}

// 함수2. 사용자로부터 첫번째 항과 공차를 입력받고 배열에 값을 채우는 함수 호출
void input() {
	int first, cd;
	int arr[10];
	printf("첫번째 항을 입력하세요: ");
	scanf("%d", &first);
	printf("공차를 입력하세요: ");
	scanf("%d", &cd);
	fill(arr, first, cd);
	return;
}

// 함수3. 등차수열로 배열에 값을 채우고 출력하는 함수
void fill(int arr[], int first, int cd) {
	for (int i = 0; i < 10; i++) {
		arr[i] = first + i * cd;
	}
	printf("배열의 값: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}