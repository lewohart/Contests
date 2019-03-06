// https://www.hackerrank.com/contests/projecteuler/challenges/euler004/
#include "pch.h"

#include <iostream>
using namespace std;

bool is_palindrome(unsigned long long n) {
	unsigned long long r = 0;
	for (unsigned long long t = n; t != 0; t /= 10)
		r = r * 10 + (t % 10);
	return r == n;
}

unsigned long long int largest_palindrome(long long n) {
	unsigned long long val;
	unsigned long long last = 101101;
	int min_j = 100;

	for (int i = 999; i > 100; --i) {
		for (int j = 999; j > min_j; --j) {
			val = i * j;
			if (val < 101101) break;
			if (val < n && is_palindrome(val))
				last = (last > val ? last : val), min_j = j;
		}
	}

	return last;
}

int euler004() {
	long long int n, val;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> val;
		cout << largest_palindrome(val) << endl;
	}

	return 0;
}