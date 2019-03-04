// https://www.hackerrank.com/challenges/arrays-introduction/
#include "pch.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int arrays_introduction() {
	int size;
	cin >> size;
	vector<int> v(size);
	for_each(v.begin(), v.end(), [](int &x) { cin >> x; });
	for_each(v.rbegin(), v.rend(), [](int x) { cout << x << ' '; });
	return 0;
}
