/*
���α׷� �� : ���� 9-8 ���ڿ��� �����
�й� : 202010853
�̸� : �ȵ���
��¥ : 2025_09_24
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void io_str(void);

int main(void) {
	io_str();
	return 0;
}

void io_str(void) {
	char in_str[128];
	char out_str[128];
	int hour = 12, min = 30, sec = 45;

	printf("���ڿ�? ");
	gets_s(in_str, sizeof(in_str)); //��ĭ ���� ���ڿ� �Է�
	puts(in_str); //���ڿ��� �ٹٲ� ���� �Բ� ���
	sprintf(out_str, "%02d:%02d:%02d", hour, min, sec); //���ڿ� ����
	puts(out_str);
	return;
}