//https://www.hackerrank.com/challenges/c-tutorial-stringstream/
#include "pch.h"

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	stringstream in(str + ',');
	vector<int> result;
	char c;
	for (int x = 0; in >> x >> c; result.push_back(x));
	return result;
}

int stringstream_run() {
	string str;
	cin >> str;
	vector<int> integers = parseInts(str);
	for (int i = 0; i < integers.size(); i++) {
		cout << integers[i] << "\n";
	}

	return 0;
}
