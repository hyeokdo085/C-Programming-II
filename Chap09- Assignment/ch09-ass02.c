/*
���α׷��� : ch09-ass02.c
�й� : 202010853
�̸� : �ȵ���
��¥ : 2025.09.24
���̵� : �ڡ�
���� : ���ڿ� �Է¹޾� ���鹮�� ���� �� ����ϴ� ���α׷�
���� : ���鹮�ڴ� ' ', '\n', '\t', '\f', '\r', '\v' 6����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void remove_space();

int main() {
	remove_space();
	return 0;
}

// �Լ�1 : ���ڿ��� �޾� ���鹮�ڸ� �����ϴ� �Լ�

void remove_space() {
	char str[100] = "";
	char result[100] = "";
	printf("���ڿ�? ");
	gets_s(str, sizeof(str));

	int index = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (!isspace(str[i])) {
			result[index++] = str[i];
		}
	}
	result[index] = '\0'; // ���ڿ� ���� ���� �߰�
	printf("���� ���� ���� ��: %s\n", result);
}
