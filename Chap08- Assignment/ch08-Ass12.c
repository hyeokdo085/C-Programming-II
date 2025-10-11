/*
프로그램명 : ch08-ass12.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.09.24
난이도 : ★★★
내용 : 정수형 배열과 키 값을 매개변수로 전달받아 배열에서 키 값을 찾고 
인덱스를 배열에 저장해서 리턴하는 함수 프로그램
조건 : 이 함수는 찾은 항목의 개수를 리턴, 항목 찾을 수 없으면 0 리턴
예시 : 12를 2개 찾으면 2를 리턴, 찾은 항목의 인덱스는 인덱스 배열에 저장
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const int arr[10] = { 12, 45, 62, 12, 99, 83, 23, 12, 72, 37 }; // 크기가 10인 int형 배열 선언 및 초기화

int find_key_indices(int* found_index, int key);
void input_values();

int main() {
	input_values();
	return 0;
}

// 함수1 : 배열과 키 값을 입력받고 find_key_indices 함수 호출하는 함수
void input_values() {
	int key;
	int found_index[10] = { -1 }; // 찾은 인덱스를 저장할 배열, 초기값 -1로 설정

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]); // 배열 원소 출력
	}
	printf("\n");

	printf("찾을 값? ");
	scanf("%d", &key);

	int count = find_key_indices(found_index, key); // 키 값을 찾는 함수 호출

	if (count > 0) {
		printf("찾은 항목은 %d개입니다.\n", count);
		printf("찾은 인덱스: ");
		for (int i = 0; i < count; i++) {
			printf("%d ", found_index[i]); // 찾은 인덱스 출력
		}
		printf("\n");
	}
	else {
		printf("%d가 없습니다.\n", key);
	}
	return;
}

// 함수2 : 배열과 키 값을 매개변수로 받아 키 값을 찾고 인덱스를 배열에 저장하는 함수
int find_key_indices(int* found_index, int key) {
	int count = 0; // 찾은 항목의 개수
	for (int i = 0; i < 10; i++) {
		if (arr[i] == key) {
			found_index[count++] = i; // 찾은 인덱스를 배열에 저장하고 개수 증가
		}
	}
	return count; // 찾은 항목의 개수 리턴
}