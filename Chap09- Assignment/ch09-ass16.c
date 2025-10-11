/*
���α׷��� : ch09-ass16.c
�й� : 202010853
�̸� : �ȵ���
��¥ : 2025.10.02
���̵� : �ڡڡ�
���� : ���ͳ� ����Ʈ�� �α��� �ϴ� ���α׷�
���� : 
1. ��ϵ� ����� 5��
2. ���̵� ����X or �н����� Ʋ�� -> �����޼��� ��� �� ���Է�
3. 3���� ��õ� �Ŀ��� ���н� �α��� ���� �����޼��� ���
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct account {
	char ID[20];
	char PW[20];
} ACC;

ACC users[5] = { // ACC ����ü �迭 �ʱ�ȭ
		{"sugar", "dna!awesome"},
		{"parkjimin", "@BestOfMe@"},
		{"hyeok_085", "abc1234"},
		{"sang629", "def5678"},
		{"lee_guen", "@@program2"}
};

int check_login(char id[], char pw[]);
void input_login();
void output_login(int result);

int main() {
	input_login();
	return 0;
}

// �Լ�1 : ���̵�� �н����带 �Է¹ް� check_login �Լ� ȣ���ϴ� �Լ�
void input_login() {
	char id[20] = "";
	char pw[20] = "";
	
	for (int attempts = 0; attempts < 3; attempts++) {
		printf("ID? ");
		scanf("%s", id);
		printf("PW? ");
		scanf("%s", pw);
		output_login(check_login(id, pw));
		if (check_login(id, pw) == 1) {
			break; // �α��� ���� �� �ݺ��� ����
		}
		if (attempts == 2) { // 3��° �õ� �Ŀ��� ���� ��
			printf("�α��� 3ȸ ����!\n");
		}
	}
	return;
}

// �Լ�2 : ���̵�� �н����带 ���ϴ� �Լ�
int check_login(char id[], char pw[]) {
	for (int i = 0; i < 5; i++) {
		if (strcmp(users[i].ID, id) == 0) { // ���̵� ��ġ�ϴ��� Ȯ��
			if (strcmp(users[i].PW, pw) == 0) { // �н����� ��
				return 1; // �α��� ����
			}
			else {
				return -1; // �н����� Ʋ��
			}
		}
	}
	return 0; // ���̵� ����
}

// �Լ�3 : �α��� ����� ���� ����ϴ� �Լ�
void output_login(int result) {
	if (result == 1) {
		printf("�α��� ����!\n\n");
	}
	else if (result == -1) {
		printf("�н����尡 Ʋ�Ƚ��ϴ�.\n\n");
	}
	else {
		printf("�ش� id�� �����ϴ�.\n\n");
	}
	return;
}