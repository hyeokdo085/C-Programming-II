/*
���α׷��� : ch08-ass12.c
�й� : 202010853
�̸� : �ȵ���
��¥ : 2025.09.24
���̵� : �ڡڡ�
���� : ������ �迭�� Ű ���� �Ű������� ���޹޾� �迭���� Ű ���� ã�� 
�ε����� �迭�� �����ؼ� �����ϴ� �Լ� ���α׷�
���� : �� �Լ��� ã�� �׸��� ������ ����, �׸� ã�� �� ������ 0 ����
���� : 12�� 2�� ã���� 2�� ����, ã�� �׸��� �ε����� �ε��� �迭�� ����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const int arr[10] = { 12, 45, 62, 12, 99, 83, 23, 12, 72, 37 }; // ũ�Ⱑ 10�� int�� �迭 ���� �� �ʱ�ȭ

int find_key_indices(int* found_index, int key);
void input_values();

int main() {
	input_values();
	return 0;
}

// �Լ�1 : �迭�� Ű ���� �Է¹ް� find_key_indices �Լ� ȣ���ϴ� �Լ�
void input_values() {
	int key;
	int found_index[10] = { -1 }; // ã�� �ε����� ������ �迭, �ʱⰪ -1�� ����

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]); // �迭 ���� ���
	}
	printf("\n");

	printf("ã�� ��? ");
	scanf("%d", &key);

	int count = find_key_indices(found_index, key); // Ű ���� ã�� �Լ� ȣ��

	if (count > 0) {
		printf("ã�� �׸��� %d���Դϴ�.\n", count);
		printf("ã�� �ε���: ");
		for (int i = 0; i < count; i++) {
			printf("%d ", found_index[i]); // ã�� �ε��� ���
		}
		printf("\n");
	}
	else {
		printf("%d�� �����ϴ�.\n", key);
	}
	return;
}

// �Լ�2 : �迭�� Ű ���� �Ű������� �޾� Ű ���� ã�� �ε����� �迭�� �����ϴ� �Լ�
int find_key_indices(int* found_index, int key) {
	int count = 0; // ã�� �׸��� ����
	for (int i = 0; i < 10; i++) {
		if (arr[i] == key) {
			found_index[count++] = i; // ã�� �ε����� �迭�� �����ϰ� ���� ����
		}
	}
	return count; // ã�� �׸��� ���� ����
}