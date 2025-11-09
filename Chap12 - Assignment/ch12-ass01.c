/*
프로그램명 : ch12-ass01.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.11.09
내용 : txt파일의 이름을 입력받아 파일 내용을 라인번호화 함께 출력하는 프로그램
조건 :
1. -
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void FIOwLineNum();

// 함수1 : 메인함수
int main() {
	FIOwLineNum();
	return 0;
}

// 함수2 : txt파일의 내용을 라인번호와 함께 출력하는 함수
void FIOwLineNum() {
	char filename[100]; // 파일 이름 저장 배열
	FILE* file = NULL; // 파일 포인터 초기화
	char ch;           // 문자 저장 변수
	int lineNum = 1;   // 라인 번호 초기화

	// 1. 파일 이름 입력받기
	printf("파일명? ");
	scanf("%s", filename);

	// 2. 파일 열기
	file = fopen(filename, "r"); // 읽기 모드로 파일 열기
	if (file == NULL) { // 예외 처리
		fprintf(stderr, "파일을 열 수 없습니다\n");
		return;
	}

	// 3. 파일 내용 읽고 라인번호와 함께 출력하기
	printf("1: "); // 첫 번째 라인 번호 출력
	while ((ch = fgetc(file)) != EOF) { // 파일 끝까지 읽기
		putchar(ch); // 문자 출력
		if (ch == '\n') {
			lineNum++;
			printf("%d: ", lineNum); // 다음 라인 번호 출력
		}
	}

	// 4. 파일 닫기
	fclose(file);
}