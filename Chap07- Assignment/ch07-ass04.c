/*
프로그램 명 : ch07-ass04.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.09.10
난이도 : ★★
내용 : 정수형 배열에 대해 배열의 원소 중 최댓값을 가진 원소와 최솟값을 가진 원소의 인덱스와 값을 출력하는 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void find_max(int arr[]);
void find_min(int arr[]);
void array();

// 함수1. 메인함수
int main() {
	array();
	return 0;
}

// 함수2. 배열을 출력하고, 최댓값 검색 함수와 최솟값 검색 함수 호출
void array() {
	int arr[] = { 23, 45, 62, 12, 99, 83, 23, 50, 12, 37 };
	printf("배열: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	find_max(arr);
	find_min(arr);
	return;
}

// 함수3. 배열에서 최댓값을 찾아 인덱스와 값을 출력하는 함수
void find_max(int arr[]) {
	int max = arr[0];
	int max_index = 0;
	for (int i = 1; i < 10; i++) {
		if (arr[i] > max) {
			max = arr[i];
			max_index = i;
		}
	}
	printf("최댓값: 인덱스=%d, 값=%d\n", max_index, max);
	return;
}

// 함수4. 배열에서 최솟값을 찾아 인덱스와 값을 출력하는 함수
void find_min(int arr[]) {
	int min = arr[0];
	int min_index = 0;
	for (int i = 1; i < 10; i++) {
		if (arr[i] < min) {
			min = arr[i];
			min_index = i;
		}
	}
	printf("최솟값: 인덱스=%d, 값=%d\n", min_index, min);
	return;
}