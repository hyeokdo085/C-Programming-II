/*
프로그램명 : ch08-ass05.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.09.24
난이도 : ★★
내용 : 
첫 항과 공차로 크기가 10인 정수형 배열에 대해 등차수열 구하는 프로그램
조건 : 
1. 첫 항의 값은 배열 0번 원소에 넣어 전달
2. 배열과 배열의 크기, 공차를 매개변수로 받아 등차수열로 배열을 채우는
arith_seq 함수 정의
3. 포인터에 의한 전달 사용
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void arith_seq(int* arr, int size, int diff);
void input_values();

int main() {
	input_values();
	return 0;
}

// 함수1 : 첫 항과 공차를 입력받고 arith_seq 함수 호출하는 함수
void input_values() {
	int arr[10] = { 0 }; // 크기가 10인 int형 배열 선언 및 초기화
	int first, diff;  

	printf("첫 번째 항? ");
	scanf("%d", &first);
	arr[0] = first; // 첫 항을 배열 0번 원소에 저장

	printf("공차? ");
	scanf("%d", &diff);

	arith_seq(arr, 10, diff); // 등차수열을 구하는 함수 호출

	printf("등차수열: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]); // 등차수열 출력
	}
	return;
}

// 함수2 : 배열과 배열의 크기, 공차를 매개변수로 받아 
// 등차수열로 배열을 채우는 함수
void arith_seq(int* arr, int size, int diff) {
	for (int i = 1; i < size; i++) {
		*(arr + i) = *((arr + i) - 1) + diff; // 포인터 연산을 이용해 등차수열 계산
	}
	return;
}