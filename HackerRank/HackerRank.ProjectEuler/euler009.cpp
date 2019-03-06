// https://www.hackerrank.com/contests/projecteuler/challenges/euler009/
#include "pch.h"

#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

unsigned int gcd(unsigned int a, unsigned int b) {
	unsigned int x;
	while (b != 0) {
		x = a;
		a = b;
		b = x % b;
	}
	return a;
}

map<int, int> get_triplets(const int &n) {
	map<int, int> res;

	for (auto i = 1; i < n; i++) {
		for (auto j = 1; j < i; j++) {
			if (
				(i * i + j * j) < n
				&& (i - j) % 2
				&& gcd(i, j) == 1
				)
			{
				auto a = 1 * (i * i) - (j * j);
				auto b = 2 * (i * j);
				auto c = 1 * (i * i) + (j * j);

				for (auto k = 1; (k * c) < n + 1; ++k) {
					auto ind = (k * a) + (k * b) + (k * c);
					auto val = (k * a) * (k * b) * (k * c);

					auto it = res.find(ind);
					auto has_prev = it != res.end();

					if (has_prev)
						it->second = max(it->second, val);
					else
						res[ind] = val;
				}
			}
		}
	}

	return res;
}

int special_pythagorean_triplet(const int &n, map<int, int> &t) {
	auto it = t.find(n);
	return (it == t.end()) ? -1 : it->second;
}

int euler009() {
	int t;
	cin >> t;

	vector<int> nths;
	int m = -1;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		nths.push_back(n);
		m = max(n, m);
	}

	auto r = get_triplets(m);

	for (auto n : nths) {
		cout << special_pythagorean_triplet(n, r) << "\n";
	}

	return 0;
}
