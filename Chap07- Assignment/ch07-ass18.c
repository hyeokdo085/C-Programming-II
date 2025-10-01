/*
프로그램 명 : ch07-ass18.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.09.10
난이도 : ★★★
내용: 최대 10개의 정수형 원소 저장 가능한 집합(set) 자료구조 구현
조건:
1. 원소의 중복 허용 안함
2. 정수를 입력 받으면 집합의 원소로 추가 후 원소 전체 출력
3. 이미 존재하는 원소 추가시 "해당 원소가 이미 [인덱스]에 존재합니다." 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input();
int add(int target, int arr[]);

// 함수1. 메인함수
int main() {
	input();
	return 0;
}

// 함수2. 사용자로부터 값을 입력받고 집합에 추가하는 함수 호출
void input() {
	int arr[10] = { 0 }; // 집합 초기화
	while (1) {
		int target;
		printf("배열에 추가할 원소? ");
		scanf("%d", &target);
		add(target, arr);
		if (arr[9] != 0) {
			printf("집합이 가득 찼습니다. 더 이상 원소를 추가할 수 없습니다.\n");
			break;
		}
	}
	return;
}

// 함수3. 집합에 원소를 추가하고 전체 원소를 출력하는 함수
int add(int target, int arr[]) {
	for (int i = 0; i < 10; i++) {
		if (arr[i] == target) {
			printf("해당 원소가 이미 [%d]에 존재합니다.\n", i);
			for (int j = 0; j < 10; j++) {
				if (arr[j] != 0) {
					printf("%d ", arr[j]);
				}
			}
			printf("\n");
			return -1;
		}
		if (arr[i] == 0) {
			arr[i] = target;
			for (int j = 0; j < 10; j++) {
				if (arr[j] != 0) {
					printf("%d ", arr[j]);
				}
			}
			printf("\n");
			return i;
		}
	}
	return -1; // 집합이 가득 찼을 때
}