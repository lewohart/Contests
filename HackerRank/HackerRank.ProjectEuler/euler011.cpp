// https://www.hackerrank.com/contests/projecteuler/challenges/euler011/
#include "pch.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long max_product(vector<vector<int>> g, int x, int y) {
	auto height = int(g[0].size());
	auto width = int(g.size());

	auto _ = [&](const int &x, const int &y) -> long long {
		return
			(0 > x || x >= width) ? 1 :
			(0 > y || y >= height) ? 1 : g[y][x]; };

	auto l_ = _(x, y) * _(x - 1, y - 0) * _(x - 2, y - 0) * _(x - 3, y - 0);
	auto tl = _(x, y) * _(x - 1, y - 1) * _(x - 2, y - 2) * _(x - 3, y - 3);
	auto t_ = _(x, y) * _(x + 0, y - 1) * _(x + 0, y - 2) * _(x + 0, y - 3);
	auto tr = _(x, y) * _(x + 1, y - 1) * _(x + 2, y - 2) * _(x + 3, y - 3);
	auto r_ = _(x, y) * _(x + 1, y + 0) * _(x + 2, y + 0) * _(x + 3, y + 0);
	auto br = _(x, y) * _(x + 1, y + 1) * _(x + 2, y + 2) * _(x + 3, y + 3);
	auto b_ = _(x, y) * _(x - 0, y + 1) * _(x - 0, y + 2) * _(x - 0, y + 3);
	auto bl = _(x, y) * _(x - 1, y - 1) * _(x - 2, y - 2) * _(x - 3, y - 3);

	return max(l_, max(tl, max(t_, max(tr, max(r_, max(br, max(b_, bl)))))));
}

int euler011() {
	vector< vector<int> > grid(20, vector<int>(20));
	for (int grid_i = 0; grid_i < 20; grid_i++) {
		for (int grid_j = 0; grid_j < 20; grid_j++) {
			cin >> grid[grid_i][grid_j];
		}
	}

	long long mult = 0;

	for (auto y = 0; y < grid.size(); ++y)
		for (auto x = 0; x < grid[y].size(); ++x)
			mult = max(max_product(grid, x, y), mult);

	cout << mult << "\n";

	return 0;
}
