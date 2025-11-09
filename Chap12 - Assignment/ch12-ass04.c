/*
프로그램명 : ch12-ass04.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.11.09
내용 : 입력 받은 아이디와 패스워드가 일치하면 "로그인 성공" 아니면 "로그인 실패" 출력하는 프로그램
조건 :
1. 아이디와 패스워드가 저장된 password.txt파일을 크기가 10인 LOGIN 구조체 배열로 읽어들인다.
2. . 입력시 프로그램 종료
3. ID를 찾을 수 없다면 "아이디를 찾을 수 없습니다." 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 10
typedef struct {
    char id[20];
    char password[20];
} LOGIN;

void loginSystem();

// 함수1. 메인 함수
int main() {
    loginSystem();
    return 0;
}

// 함수2. 로그인 시스템 함수
void loginSystem() {
    LOGIN logins[MAX]; // LOGIN 구조체 배열
    FILE* pwfile = NULL;
    char inputId[20];
    char inputPassword[20];
    int count = 0;

    // 1. password.txt 파일 열기
    pwfile = fopen("password.txt", "r");
    if (pwfile == NULL) { // 예외 처리
        fprintf(stderr, "파일을 열 수 없습니다\n");
        return;
    }

    // 2. 파일에서 아이디와 패스워드 읽어들이기
    while (fscanf(pwfile, "%s %s", logins[count].id, logins[count].password) != EOF && count < MAX) {
        count++;
    }
    fclose(pwfile); // 파일 닫기

    // 3. 로그인 시도
    while (1) {
        int found = 0; // 아이디 찾음 여부
        printf("ID? ");
        scanf("%s", inputId);
        if (strcmp(inputId, ".") == 0) { // 종료 조건
            break;
        }

        for (int i = 0; i < count; i++) {
            if (strcmp(inputId, logins[i].id) == 0) { // 아이디 일치
                found = 1;
                printf("Password? ");
                scanf("%s", inputPassword);
                if (strcmp(inputPassword, logins[i].password) == 0) { // 패스워드 일치
                    printf("로그인 성공\n");
                    break;
                }
                else {
                    printf("로그인 실패\n");
                    break;
                }
            }
        }
        if (found != 1)
        printf("아이디를 찾을 수 없습니다.\n");
    }
}