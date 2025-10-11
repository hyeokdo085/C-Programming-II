/*
프로그램명 : ch10-ass11.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.10.01
난이도 : ★★★
내용 : 카페 주문 처리 프로그램
조건 :
1. PRODUCT 구조체 배열 (크기 5) 선언 및 초기화
2. 제품명, 수량 입력 / 결제금액, 제품 재고 출력
3. 제품 재고를 주문 수량만큼 차감
4. 재고 부족, 제품 없음 = 에러메시지 출력
5. 제품명 "." 입력시 재고 목록 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct product {
	char name[20]; // 제품명
	int price;     // 가격
	int stock;     // 재고
} PRODUCT;

// PRODUCT 구조체 배열 (크기 5) 선언 및 초기화
PRODUCT coffee[5] = {
	{"아메리카노", 4000, 10},
	{"카페라떼", 4500, 10},
	{"플랫화이트", 5000, 10},
	{"아샷추", 4500, 10},
	{"자몽허니블랙티", 5500, 10}
};

void cafe_manager(char name[], int stock);
void order_coffee();

int main() {
	order_coffee();
	return 0;
}

// 함수1 : 제품명과 수량을 입력받고 cafe_manager 함수 호출하는 함수
void order_coffee() {
	while (1) {
		char name[20] = "";
		int stock;

		printf("제품명? ");
		scanf("%s", name);
		if (strcmp(name, ".") == 0) { // 제품명이 "."이면 재고 목록 출력
			for (int i = 0; i < 5; i++) {
				printf("[%s %d원 재고:%d]\n", coffee[i].name, coffee[i].price, coffee[i].stock);
			}
			continue; // 다시 제품명 입력받기
		}

		printf("수량? ");
		scanf("%d", &stock);

		cafe_manager(name, stock); // 카페 주문 처리 함수 호출
	}
	return;
}

// 함수2 : 제품명과 수량을 매개변수로 받아 주문 처리하는 함수
void cafe_manager(char name[], int stock) {
	int found = 0; // 제품 존재 여부 확인 변수

	for (int i = 0; i < 5; i++) {
		if (strcmp(coffee[i].name, name) == 0) { // 제품명이 일치하는지 확인
			found = 1; // 제품 존재하면?
			if (coffee[i].stock >= stock) { // 재고가 충분하면?
				coffee[i].stock -= stock; // 재고 차감
				int total_price = coffee[i].price * stock; // 결제 금액 계산
				printf("결제 금액: %d원 ", total_price);
				printf("%s 재고: %d\n", name, coffee[i].stock);
			}
			else {
				printf("재고가 부족합니다.\n"); // 재고 부족 메시지 출력
			}
			break;
		}
	}

	if (found == 0) {
		printf("해당 제품이 없습니다.\n"); // 제품 없음 메시지 출력
	}
	return;
}