/*
프로그램명 : ch12-ass11.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.11.09
내용 : 연락처 관리 프로그램에 텍스트 파일로부터 연락처 로딩하는 기능
조건 :
1. CONTACT 구조체 사용
2. 파일 이름 입력받고 읽어서 CONTACT 구조체 배열을 생성
3. CONTACT 구조체 배열은 동적 메모리에 생성
4. 이름을 입력하면 해당 연락처 출력, 없으면 "연락처를 찾을 수 없습니다." 출력
5. . 입력시 프로그램 종료
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //동적 메모리 할당에 필요
#include <string.h>

typedef struct {
    char name[20];
    char phone[20];
} CONTACT;

void loadContacts();

// 함수1. 메인 함수
int main() {
    loadContacts();
    return 0;
}

// 함수2. 연락처 로딩 및 검색 함수
void loadContacts() {
    char filename[100];
    FILE* file = NULL;
    CONTACT* contacts = NULL; // CONTACT 구조체 배열 포인터
    
    // 1. 파일 이름 입력받고 열기
    printf("파일명? ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) { // 예외 처리
        fprintf(stderr, "파일을 열 수 없습니다\n");
        return;
    }

    // 2. 파일에서 연락처 개수 세기
    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    // 마지막 줄에 줄바꿈이 없는 경우를 대비하여, 파일 크기가 0이 아니면 개수를 하나 더 추가
    if (count > 0 || ftell(file) > 0) { // 현재 파일 포인터 위치 비교
        count++;
    }
    fseek(file, 0, SEEK_SET); // 파일 포인터를 처음으로 되돌리기
    printf("%d개의 연락처를 로딩했습니다.\n", count);

    // 3. 동적 메모리 할당
    contacts = (CONTACT*)malloc(count * sizeof(CONTACT));
    if (contacts == NULL) {
        fprintf(stderr, "메모리 할당에 실패했습니다\n");
        fclose(file);
        return;
    }

    // 4. 파일에서 연락처 읽어들이기
    for (int i = 0; i < count; i++) {
        fscanf(file, "%s %s", contacts[i].name, contacts[i].phone);
    }
    fclose(file); // 파일 닫기

    // 5. 연락처 검색 및 출력
    char inputName[20];
    while (1) {
        int found = 0; // 연락처 찾음 여부
        printf("이름(. 입력 시 종료)? ");
        scanf("%s", inputName);
        if (strcmp(inputName, ".") == 0) { // 종료 조건
            return;
        }

        for (int i = 0; i < count; i++) {
            if (strcmp(contacts[i].name, inputName) == 0) {
                printf("%s의 전화번호 %s로 전화를 겁니다....\n", contacts[i].name, contacts[i].phone);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("연락처를 찾을 수 없습니다.\n");
        }
    }
    // 6. 동적 메모리 해제
    free(contacts);
}