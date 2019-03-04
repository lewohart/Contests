// https://www.hackerrank.com/challenges/c-tutorial-basic-data-types
#include  "pch.h"

#include <iostream>
#include <cstdio>
using namespace std;

int basic_data_types_run() {
	int a;
	long b;
	long long c;
	char d;
	float e;
	double f;
	scanf_s("%d %ld %lld %c %f %lf", &a, &b, &c, &d, &e, &f);
	printf("%d\n%ld\n%lld\n%c\n%f\n%lf", a, b, c, d, e, f);
	return 0;
}
