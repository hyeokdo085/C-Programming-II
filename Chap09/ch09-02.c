/*
���α׷� �� : ���� 9-2 strlen �Լ� ��� ��
�й� : 202010853
�̸� : �ȵ���
��¥ : 2025_09_24
*/

#include <stdio.h>
#include <string.h> // ���ڿ� ó�� �Լ� ��� �� ����

void strlen_ex();

int main(void) {
	strlen_ex();
	return 0;
}

void strlen_ex() {
	char s1[] = "hello";
	char s2[] = ""; //�� ���ڿ�
	int len = 0;

	printf("s1�� ����: %d\n", strlen(s1)); //�ι��� ����
	printf("s2�� ����: %d\n", strlen(s2)); //�ι��� ����
	printf("s2�� ����: %d\n", strlen("bye bye")); //���ڿ� ���ͷ� ����

	printf("s1�� ũ��: %d\n", sizeof(s1)); //�ι��� ����
	len = strlen(s1);
	if (len > 0)
		s1[len - 1] = '\0'; //������ ���� ����
	printf("s1 = %s\n", s1);

	return;
}