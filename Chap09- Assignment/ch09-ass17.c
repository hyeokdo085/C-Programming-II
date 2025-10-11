/*
프로그램명 : ch09-ass17.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.10.02
난이도 : ★★★
내용 : 입력 받은 노래 제목 최대 20개 저장 관리 프로그램
조건 :
1. 노래 제목 최대 40글자
2. 노래 제목 추가, 노래 제목 수정, 노래 목록 출력 기능
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct song {
	char title[40];
} SONG;

SONG song[20]; // SONG 구조체 배열 선언 및 전역변수로 사용

int print_menu();
void add_song();
void edit_song();
void list_songs();


int main() {
	while (1) {
		if (print_menu() == 0) {
			break;
		}
		else {
			continue;
		}
	}
	return 0;
}

// 함수1 : 메뉴를 출력하고 선택한 기능을 수행하는 함수	
int print_menu() {
	int choice;
	printf("[ 0.종료 1.추가 2.수정 3.목록 ] 선택? ");
	scanf("%d", &choice);
	switch (choice) {
	case 0:
		return 0;
	case 1:
		add_song();
		break;
	case 2:
		edit_song();
		break;
	case 3:
		list_songs();
		break;
	default:
		printf("잘못된 선택입니다.\n");
		break;
	}
	return 1;
}

// 함수2 : 노래 제목을 추가하는 함수
void add_song() {
	for (int i = 0; i < 20; i++) {
		if (strcmp(song[i].title, "\0") == 0) { // 빈 자리 찾기
			printf("노래 제목? ");
			scanf(" %[^\n]", song[i].title); // 공백 포함 입력
			return;
		}
	}
	printf("노래 제목이 가득 찼습니다.\n");
}

// 함수3 : 노래 제목을 수정하는 함수
void edit_song() {
	char title_temp[40];
	printf("찾을 노래 제목? ");
	scanf(" %[^\n]", title_temp); // 공백 포함 입력
	for (int i = 0; i < 20; i++) {
		if (strcmp(song[i].title, title_temp) == 0) { // 노래 제목 찾기
			printf("수정할 제목? ");
			scanf(" %[^\n]", song[i].title); // 공백 포함 입력
			return;
		}
	}
	printf("노래 제목을 찾을 수 없습니다.\n");
	return;
}

// 함수4 : 노래 제목 목록을 출력하는 함수
void list_songs() {
	printf("<< 노래 목록 >>\n");
	for (int i = 0; i < 20; i++) {
		if (strcmp(song[i].title, "\0") != 0) { // 빈 자리 제외 출력
			printf("%s\n", song[i].title);
		}
	}
	return;
}