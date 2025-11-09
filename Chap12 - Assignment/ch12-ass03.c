/*
프로그램명 : ch12-ass03.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.11.09
내용 : txt파일 입력받아 파일 내 문자에 대해 영문자 개수 문자별로 세서 출력하는 프로그램
조건 :
１. 일단 파일 전체 출력
２. 대소문자 구분하지 않는다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void countABC();

// 함수1. 메인 함수
int main() {
    countABC();
    return 0;
}

// 함수2. txt 파일의 내용을 출력하는 함수
void countABC() {
    char filename[100]; 
    FILE* file = NULL; 
    char ch;           
    int counts[26] = { 0 }; // 알파벳 개수 저장 배열

    // 1. 파일 이름 입력받기
    printf("파일명? ");
    scanf("%s", filename);

    // 2. 파일 열기
    file = fopen(filename, "r"); // 읽기 모드로 파일 열기
    if (file == NULL) { // 예외 처리
        fprintf(stderr, "파일을 열 수 없습니다\n");
        return;
    }

    // 3. 파일 내용 읽고 출력 및 영문자 개수 세기
    while ((ch = fgetc(file)) != EOF) { // 파일 끝까지 읽기
        putchar(ch); // 문자 출력
        if (ch >= 'A' && ch <= 'Z') {
            counts[ch - 'A']++;
            //'A'를 아스키 값으로 변환하면 65~90 이므로 0~25로 맞추기 위해 'A'를 빼줌
            // 그러면 'A'는 0, 'B'는 1, ..., 'Z'는 25번 인덱스에 해당
        }
        else if (ch >= 'a' && ch <= 'z') {
            counts[ch - 'a']++;
            // 대문자와 마찬가지로 97~122이므로 'a'를 빼줌
        }
    }
    printf("\n");

    // 4. 결과 출력
    for (int i = 0; i < 13; i++) {
        printf("%c: %d    ", 'a' + i, counts[i]);
    }
    printf("\n"); // 가독성 위한 줄바꿈
    for (int i = 13; i < 26; i++) {
        printf("%c: %d    ", 'a' + i, counts[i]);
    }

    // 5. 파일 닫기
    fclose(file);
}

