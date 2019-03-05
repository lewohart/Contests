// https://www.hackerrank.com/contests/projecteuler/challenges/euler001
#include "pch.h"

#include <iostream>
using namespace std;

long long sum_of_multiples_of_a_and_b_below_n(unsigned int a, unsigned int b, long n) {
	auto sum_mul = [](long long x) { return (x * (x + 1)) >> 1; };
	auto m = a * b;
	long long sa = sum_mul((n - 1) / a);
	long long sb = sum_mul((n - 1) / b);
	long long sm = sum_mul((n - 1) / m);
	return (a * sa) + (b * sb) - (m * sm);
}

int euler001() {
	int n, v;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> v;
		cout << sum_of_multiples_of_a_and_b_below_n(3, 5, v) << endl;
	}
	return 0;
}

