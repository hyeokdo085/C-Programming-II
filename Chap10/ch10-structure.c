/*
���α׷� �� : ���� �� �ǽ�(����ü, typedef)
�й� : 202010853
�̸� : �ȵ���
��¥ : 2025_09_30
*/

#include <stdio.h>

/*
typedef struct contact {
	char name[50];
	char phone[15];
	int ringtone;
} Contact;

�ش� ������ ���� ������� ����
*/

#include "contact.h"

Contact kim = { 0 };

int main() {
	Contact lee = { "LEE", "010-1234-5678", 1 };
	Contact lee2 = { 0 };
	lee2 = lee;
	//lee2 = { "LEE2", "010-9876-5432", 2 }; ����!
	lee2.ringtone = 2;

	return 0;
}
