// https://www.hackerrank.com/challenges/c-tutorial-for-loop
#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int for_loop_run() {
	vector<string> enUSnumbers = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "even", "odd" };
	int cur, last;
	cin >> cur >> last;
	for (--cur; cur < last; ++cur)
		cout << enUSnumbers[min(cur - max(0, int(cur - 10) + (cur % 2)), 10)] << endl;
	return 0;
}
