/*
���α׷� �� : ���� 9-1 ���� �迭�� �ʱ�ȭ �� ���
�й� : 202010853
�̸� : �ȵ���
��¥ : 2025_09_24
*/

#include <stdio.h>

void string();

int main(void) {
	string();
	return 0;
}

void string() {
	char str1[10] = { 'a','b','c' };
	char str2[10] = "abc";
	char str3[] = "abc";
	char str4[10] = "very long string"; //���� ����
	int size = sizeof(str1) / sizeof(str1[0]);
	int i;

	printf("str1 = ");
	for (i = 0; i < size; i++) {
		printf("%c ", str1[i]);
	}
	printf("\n");

	printf("str2 = %s\n", str2);
	printf("str3 = ");
	printf(str3);
	printf("\n");

	printf("str4 = %s\n", str4);

	return;
}