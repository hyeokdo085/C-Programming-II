/*
���α׷��� : ch09-ass17.c
�й� : 202010853
�̸� : �ȵ���
��¥ : 2025.10.02
���̵� : �ڡڡ�
���� : �Է� ���� �뷡 ���� �ִ� 20�� ���� ���� ���α׷�
���� :
1. �뷡 ���� �ִ� 40����
2. �뷡 ���� �߰�, �뷡 ���� ����, �뷡 ��� ��� ���
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct song {
	char title[40];
} SONG;

SONG song[20]; // SONG ����ü �迭 ���� �� ���������� ���

int print_menu();
void add_song();
void edit_song();
void list_songs();


int main() {
	while (1) {
		if (print_menu() == 0) {
			break;
		}
		else {
			continue;
		}
	}
	return 0;
}

// �Լ�1 : �޴��� ����ϰ� ������ ����� �����ϴ� �Լ�	
int print_menu() {
	int choice;
	printf("[ 0.���� 1.�߰� 2.���� 3.��� ] ����? ");
	scanf("%d", &choice);
	switch (choice) {
	case 0:
		return 0;
	case 1:
		add_song();
		break;
	case 2:
		edit_song();
		break;
	case 3:
		list_songs();
		break;
	default:
		printf("�߸��� �����Դϴ�.\n");
		break;
	}
	return 1;
}

// �Լ�2 : �뷡 ������ �߰��ϴ� �Լ�
void add_song() {
	for (int i = 0; i < 20; i++) {
		if (strcmp(song[i].title, "\0") == 0) { // �� �ڸ� ã��
			printf("�뷡 ����? ");
			scanf(" %[^\n]", song[i].title); // ���� ���� �Է�
			return;
		}
	}
	printf("�뷡 ������ ���� á���ϴ�.\n");
}

// �Լ�3 : �뷡 ������ �����ϴ� �Լ�
void edit_song() {
	char title_temp[40];
	printf("ã�� �뷡 ����? ");
	scanf(" %[^\n]", title_temp); // ���� ���� �Է�
	for (int i = 0; i < 20; i++) {
		if (strcmp(song[i].title, title_temp) == 0) { // �뷡 ���� ã��
			printf("������ ����? ");
			scanf(" %[^\n]", song[i].title); // ���� ���� �Է�
			return;
		}
	}
	printf("�뷡 ������ ã�� �� �����ϴ�.\n");
	return;
}

// �Լ�4 : �뷡 ���� ����� ����ϴ� �Լ�
void list_songs() {
	printf("<< �뷡 ��� >>\n");
	for (int i = 0; i < 20; i++) {
		if (strcmp(song[i].title, "\0") != 0) { // �� �ڸ� ���� ���
			printf("%s\n", song[i].title);
		}
	}
	return;
}