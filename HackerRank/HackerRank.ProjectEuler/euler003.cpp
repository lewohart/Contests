// https://www.hackerrank.com/contests/projecteuler/challenges/euler003
#include "pch.h"

#include <iostream>

unsigned long long  largest_prime_factor(unsigned long long n) {
	auto i = 2ull, largest = 1ull;

	while ((i * i) <= n)
		if (n % i == 0)
			largest = i, n /= i;
		else
			i++;

	return largest > n ? largest : n;
}

int euler003() {
	long long int n, val;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		std::cin >> val;
		std::cout << largest_prime_factor(val) << std::endl;
	}

	return 0;
}