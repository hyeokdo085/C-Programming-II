/*
���α׷��� : ch10-ass11.c
�й� : 202010853
�̸� : �ȵ���
��¥ : 2025.10.01
���̵� : �ڡڡ�
���� : ī�� �ֹ� ó�� ���α׷�
���� :
1. PRODUCT ����ü �迭 (ũ�� 5) ���� �� �ʱ�ȭ
2. ��ǰ��, ���� �Է� / �����ݾ�, ��ǰ ��� ���
3. ��ǰ ��� �ֹ� ������ŭ ����
4. ��� ����, ��ǰ ���� = �����޽��� ���
5. ��ǰ�� "." �Է½� ��� ��� ���
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct product {
	char name[20]; // ��ǰ��
	int price;     // ����
	int stock;     // ���
} PRODUCT;

// PRODUCT ����ü �迭 (ũ�� 5) ���� �� �ʱ�ȭ
PRODUCT coffee[5] = {
	{"�Ƹ޸�ī��", 4000, 10},
	{"ī���", 4500, 10},
	{"�÷�ȭ��Ʈ", 5000, 10},
	{"�Ƽ���", 4500, 10},
	{"�ڸ���Ϻ�Ƽ", 5500, 10}
};

void cafe_manager(char name[], int stock);
void order_coffee();

int main() {
	order_coffee();
	return 0;
}

// �Լ�1 : ��ǰ��� ������ �Է¹ް� cafe_manager �Լ� ȣ���ϴ� �Լ�
void order_coffee() {
	while (1) {
		char name[20] = "";
		int stock;

		printf("��ǰ��? ");
		scanf("%s", name);
		if (strcmp(name, ".") == 0) { // ��ǰ���� "."�̸� ��� ��� ���
			for (int i = 0; i < 5; i++) {
				printf("[%s %d�� ���:%d]\n", coffee[i].name, coffee[i].price, coffee[i].stock);
			}
			continue; // �ٽ� ��ǰ�� �Է¹ޱ�
		}

		printf("����? ");
		scanf("%d", &stock);

		cafe_manager(name, stock); // ī�� �ֹ� ó�� �Լ� ȣ��
	}
	return;
}

// �Լ�2 : ��ǰ��� ������ �Ű������� �޾� �ֹ� ó���ϴ� �Լ�
void cafe_manager(char name[], int stock) {
	int found = 0; // ��ǰ ���� ���� Ȯ�� ����

	for (int i = 0; i < 5; i++) {
		if (strcmp(coffee[i].name, name) == 0) { // ��ǰ���� ��ġ�ϴ��� Ȯ��
			found = 1; // ��ǰ �����ϸ�?
			if (coffee[i].stock >= stock) { // ��� ����ϸ�?
				coffee[i].stock -= stock; // ��� ����
				int total_price = coffee[i].price * stock; // ���� �ݾ� ���
				printf("���� �ݾ�: %d�� ", total_price);
				printf("%s ���: %d\n", name, coffee[i].stock);
			}
			else {
				printf("��� �����մϴ�.\n"); // ��� ���� �޽��� ���
			}
			break;
		}
	}

	if (found == 0) {
		printf("�ش� ��ǰ�� �����ϴ�.\n"); // ��ǰ ���� �޽��� ���
	}
	return;
}