/*
���α׷��� : ch09-ass04.c
�й� : 202010853
�̸� : �ȵ���
��¥ : 2025.10.02
���̵� : ��
���� : ���ڿ� �Է¹޾� �������� ����ϴ� ���α׷�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse_string();

int main() {
	reverse_string();
	return 0;
}

// �Լ�1 : ���ڿ��� �޾� �������� ����ϴ� �Լ�
void reverse_string() {
	char str[100] = "";
	printf("���ڿ�? ");
	gets_s(str, sizeof(str));
	int len = strlen(str);

	printf("�������� �� ���ڿ�: ");
	for (int i = len - 1; i >= 0; i--) {
		printf("%c", str[i]);
	}
	printf("\n");
}