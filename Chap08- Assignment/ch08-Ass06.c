/*
프로그램명 : ch08-ass06.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.09.24
난이도 : ★★
내용 : 
크기 10인 int 배열, 원하는 초기값으로 채워, 
get_min_max 함수로 최댓값과 최솟값 구하는 프로그램
조건 : 
정수형 배열에 대해 배열의 원소 중 
최댓값과 최솟값 찾는 get_min_max 함수 정의
*/

#include <stdio.h>

void get_min_max(int* arr);
void input_values();

int main() {
	input_values();
	return 0;
}

// 함수1 : 배열의 모든 원소를 선언하고 get_min_max 함수 호출하는 함수
void input_values() {
	int arr[10] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };

	printf("배열: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]); // 배열 원소 출력
	}

	get_min_max(arr); // 최댓값과 최솟값을 구하는 함수 호출
	return;
}

// 함수2 : 배열의 원소 중 최댓값과 최솟값을 찾는 함수
void get_min_max(int* arr) {
	int min = *arr; // 배열의 첫 번째 원소로 초기화
	int max = *arr; // 배열의 첫 번째 원소로 초기화
	for (int i = 1; i < 10; i++) {
		if (*(arr + i) > max) {
			max = *(arr + i); // 최댓값 갱신
		}
		if (*(arr + i) < min) {
			min = *(arr + i); // 최솟값 갱신
		}
	}
	printf("\n최댓값: %d\n", max);
	printf("최솟값: %d\n", min);
	return;
}