// https://www.hackerrank.com/contests/projecteuler/challenges/euler008/submissions/
#include "pch.h"

#include <iostream>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

int largest_product_in_a_series(const string &num, const int &k) {
	int larg_prod = 0;

	for (auto i = num.begin(); i + k < num.end(); ++i) {
		larg_prod = max(larg_prod, accumulate(i, i + k, 1, [](int a, char b) -> int { return a * (b - int('0')); }));
	}

	return larg_prod;
}

int euler008() {
	int t;
	cin >> t;
	for (int a0 = 0; a0 < t; a0++) {
		int n;
		int k;
		cin >> n >> k;
		string num;
		cin >> num;
		cout << largest_product_in_a_series(num, k) << "\n";
	}
	return 0;
}
