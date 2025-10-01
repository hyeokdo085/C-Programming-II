/*
프로그램 명 : 수업 중 실습(문자열)
학번 : 202010853
이름 : 안도혁
날짜 : 2025_09_24
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int test_strcpy();
int str_swap(char* str1, char* str2, int size);
int test_string();

int main() {
	//printf("Hello, World!\n");
	//test_strlen();
	//test_strcpy();
	test_string();

	return 0;
}

#define SIZE 128
#define MYCONTACT "mycontact.txt"
int test_string() {
	char in_str[SIZE] = "";
	char out_str[SIZE] = "";
	char* pContext = NULL;

	//printf("Enter string: ");

	//gets_s(in_str, sizeof(in_str));
	//fgets(in_str, sizeof(in_str), stdin); // stdin = 키보드파일
	// 파일에서 읽기 : "파일 주소.txt"
	//FILE* mycontact = fopen("C:/Users/희진/Desktop/mycontact.txt", "r");
	FILE* mycontact = fopen("mycontact.txt", "r");
	if (mycontact == NULL) {
		printf("Fail to open file\n");
		return -1;
	}

	while (fgets(in_str, sizeof(in_str), mycontact) != NULL) {
		fgets(in_str, sizeof(in_str), mycontact);
		puts(in_str);

		char* ptoken = strtok_s(in_str, "|", &pContext);
		if (ptoken != NULL) puts(ptoken);

		ptoken = strtok_s(NULL, "|", &pContext);
		if (ptoken != NULL) puts(ptoken);

		ptoken = strtok_s(NULL, "|", &pContext);
		if (ptoken != NULL) puts(ptoken);
	}
	fclose(mycontact);

}

#define STR_SIZE 128
int test_strcpy() {
	char str1[STR_SIZE] = ""; //널 문자열
	char str2[STR_SIZE] = "";

	printf("두 문자열 입력: ");
	scanf_s("%s %s", str1, STR_SIZE, str2, STR_SIZE);
	printf("%s %s 가 입력되었습니다\n", str1, str2);

	str_swap(str1, str2, STR_SIZE);

	printf("%s %s 가 교환되었나요?\n", str1, str2);

	return 0;
}

// 교환된 두 문자열 길이의 합 반환
int str_swap(char* str1, char* str2, int size) {
	int result = 0;
	if (size <= 0 || str1 == NULL || str2 == NULL) {
		return 0;
	}

	char* temp = NULL;
	//void * malloc(int size);
	temp = (char*)malloc(sizeof(char) * size);
	//temp[0] = 'A'; // 적어도 0이 아니게 초기화.
	//char temp[size];

	if (temp == NULL) {
		printf("메모리 할당 실패\n");
		return 0;
	}

	/*
	strncpy(temp, str1, size);
	strncpy(str1, str2, size);
	strncpy(str2, temp, size);
	*/

	strcpy_s(temp, size, str1);
	strcpy_s(str1, size, str2);
	strcpy_s(str2, size, temp);

	result = strlen(str1) + strlen(str2);

	free(temp);


	return result;
}

int test_strlen() {
	char str1[] = "hello";
	char name[] = "안도혁";

	size_t len = strlen(str1);

	//printf("%s의 길이 : %d\n", str1, strlen(str1));
	printf("%s의 길이 : %d\n", str1, len);

	len = strlen("안녕하세요");

	printf("%s의 길이 : %d\n", name, strlen(name));

	len = strlen("");

	printf("%s의 길이 : %d\n", "", len);

}