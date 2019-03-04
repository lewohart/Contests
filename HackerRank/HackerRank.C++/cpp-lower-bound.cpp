//https://www.hackerrank.com/challenges/cpp-lower-bound/
#include "pch.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int lower_bound() {
	int size;
	cin >> size;
	vector<int> v(size);
	for_each(v.begin(), v.end(), [](int &x) { cin >> x; });
	sort(v.begin(), v.end());

	cin >> size;
	vector<int> indexes(size);
	for_each(indexes.begin(), indexes.end(), [](int &x) { cin >> x; });

	for_each(indexes.begin(), indexes.end(), [&v](const int &i) {
		vector<int>::iterator p = lower_bound(v.begin(), v.end(), i);
		cout << ((*p) == i ? "Yes " : "No ") << (p - v.begin()) + 1 << endl;
	});

	return 0;
}
