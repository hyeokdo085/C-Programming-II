/*
���α׷� �� : ���� �� �ǽ�(������ ����ü)
�й� : 202010853
�̸� : �ȵ���
��¥ : 2025_09_30
*/

#include <stdio.h>

typedef  struct point {
	int x;
	int y;
} Point;

void* swap(Point* pa, Point* pb) {
	if (pa == NULL || pb == NULL) {
		return;
	}
	Point temp = *pa;
	*pa = *pb;
	*pb = temp;

	return;
}

Point mul10(Point pt) { //������Ÿ�� ����
	Point pr = { 0 };
	pr.x *= 10;
	pr.y *= 10;

	return pr;
}

int test_point() {
	Point p1 = { 1,2 };
	Point p2 = { 3,4 };
	Point p3 = { 0 };

	printf("p1(%d,%d), p2(%d,%d) \n", p1.x, p1.y, p2.x, p2.y);
	swap(&p1, &p2);
	printf("p1(%d,%d), p2(%d,%d) \n", p1.x, p1.y, p2.x, p2.y);

	p3 = mul10(p1);
	printf("p3(%d,%d) \n", p3.x, p3.y);
}



int main() {
	test_point();
	return 0;
}