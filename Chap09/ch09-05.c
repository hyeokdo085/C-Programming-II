/*
���α׷� �� : ���� 9-5 ���ڿ��� ����
�й� : 202010853
�̸� : �ȵ���
��¥ : 2025_09_24
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void cat_str(void);

int main(void) {
	cat_str();
	return 0;
}

void cat_str(void) {
	char sentence[100] = "";
	char word[20];

	do {
		printf("�ܾ�? ");
		scanf("%s", word);
		strcat(sentence, word); //���ڿ� ����
		strcat(sentence, " "); //�ܾ� ���� ���� ���� �߰�
	} while (strcmp(word, ".") != 0); //��ħǥ �Է� ������ �ݺ�

	printf("%s\n", sentence);

	return;
}