// https://www.hackerrank.com/contests/projecteuler/challenges/euler002
#include "pch.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


unsigned long long int fibonacci_even_acc(const unsigned long long int n) {
	unsigned long long int a = 1l, b = 1l, acc = 0l;

	if (n < 4)
		return 0;

	for (int i = 3; i <= n; i++) {
		unsigned long long int c = a + b;
		a = b;
		b = c;

		if (b > n)
			break;

		if (!(b & 0x1))
			acc += b;
	}

	return acc;
}

int euler002() {
	long long int n, v;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> v;
		cout << fibonacci_even_acc(v) << endl;
	}

	return 0;
}
