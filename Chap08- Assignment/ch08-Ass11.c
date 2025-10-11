/*
���α׷��� : ch08-ass11.c
�й� : 202010853
�̸� : �ȵ���
��¥ : 2025.09.24
���̵� : �ڡڡ�
���� : ����, ���� ���� �Է¹޾� �Լ��� �̿��� 
���簢���� ���̿� �ѷ� ���ϴ� ���α׷�
���� : ���簢���� ���̿� �ѷ��� ���ϴ� get_rect_info �Լ� ����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void get_rect_info(int* width, int* height);
void input_values();

int main() {
	input_values();
	return 0;
}

// �Լ�1 : ���ο� ���� ���̸� �Է¹ް� get_rect_info �Լ� ȣ���ϴ� �Լ�
void input_values() {
	int width, height;

	printf("����? ");
	scanf("%d", &width);
	printf("����? ");
	scanf("%d", &height);

	get_rect_info(&width, &height); // ���簢���� ���̿� �ѷ��� ���ϴ� �Լ� ȣ��
	return;
}

// �Լ�2 : ���ο� ���� ���̸� �Ű������� �޾� ���簢���� ���̿� �ѷ��� ���ϴ� �Լ�
void get_rect_info(int* width, int* height) {
	int area = (*width) * (*height); // ���� ���
	int perimeter = 2 * ((*width) + (*height)); // �ѷ� ���
	printf("����: %d, �ѷ�: %d\n", area, perimeter);
	return;
}