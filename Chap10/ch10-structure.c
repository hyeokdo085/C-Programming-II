/*
프로그램 명 : 수업 중 실습(구조체, typedef)
학번 : 202010853
이름 : 안도혁
날짜 : 2025_09_30
*/

#include <stdio.h>

/*
typedef struct contact {
	char name[50];
	char phone[15];
	int ringtone;
} Contact;

해당 내용을 갖는 헤더파일 생성
*/

#include "contact.h"

Contact kim = { 0 };

int main() {
	Contact lee = { "LEE", "010-1234-5678", 1 };
	Contact lee2 = { 0 };
	lee2 = lee;
	//lee2 = { "LEE2", "010-9876-5432", 2 }; 오류!
	lee2.ringtone = 2;

	return 0;
}
