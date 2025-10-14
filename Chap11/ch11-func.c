/*
프로그램 명 : 수업 중 실습(외부 변수)
학번 : 202010853
이름 : 안도혁
날짜 : 2025_10_14
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int inc_id(int n);

// 함수명: get_id()
// 기능: 1001번부터 차례로 유일한 번호를 증가하면서 반환하는 기능
// 입력: 없음
// 출력: 1001부터 시작해서 1씩 증가하는 유일한 값
// 오류: 없음
int get_id() {
	static int last_id = 1000;

	last_id = inc_id(last_id); //1 증가

	return ++last_id; //증가 후 출력 (총합 2 증가)
}

static int inc_id(int n) {
	return n + 1;
}