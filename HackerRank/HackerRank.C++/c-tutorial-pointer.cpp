// https://www.hackerrank.com/challenges/c-tutorial-pointer/
#include "pch.h"

#include <stdio.h>
#include <stdlib.h>

void update(int *a, int *b) {
	int abs_dif = abs(*a - *b);
	*a = *a + *b;
	*b = abs_dif;
}

int pointer_run() {
	int a, b;
	int *pa = &a, *pb = &b;

	scanf_s("%d %d", &a, &b);
	update(pa, pb);
	printf("%d\n%d", a, b);

	return 0;
}
