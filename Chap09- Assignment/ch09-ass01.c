/*
���α׷��� : ch09-ass01.c
�й� : 202010853
�̸� : �ȵ���
��¥ : 2025.09.24
���̵� : ��
���� : �� �� ���ڿ� �Է¹޾� ���鹮�� ���� ���� ���α׷�
���� : ���鹮�ڴ� ' ', '\n', '\t', '\f', '\r', '\v' 6����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_space();


int main() {
	int count = count_space();
	printf("���鹮�� ����: %d\n", count);
	return 0;
}


// �Լ�1 : ���ڿ����� ���鹮�� ������ ���� �Լ�
int count_space() {
	int count = 0;
	char str[100] = "";
	printf("���ڿ�? ");
	gets_s(str, sizeof(str));

	for (int i = 0; i < strlen(str); i++) {
		if (isspace(str[i])) {
			count++;
		}
	}
	return count;
}