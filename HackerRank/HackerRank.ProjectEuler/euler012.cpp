// https://www.hackerrank.com/contests/projecteuler/challenges/euler012/
#include "pch.h"

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

long long nth_triangular(int n) {
	return n * (n + 1) / 2;
}

vector<bool> atkin_sieve(int max) {
	vector<bool> sieve(max + 1);
	auto n = 0, sqrt_max = int(sqrt(max));

	sieve[2] = sieve[3] = true;

	for (auto x = 1; x < sqrt_max; x++) {
		for (auto y = 1; y < sqrt_max; y++) {
			n = (4 * x * x) + (y * y);
			if (n <= max && (n % 12 == 1 || n % 12 == 5)) sieve[n] = !sieve[n];

			n = (3 * x * x) + (y * y);
			if (n <= max && (n % 12 == 7)) sieve[n] = !sieve[n];

			n = (3 * x * x) - (y * y);
			if (x > y && n <= max && (n % 12 == 11)) sieve[n] = !sieve[n];
		}
	}

	for (auto k = 5; k < sqrt_max; k++) {
		if (sieve[k]) {
			n = k * k;
			for (auto l = n; l <= max; l += n) sieve[l] = false;
		}
	}

	return sieve;
}

void for_each_prime(vector<bool> &sieve, function<bool(int)> func) {
	for (size_t prime = 2; prime < sieve.size(); ++prime)
		if (sieve[prime])
			if (func(prime) == false)
				break;
}

int count_divisors(long long n, vector<bool> &sieve)
{
	int res = 1;
	for_each_prime(sieve,
		[&](auto prime) -> bool {
		int exp = 0;

		while (n % prime == 0) {
			++exp;
			n /= prime;
		}

		res *= (exp + 1);
		return prime < sqrt(n);
	});
	return (n > 1) ? 2 * res : res;
}

long long first_triangle_having_over_n_divisors(const int &n, vector<bool> &sieve) {
	for (auto i = 1; i < int(sieve.size()); ++i) {
		auto t = nth_triangular(i);
		auto qty_divisors = count_divisors(t, sieve);

		if (qty_divisors > n)
			return t;
	}
	return 0;
}

// TODO: incorrect
int euler012() {
	int t;
	cin >> t;
	vector<int> nths(t);

	for (auto i = 0; i < nths.size(); ++i) {
		cin >> nths[i];
	}

	auto sieve = atkin_sieve(pow(10, 3));

	for (auto i = 0; i < nths.size(); ++i) {
		cout << first_triangle_having_over_n_divisors(nths[i], sieve) << "\n";
	}

	return 0;
}
