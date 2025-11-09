/*
프로그램명 : ch12-ass12.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.11.09
내용 : ass11.c 프로그램에 연락처 검색 실패시 새로운 연락처 추가하는 기능
조건 :
1. 또한, 프로그램 종료 시 CONTACT 구조체 내용을 텍스트 파일로 저장
*/

// ass11.c을 기반으로 작성
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //동적 메모리 할당에 필요
#include <string.h>

typedef struct {
    char name[20];
    char phone[20];
} CONTACT;

void manageContacts();

// 함수1. 메인 함수
int main() {
    manageContacts();
    return 0;
}

// 함수2. 연락처 관리 함수
void manageContacts() {
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

    // 3. 동적 메모리 할당 및 연락처 읽기
    contacts = (CONTACT*)malloc(count * sizeof(CONTACT));
    for (int i = 0; i < count; i++) {
        fscanf(file, "%s %s", contacts[i].name, contacts[i].phone);
    }
    fclose(file); // 파일 닫기
    printf("%d개의 연락처를 로딩했습니다.\n", count);
    for (int i = 0; i < count; i++) {
        printf("%s %s\n", contacts[i].name, contacts[i].phone);
    }

    // 4. 연락처 검색 및 추가 기능
    char inputName[20];
    while (1) {
        int found = 0; // 연락처 찾음 여부
        char temp;
        printf("이름? ");
        scanf("%s", inputName);
        if (strcmp(inputName, ".") == 0) { // 종료 조건
            break;
        }
        for (int i = 0; i < count; i++) {
            if (strcmp(contacts[i].name, inputName) == 0) {
                printf("%s의 전화번호 %s로 전화를 겁니다....\n", contacts[i].name, contacts[i].phone);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("연락처를 찾을 수 없습니다. 연락처를 등록하시겠습니까?(y/n) ");
            scanf(" %c", &temp);
            if (temp == 'y') {
                printf("전화번호? ");
                char newPhone[20];
                scanf("%s", newPhone);
                contacts = (CONTACT*)realloc(contacts, (count + 1) * sizeof(CONTACT));
                strcpy(contacts[count].name, inputName);
                strcpy(contacts[count].phone, newPhone);
                count++;
                printf("새 연락처가 추가되었습니다.\n");
            }
            else if (temp == 'n') {
                continue;
            }
            else {
                printf("잘못된 입력입니다. 다시 시도하세요.\n");
            }
        }
    }
    // 5. 연락처를 파일에 저장
    file = fopen(filename, "w");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s\n", contacts[i].name, contacts[i].phone);
    }
    fclose(file);
    printf("%s로 %d개의 연락처를 저장했습니다.\n", filename, count);
    free(contacts); // 동적 메모리 해제
}