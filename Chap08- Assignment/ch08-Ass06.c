/*
���α׷��� : ch08-ass06.c
�й� : 202010853
�̸� : �ȵ���
��¥ : 2025.09.24
���̵� : �ڡ�
���� : 
ũ�� 10�� int �迭, ���ϴ� �ʱⰪ���� ä��, 
get_min_max �Լ��� �ִ񰪰� �ּڰ� ���ϴ� ���α׷�
���� : 
������ �迭�� ���� �迭�� ���� �� 
�ִ񰪰� �ּڰ� ã�� get_min_max �Լ� ����
*/

#include <stdio.h>

void get_min_max(int* arr);
void input_values();

int main() {
	input_values();
	return 0;
}

// �Լ�1 : �迭�� ��� ���Ҹ� �����ϰ� get_min_max �Լ� ȣ���ϴ� �Լ�
void input_values() {
	int arr[10] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };

	printf("�迭: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]); // �迭 ���� ���
	}

	get_min_max(arr); // �ִ񰪰� �ּڰ��� ���ϴ� �Լ� ȣ��
	return;
}

// �Լ�2 : �迭�� ���� �� �ִ񰪰� �ּڰ��� ã�� �Լ�
void get_min_max(int* arr) {
	int min = *arr; // �迭�� ù ��° ���ҷ� �ʱ�ȭ
	int max = *arr; // �迭�� ù ��° ���ҷ� �ʱ�ȭ
	for (int i = 1; i < 10; i++) {
		if (*(arr + i) > max) {
			max = *(arr + i); // �ִ� ����
		}
		if (*(arr + i) < min) {
			min = *(arr + i); // �ּڰ� ����
		}
	}
	printf("\n�ִ�: %d\n", max);
	printf("�ּڰ�: %d\n", min);
	return;
}