// https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/
#include "pch.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int conditional_if_else_run() {
	vector<string> enUSnumbers = {
		"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "Greater than 9" };
	int opt;
	cin >> opt;
	cout << enUSnumbers[min(opt - 1, 9)];
	return 0;
}
