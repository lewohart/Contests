// https://www.hackerrank.com/challenges/a-very-big-sum/
#include "pch.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int a_very_big_sum() {
	long long n, val, sum = 0;
	std::cin >> n;

	for (long long i = 0; i < n; ++i) {
		std::cin >> val;
		sum += val;
	}

	std::cout << sum << '\n';

	return 0;
}