// https://www.hackerrank.com/challenges/vector-sort/
#include "pch.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int vector_sort_run() {
	int n;
	cin >> n;
	vector<int> values(n);
	for_each(values.begin(), values.end(), [](int &x) { cin >> x; });
	sort(values.begin(), values.end());
	for_each(values.begin(), values.end(), [](int &x) { cout << x << ' '; });
	return 0;
}
