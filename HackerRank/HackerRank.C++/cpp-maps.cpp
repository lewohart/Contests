//https://www.hackerrank.com/challenges/cpp-maps/
#include "pch.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


int maps() {
	enum operation_type { Add = 1, Delete = 2, Query = 3 };
	struct operation { int type; string key; int value; };
	int size;
	cin >> size;
	vector<operation> v(size);
	for_each(v.begin(), v.end(), [](operation &x) {
		cin >> x.type >> x.key;
		if (x.type == operation_type::Add) cin >> x.value; });
	map<string, int> s;
	map<string, int>::iterator p;
	for_each(v.begin(), v.end(), [&s](operation &x) {
		switch (operation_type(x.type)) {
		case Add:    s[x.key] += x.value; break;
		case Delete: s.erase(x.key); break;
		case Query:  cout << s[x.key] << endl; break;
		default: break;
		}
	});
	return 0;
}
