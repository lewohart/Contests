// https://www.hackerrank.com/challenges/2d-array/
#include "pch.h"

#include <cstdio>
#include <limits>
#include <vector>
#include <iostream>

using namespace std;

const auto hourglass_width = 3;
const auto hourglass_height = 3;

vector<vector<int>> get_input() {
	vector<vector<int>> arr(6, vector<int>(6));

	for (int arr_i = 0; arr_i < 6; arr_i++)
		for (int arr_j = 0; arr_j < 6; arr_j++)
			cin >> arr[arr_i][arr_j];

	return arr;
}

int get_hourglass(const vector<vector<int>> &a, const int &x, const int &y) {
	return  
		(a[y + 0][x + 0]) + (a[y + 0][x + 1]) + (a[y + 0][x + 2])
		/*             */ + (a[y + 1][x + 1]) + /*             */
		(a[y + 2][x + 0]) + (a[y + 2][x + 1]) + (a[y + 2][x + 2]);
}

int _2d_array() {
	const auto arr = get_input();
	auto max = numeric_limits<int>::min();

	for (auto y = 0; y < arr.size() - hourglass_height + 1; ++y) {
		for (auto x = 0; x < arr[y].size() - hourglass_width + 1; ++x) {
			auto hourglass = get_hourglass(arr, x, y);

			if (max < hourglass)
				max = hourglass;
		}
	}

	cout << max;
	return 0;
}
