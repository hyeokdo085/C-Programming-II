/*
���α׷��� : ch08-ass05.c
�й� : 202010853
�̸� : �ȵ���
��¥ : 2025.09.24
���̵� : �ڡ�
���� : 
ù �װ� ������ ũ�Ⱑ 10�� ������ �迭�� ���� �������� ���ϴ� ���α׷�
���� : 
1. ù ���� ���� �迭 0�� ���ҿ� �־� ����
2. �迭�� �迭�� ũ��, ������ �Ű������� �޾� ���������� �迭�� ä���
arith_seq �Լ� ����
3. �����Ϳ� ���� ���� ���
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void arith_seq(int* arr, int size, int diff);
void input_values();

int main() {
	input_values();
	return 0;
}

// �Լ�1 : ù �װ� ������ �Է¹ް� arith_seq �Լ� ȣ���ϴ� �Լ�
void input_values() {
	int arr[10] = { 0 }; // ũ�Ⱑ 10�� int�� �迭 ���� �� �ʱ�ȭ
	int first, diff;  

	printf("ù ��° ��? ");
	scanf("%d", &first);
	arr[0] = first; // ù ���� �迭 0�� ���ҿ� ����

	printf("����? ");
	scanf("%d", &diff);

	arith_seq(arr, 10, diff); // ���������� ���ϴ� �Լ� ȣ��

	printf("��������: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]); // �������� ���
	}
	return;
}

// �Լ�2 : �迭�� �迭�� ũ��, ������ �Ű������� �޾� 
// ���������� �迭�� ä��� �Լ�
void arith_seq(int* arr, int size, int diff) {
	for (int i = 1; i < size; i++) {
		*(arr + i) = *((arr + i) - 1) + diff; // ������ ������ �̿��� �������� ���
	}
	return;
}