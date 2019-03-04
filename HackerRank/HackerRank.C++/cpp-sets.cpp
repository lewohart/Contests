// https://www.hackerrank.com/challenges/cpp-sets/
#include "pch.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int sets() {
	enum operation_type { Add = 1, Delete = 2, Query = 3 };
	struct operation { int operation; int value; };
	int size;
	cin >> size;
	vector<operation> v(size);
	for_each(v.begin(), v.end(), [](operation &x) { cin >> x.operation >> x.value; });
	set<int> s;
	set<int>::iterator p;
	for_each(v.begin(), v.end(), [&s](const operation &x) {
		switch (operation_type(x.operation)) {
		case Add:    s.insert(x.value); break;
		case Delete: s.erase(x.value); break;
		case Query:  cout << (s.find(x.value) != s.end() ? "Yes" : "No") << endl; break;
		default: break;
		}
	});

	return 0;
}
