// https://www.hackerrank.com/challenges/ctci-array-left-rotation/
#include "pch.h"

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int>  array_left_rotation(vector<int> a, int k) {
	auto res = vector<int>();
	res.reserve(a.size());
	int p = (a.size() - k) % a.size();
	copy(end(a) - p, end(a), back_inserter(res));
	copy(begin(a), end(a) - p, back_inserter(res));
	return move(res);
}

int array_left_rotation_run() {
	int n;
	int k;
	cin >> n >> k;
	vector<int> a(n);
	for (int a_i = 0; a_i < n; a_i++) {
		cin >> a[a_i];
	}
	vector<int> output = array_left_rotation(a, k);
	for (int i = 0; i < n; i++)
		cout << output[i] << " ";
	cout << endl;
	return 0;
}
