/*
프로그램 명 : ch07-ass12.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.09.10
난이도 : ★★★
내용: 기차표 예매 프로그램
조건:
1. 좌석은 10개로 제한
2. 예매할 좌석수를 입력받아 빈자리 앞에서부터 채움
3. 예매할 때마다 각 좌석의 상태 출력
4. 좌석 상태는 O(예약 가능)과 X(예약 불가)로 표시
5. 예약 불가할 경우 프로그램 종료
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input();
void reserve(int num, char seats[]);

// 함수1. 메인함수
int main() {
	input();
	return 0;
}

// 함수2. 사용자로부터 예매할 좌석수를 입력받고 예약 함수 호출
void input() {
	char seats[10] = { 'O','O','O','O','O','O','O','O','O','O' }; // 좌석 초기화
	while (1) {
		printf("현재 좌석: ");
		for (int i = 0; i < 10; i++) {
			printf("%c ", seats[i]);
		}
		printf("\n예매할 좌석수? ");
		int num;
		scanf("%d", &num);
		reserve(num, seats);
		if (seats[9] == 'X') {
			printf("좌석이 가득 찼습니다. 프로그램을 종료합니다.\n");
			return;
		}
	}
	return;
}

// 함수3. 좌석을 예약하고 배열을 변경하는 함수
void reserve(int num, char seats[]) {
	int count = 0;
	for (int i = 0; i < 10; i++) {
		if (seats[i] == 'O') {
			seats[i] = 'X';
			count++;
			printf("%d ", i + 1);
			if (count == num) {
				printf("번 좌석을 예약했습니다.\n");
				break;
			}
		}
	}
	if (count < num) {
		printf("번 좌석만 남아 %d인 예약이 불가합니다. \n", num);
		exit(0);
	}
	return;
}