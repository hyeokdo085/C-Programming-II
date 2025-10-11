/*
프로그램명 : ch09-ass05.c
학번 : 202010853
이름 : 안도혁
날짜 : 2025.10.02
난이도 : ★★
내용 : 대소문자 구별 없이 문자열 비교하는 프로그램
조건 : 
1. strcmp_ic 함수 작성
2. lhs>rhs = 양수, lhs<rhs = 음수, lhs==rhs = 0 반환
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int strcmp_ic(const char* lhs, const char* rhs);
void input_str();
void output_result(int result);

int main() {
	input_str();
	return 0;
}

// 함수1 : 문자열을 입력받고 strcmp_ic 함수 호출하는 함수
void input_str() {
	char str1[100] = "";
	char str2[100] = "";
	printf("첫 번째 문자열 ? ");
	gets_s(str1, sizeof(str1));
	printf("두 번째 문자열 ? ");
	gets_s(str2, sizeof(str2));

	int result = strcmp_ic(str1, str2);
	
	printf("%s와 %s가 ", str1, str2);
	output_result(result);
	return;
}

// 함수2 : 두 문자열을 대소문자 구별 없이 비교하는 함수
int strcmp_ic(const char* lhs, const char* rhs) {
	while (*lhs && *rhs) {
		char c1 = tolower((unsigned char)*lhs);
		char c2 = tolower((unsigned char)*rhs);

		if (c1 != c2) {
			return c1 - c2; // 차이 반환
		}

		lhs++;
		rhs++;
	}
	return *lhs - *rhs; // 길이 차이 반환
}

// 함수3 : 비교 결과에 따라 출력하는 함수
void output_result(int result) {
	if (result == 0) {
		printf("같습니다.\n");
	}
	else {
		printf("다릅니다.\n");
	}
}