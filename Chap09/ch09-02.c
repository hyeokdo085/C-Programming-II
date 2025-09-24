/*
프로그램 명 : 예제 9-2 strlen 함수 사용 예
학번 : 202010853
이름 : 안도혁
날짜 : 2025_09_24
*/

#include <stdio.h>
#include <string.h> // 문자열 처리 함수 사용 시 포함

void strlen_ex();

int main(void) {
	strlen_ex();
	return 0;
}

void strlen_ex() {
	char s1[] = "hello";
	char s2[] = ""; //널 문자열
	int len = 0;

	printf("s1의 길이: %d\n", strlen(s1)); //널문제 제외
	printf("s2의 길이: %d\n", strlen(s2)); //널문자 길이
	printf("s2의 길이: %d\n", strlen("bye bye")); //문자열 리터럴 길이

	printf("s1의 크기: %d\n", sizeof(s1)); //널문자 포함
	len = strlen(s1);
	if (len > 0)
		s1[len - 1] = '\0'; //마지막 글자 제거
	printf("s1 = %s\n", s1);

	return;
}