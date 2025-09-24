/*
프로그램 명 : 예제 9-5 문자열의 연결
학번 : 202010853
이름 : 안도혁
날짜 : 2025_09_24
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void cat_str(void);

int main(void) {
	cat_str();
	return 0;
}

void cat_str(void) {
	char sentence[100] = "";
	char word[20];

	do {
		printf("단어? ");
		scanf("%s", word);
		strcat(sentence, word); //문자열 연결
		strcat(sentence, " "); //단어 구분 위해 공백 추가
	} while (strcmp(word, ".") != 0); //마침표 입력 전까지 반복

	printf("%s\n", sentence);

	return;
}