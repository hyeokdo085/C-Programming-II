/*
프로그램 명 : 수업 중 실습(포인터)
학번 : 202010853
이름 : 안도혁
날짜 : 2025.09.16
*/

#include <stdio.h>

int main() {
	int* pi;
	double* pd;
	printf("pi의 크기: %d\n", sizeof(pi));
	printf("pd의 크기: %d\n", sizeof(pd));
	// 포인터 주소의 크기는 같다(32bit=4B, 64bit=8B)

	int* pj = 0;
	printf("pi의 값: %p\n", pj);
	//어떤 주소로 초기화할지 모르면 0 or NULL로 초기화
	//0번지는 없는 주소이기 때문(=이후 에러 확인 용이)

	int a = 10;
	int* pa = &a; // & : 주소 연산자
	printf("%d\n", *pa);
	// * : 간접 참조 연산자(포인터가 가리키는 변수 값)
	*pa = 20; // * 이용하여 변수 값 역참조 가능
	printf("%d\n", *pa);

	//함수의 경우, 함수 이름이 함수의 주소를 의미

	//const 포인터 경우, const 위치에 따라 의미 다름
	const int* p1; // 읽기 전용
	int* const p2; //특정 변수 전용 = 주소 변경 불가
	//머리 아파서 알고만 있기

	int* p = NULL;
	int i;
	p = &i;
	printf("%p\n", p);
	p++;
	printf("%p\n", p);
	//포인터 증감시, 자료형 크기만큼 증감

	int arr[5] = { 1,2,3,4,5 }; //*(arr+5) = arr[5]
	int* pp = &arr[0]; //int* pp = arr; 도 가능
	//배열명은 배열의 첫 번째 요소의 주소기 때문
	for (int j = 0; j < 5; j++) {
		printf("%d ", *(pp + j)); //pp[j] 도 가능
	}
	//arr[0]의 주소부터 하나씩 밀림



	return 0;
}