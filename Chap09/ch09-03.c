/*
���α׷� �� : ���� 9-3 ���ڿ��� ��ȯ
�й� : 202010853
�̸� : �ȵ���
��¥ : 2025_09_24
*/

#define _CRT_SECURE_NO_WARNINGS //��� ��
#include <stdio.h>
#include <string.h>
#define SIZE 32

void swap_str(void);

int main(void) {
	swap_str();
	return 0;
}

void swap_str(void) {
	char str1[SIZE] = "";
	char str2[SIZE] = "";
	char temp[SIZE];

	printf("�� ���� ���ڿ�? ");
	scanf("%s %s", str1, str2);
	printf("str1 = %s, str2 = %s\n", str1, str2);

	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
	printf("str1 = %s, str2 = %s\n", str1, str2);
	return;
}