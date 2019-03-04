// https://www.hackerrank.com/challenges/c-tutorial-functions/
#include "pch.h"

#include <iostream>
#include <cstdio>
using namespace std;

int max_of_four(int a, int b, int c, int d)
{
	auto mx = [](int x, int y) { return x > y ? x : y; };
	return mx(a, mx(b, mx(c, d)));
}

int functions_run() {
	int a, b, c, d;
	scanf_s("%d %d %d %d", &a, &b, &c, &d);
	int ans = max_of_four(a, b, c, d);
	printf("%d", ans);

	return 0;
}

