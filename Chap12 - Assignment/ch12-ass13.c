/*
프로그램명 : ch12-ass13.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.11.09
내용 : 정수의 개수 N을 입력받고, 임의의 정수 N개 생성하여 텍스트 파일과 이진 파일로 각각 생성하는 프로그램
조건 :
1. N 입력받아 int가 N개 들어갈 수 있는 동적 메모리 할당
2. 이진 파일 생성시, N을 먼저 저장 후 배열 내용 저장
3. 저장된 파일을 문서 편집기로 열어 비교해볼 것
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // 난수 생성을 위한 헤더 파일

void IntToFile();

// 함수1. 메인 함수
int main() {
    IntToFile();
    return 0;
}

// 함수2. 정수 N개를 생성하여 txt파일과 dat 파일로 저장하는 함수
void IntToFile() {
    int N; // 정수 N
    int* arr = NULL; // 정수 배열 포인터
    FILE* txtFile = NULL;
    FILE* datFile = NULL;

    // 1. 정수 N 입력받기
    printf("정수의 개수? ");
    scanf("%d", &N);

    // 2. 동적 메모리 할당
    arr = (int*)malloc(N * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        return;
    }

    // 3. 난수 생성기 초기화
    srand((unsigned int)time(NULL));

    // 4. N개의 임의의 정수 생성
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 10; // 0~9 사이의 난수 생성
    }

    // 5. txt 파일 생성 및 저장
    char Filename[20];
    char txtFilename[25];
    printf("파일명? ");
    scanf("%s", Filename);
    sprintf(txtFilename, "%s.txt", Filename); // txt 파일 이름 생성

    txtFile = fopen(txtFilename, "w");
    if (txtFile == NULL) {
        fprintf(stderr, "txt 파일을 열 수 없습니다\n");
        free(arr);
        return;
    }
    for (int i = 0; i < N; i++) {
        fprintf(txtFile, "%d\n", arr[i]);
    }
    fclose(txtFile);

    // 6. dat 파일 생성 및 저장
    char datFilename[25];
    sprintf(datFilename, "%s.dat", Filename); // binary 파일 이름 생성
    datFile = fopen(datFilename, "wb");
    if (datFile == NULL) {
        fprintf(stderr, "binary 파일을 열 수 없습니다\n");
        free(arr);
        return;
    }
    fwrite(&N, sizeof(int), 1, datFile); // N 저장
    fwrite(arr, sizeof(int), N, datFile); // 배열 내용 저장
    fclose(datFile);
    free(arr); // 동적 메모리 해제
    printf("%s와 %s를 생성했습니다.\n", txtFilename, datFilename);
}