/*
프로그램 명 : ch07-ass05.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.09.10
난이도 : ★
내용: 정수형 배열에 대해 사용자가 입력한 값을 배열 끝에서부터 역수으로 찾아 인덱스를 반환하는 프로그램
조건: 원소를 찾을 수 없으면 에러메세지 출력, 같은 값의 원소가 여러개면 처음 찾은 원소의 인덱스 반환
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input();
int find(int arr[], int target);

// 함수1. 메인함수
int main() {
	input();
	return 0;
}

// 함수2. 사용자로부터 찾을 값을 입력받고 배열에서 찾는 함수 호출
void input() {
	int target;
	int arr[] = { 23, 45, 62, 12, 99, 83, 23, 50, 12, 37 };
	printf("배열: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n찾을 값? ");
	scanf("%d", &target);
	int index = find(arr, target);
	if (index != -1) {
		printf("%d는 %d번째 원소입니다.\n", target, index);
	}
	else {
		printf("값 %d를 찾을 수 없습니다.\n", target);
	}
	return;
}

// 함수3. 배열에서 값을 찾아 인덱스를 반환하는 함수
int find(int arr[], int target) {
	for (int i = 9; i >= 0; i--) {
		if (arr[i] == target) {
			return i;
		}
	}
	return -1;
}