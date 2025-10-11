/*
프로그램명 : ch09-ass16.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.10.02
난이도 : ★★★
내용 : 인터넷 사이트에 로그인 하는 프로그램
조건 : 
1. 등록된 사용자 5명
2. 아이디가 존재X or 패스워드 틀림 -> 에러메세지 출력 후 재입력
3. 3번의 재시도 후에도 실패시 로그인 실패 에러메세지 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct account {
	char ID[20];
	char PW[20];
} ACC;

ACC users[5] = { // ACC 구조체 배열 초기화
		{"sugar", "dna!awesome"},
		{"parkjimin", "@BestOfMe@"},
		{"hyeok_085", "abc1234"},
		{"sang629", "def5678"},
		{"lee_guen", "@@program2"}
};

int check_login(char id[], char pw[]);
void input_login();
void output_login(int result);

int main() {
	input_login();
	return 0;
}

// 함수1 : 아이디와 패스워드를 입력받고 check_login 함수 호출하는 함수
void input_login() {
	char id[20] = "";
	char pw[20] = "";
	
	for (int attempts = 0; attempts < 3; attempts++) {
		printf("ID? ");
		scanf("%s", id);
		printf("PW? ");
		scanf("%s", pw);
		output_login(check_login(id, pw));
		if (check_login(id, pw) == 1) {
			break; // 로그인 성공 시 반복문 종료
		}
		if (attempts == 2) { // 3번째 시도 후에도 실패 시
			printf("로그인 3회 실패!\n");
		}
	}
	return;
}

// 함수2 : 아이디와 패스워드를 비교하는 함수
int check_login(char id[], char pw[]) {
	for (int i = 0; i < 5; i++) {
		if (strcmp(users[i].ID, id) == 0) { // 아이디가 일치하는지 확인
			if (strcmp(users[i].PW, pw) == 0) { // 패스워드 비교
				return 1; // 로그인 성공
			}
			else {
				return -1; // 패스워드 틀림
			}
		}
	}
	return 0; // 아이디 없음
}

// 함수3 : 로그인 결과에 따라 출력하는 함수
void output_login(int result) {
	if (result == 1) {
		printf("로그인 성공!\n\n");
	}
	else if (result == -1) {
		printf("패스워드가 틀렸습니다.\n\n");
	}
	else {
		printf("해당 id가 없습니다.\n\n");
	}
	return;
}