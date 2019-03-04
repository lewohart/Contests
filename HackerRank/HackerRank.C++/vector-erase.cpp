//https://www.hackerrank.com/challenges/vector-erase/
#include "pch.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int vector_erase_run() {
	int n;
	cin >> n;
	vector<int> values(n);
	for_each(values.begin(), values.end(), [](int &x) { cin >> x; });

	int pos;
	cin >> pos;
	values.erase(values.begin() + pos - 1);

	int start, end;
	cin >> start >> end;
	values.erase(values.begin() + start - 1, values.begin() + end - 1);

	cout << values.size() << endl;
	for_each(values.begin(), values.end(), [](int &x) { cout << x << ' '; });

	return 0;
}
