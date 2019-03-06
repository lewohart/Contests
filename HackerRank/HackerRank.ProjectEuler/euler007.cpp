// https://www.hackerrank.com/contests/projecteuler/challenges/euler007/
#include "pch.h"

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<bool> atkin_sieve(int max) {
	vector<bool> sieve(max + 1);
	auto n = 0, sqrt_max = int(sqrt(max));

	for (auto x = 1; x < sqrt_max; x++) {
		for (auto y = 1; y < sqrt_max; y++) {
			n = (4 * x * x) + (y * y);

			if (n <= max && (n % 12 == 1 || n % 12 == 5))
				sieve[n] = !sieve[n];

			n = (3 * x * x) + (y * y);

			if (n <= max && (n % 12 == 7))
				sieve[n] = !sieve[n];

			n = (3 * x * x) - (y * y);

			if (x > y && n <= max && (n % 12 == 11))
				sieve[n] = !sieve[n];
		}
	}

	for (auto k = 5; k < sqrt_max; k++) {
		if (sieve[k]) {
			n = k * k;

			for (auto l = n; l <= max; l += n)
				sieve[l] = false;
		}
	}

	return sieve;
}

vector<int> get_primes(int max) {
	vector<int> primes{ 2, 3, 5 };
	auto sieve = atkin_sieve(max);

	primes.reserve(max / log(max));

	for (auto x = 7; x <= max; x += 2) {
		if (sieve[x]) {
			primes.push_back(x);
		}
	}

	return primes;
}

int euler007(int argc, char **argv) {
	auto max = 0;
	vector<int> nths;

	int t;
	cin >> t;

	for (int a0 = 0; a0 < t; a0++) {
		int n;
		cin >> n;
		nths.push_back(n);

		if (n > max) {
			max = n;
		}
	}

	auto size = pow(10, 4);
	vector<int> primes;

	while (primes.size() < max) {
		size *= 1.5;
		primes = get_primes(size);
	}

	for (auto &n : nths) {
		cout << primes[n - 1] << "\n";
	}

	return 0;
}