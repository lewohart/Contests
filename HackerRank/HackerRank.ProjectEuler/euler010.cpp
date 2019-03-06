// https://www.hackerrank.com/contests/projecteuler/challenges/euler010/
#include "pch.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

vector<bool> atkin_sieve(int max) {
	vector<bool> sieve(max + 1);
	auto n = 0, sqrt_max = int(sqrt(max));
	sieve[2] = sieve[3] = true;

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

vector<long long> get_primes(int max) {
	auto sieve = atkin_sieve(max);
	vector<long long> res;
	res.reserve(int(sqrt(max)));

	for (auto i = 1; i < int(sieve.size()); ++i)
		if (sieve[i] == true)
			res.push_back(i);

	return res;
}

map<int, long long> get_primes_sum(const vector<int>& in) {
	map<int, long long> sums;

	auto sieve = atkin_sieve(int(pow(10, 6)));

	vector<int> nths(in);
	sort(begin(nths), end(nths));
	auto nth = begin(nths);
	long long sum = 0;

	for (auto prime = 1; prime < int(sieve.size()); ++prime) {
		if (sieve[prime] == false)
			continue;

		while (*nth <= prime) {
			sums[*nth] = (prime == *nth) ? sum + prime : sum;

			if (++nth == end(nths))
				break;
		}

		sum += prime;
	}

	return sums;
}

int euler010() {
	int t;
	cin >> t;
	vector<int> nths(t);

	for (int i = 0; i < nths.size(); i++) {
		cin >> nths[i];
	}

	auto sums = get_primes_sum(nths);

	for (auto &n : nths) {
		cout << sums[n] << "\n";
	}

	return 0;
}