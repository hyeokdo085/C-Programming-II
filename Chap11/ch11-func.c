/*
���α׷� �� : ���� �� �ǽ�(�ܺ� ����)
�й� : 202010853
�̸� : �ȵ���
��¥ : 2025_10_14
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int inc_id(int n);

// �Լ���: get_id()
// ���: 1001������ ���ʷ� ������ ��ȣ�� �����ϸ鼭 ��ȯ�ϴ� ���
// �Է�: ����
// ���: 1001���� �����ؼ� 1�� �����ϴ� ������ ��
// ����: ����
int get_id() {
	static int last_id = 1000;

	last_id = inc_id(last_id); //1 ����

	return ++last_id; //���� �� ��� (���� 2 ����)
}

static int inc_id(int n) {
	return n + 1;
}