/*
프로그램명 : ch10-ass08.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.10.01
난이도 : ★
내용 : 커피숍에서 판매되는 제품 정보를 나타내는 PRODUCT 구조체
조건 :
1. 각 제품별로 제품명, 가격, 재고 저장(제품명은 빈칸 없는 한 단어)
2. PRODUCT 구조체를 매개변수로 전달받아 제품 정보를 출력하는 print_product 함수 작성
3. 제품명, 가격, 재고를 입력받아 저장하고 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct product {
	char name[20]; // 제품명
	int price;     // 가격
	int stock;     // 재고
} PRODUCT;

void ass08(void);
void print_product(PRODUCT p);

// 함수1 : 메인함수
int main() {
	ass08(); //함수 호출
	return 0;
}

// 함수2 : 제품 정보를 입력받고 출력하는 함수
void ass08(void) {
	PRODUCT p; // PRODUCT 구조체 변수 선언
	// 1. 제품명, 가격, 재고 입력받기
	printf("제품명? ");
	scanf("%s", p.name);
	printf("가격? ");
	scanf("%d", &p.price);
	printf("재고? ");
	scanf("%d", &p.stock);
	// 2. 제품 정보 출력하기
	print_product(p);
	return;
}

// 함수3 : PRODUCT 구조체를 매개변수로 받아 제품 정보를 출력하는 함수
void print_product(PRODUCT p) {
	printf("[%s %d원 재고:%d]\n", p.name, p.price, p.stock);
	return;
}