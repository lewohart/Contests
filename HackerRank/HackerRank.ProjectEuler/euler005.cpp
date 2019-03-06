// https://www.hackerrank.com/contests/projecteuler/challenges/euler005/
#include "pch.h"

#include <iostream>
#include <limits>

int is_divisible_by_all_precedents(const int &val, const int &range) {
	for (int i = range; i > 0; --i)
		if ((val % i) != 0)
			return false;
	return true;
}

long long smallest_multiple(int n) {
	for (int i = n; i < std::numeric_limits<long long>::max(); i += n)
		if (is_divisible_by_all_precedents(i, n))
			return i;
	return -1;
}

int euler005() {
	long long int n, val;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		std::cin >> val;
		std::cout << smallest_multiple(val) << '\n';
	}

	return 0;
}