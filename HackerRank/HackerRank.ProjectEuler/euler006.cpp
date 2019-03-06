// https://www.hackerrank.com/contests/projecteuler/challenges/euler006
#include "pch.h"

#include <cmath>
#include <iostream>

using namespace std;

long long sum_square_difference(const long long &n) {
	auto sum_of_squares = (n * (n + 1) * (2 * n + 1)) / 6;
	auto square_of_sums = pow((n * (n + 1)) / 2, 2);
	return abs(sum_of_squares - square_of_sums);
}

int euler006() {
	int t;
	cin >> t;
	for (int a0 = 0; a0 < t; a0++) {
		int n;
		cin >> n;
		cout << sum_square_difference(n) << '\n';
	}
	return 0;
}
