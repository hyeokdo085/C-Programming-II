/*
���α׷��� : ch09-ass05.c
�й� : 202010853
�̸� : �ȵ���
��¥ : 2025.10.02
���̵� : �ڡ�
���� : ��ҹ��� ���� ���� ���ڿ� ���ϴ� ���α׷�
���� : 
1. strcmp_ic �Լ� �ۼ�
2. lhs>rhs = ���, lhs<rhs = ����, lhs==rhs = 0 ��ȯ
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

// �Լ�1 : ���ڿ��� �Է¹ް� strcmp_ic �Լ� ȣ���ϴ� �Լ�
void input_str() {
	char str1[100] = "";
	char str2[100] = "";
	printf("ù ��° ���ڿ� ? ");
	gets_s(str1, sizeof(str1));
	printf("�� ��° ���ڿ� ? ");
	gets_s(str2, sizeof(str2));

	int result = strcmp_ic(str1, str2);
	
	printf("%s�� %s�� ", str1, str2);
	output_result(result);
	return;
}

// �Լ�2 : �� ���ڿ��� ��ҹ��� ���� ���� ���ϴ� �Լ�
int strcmp_ic(const char* lhs, const char* rhs) {
	while (*lhs && *rhs) {
		char c1 = tolower((unsigned char)*lhs);
		char c2 = tolower((unsigned char)*rhs);

		if (c1 != c2) {
			return c1 - c2; // ���� ��ȯ
		}

		lhs++;
		rhs++;
	}
	return *lhs - *rhs; // ���� ���� ��ȯ
}

// �Լ�3 : �� ����� ���� ����ϴ� �Լ�
void output_result(int result) {
	if (result == 0) {
		printf("�����ϴ�.\n");
	}
	else {
		printf("�ٸ��ϴ�.\n");
	}
}