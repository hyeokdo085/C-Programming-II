/*
프로그램 명 : ch07-ass07.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.09.10
난이도 : ★★
내용: 정수형 배열의 모든 원소를 특정 값으로 채우는 fill_array 함수를 작성하고, 크기가 20인 배열을 선언하여 전체를 채우는 프로그램
조건: fill_array 함수는 배열, 크기, 값을 매개변수로 받음
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fill_array(int arr[], int size, int value);
void input();

// 함수1. 메인함수
int main() {
	input();
	return 0;
}

// 함수2. 사용자로부터 채울 값을 입력받고 배열을 채우는 함수 호출
void input() {
	int arr[20];
	int value;
	printf("채울 값? ");
	scanf("%d", &value);
	fill_array(arr, 20, value);
	return;
}

// 함수3. 배열의 모든 원소를 특정 값으로 채우고 출력하는 함수
void fill_array(int arr[], int size, int value) {
	for (int i = 0; i < size; i++) {
		arr[i] = value;
	}
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}