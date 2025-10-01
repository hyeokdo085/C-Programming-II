/*
프로그램명 : ch10-ass03.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.10.01
난이도 : ★★
내용 : LOGIN 구조체를 사용한 로그인 과정 프로그램
조건 :
1. 아이디와 패스워드는 각각 최대 20글자
2. 아이디를 입력받아 LOGIN 구조체 배열에서 검색
	이후 입력받은 패스워드와 등록된 패스워드를 비교하여 같으면 로그인 성공 메시지 출력
3. LOGIN 구조체 배열은 크기가 5인 배열로 선언 및 적당한 값으로 초기화 후 사용
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct login {
	char ID[20]; // 아이디
	char PW[20]; // 패스워드
} LOGIN;

void ass03(void);

// 함수1 : 메인함수
int main() {
	ass03(); //함수 호출
	return 0;
}

// 함수2 : 아이디와 패스워드 입력받고 비교하여 로그인 성공 여부 출력하는 함수
void ass03(void) {
	LOGIN users[5] = { // LOGIN 구조체 배열 초기화
		{"guest", "idontknow"},
		{"guest2", "iknow"},
		{"guest3", "idoknow"},
		{"guset4", "youknow"},
		{"guest5", "youdontknow"}
	};

	LOGIN input; // 입력받을 LOGIN 구조체 변수 선언
	// 1. 아이디 입력받기(틀릴 때까지 반복)
	while (1) {
		printf("ID? ");
		scanf("%s", input.ID);
		// 2. 아이디 검색 및 패스워드 입력받기
		for (int i = 0; i < 5; i++) {
			if (strcmp(users[i].ID, input.ID) == 0) { // 아이디가 일치하는지 확인
				printf("PW? ");
				scanf("%s", input.PW);
				if (strcmp(users[i].PW, input.PW) == 0) { // 패스워드 비교
					printf("로그인 성공\n");
					break;
				}
				else {
					printf("비밀번호가 다릅니다.\n");
					break;
				}
				break;
			}
			else {
				return;
			}
		}
	}
}