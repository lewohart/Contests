// https://www.hackerrank.com/challenges/c-tutorial-struct/submissions/code/13728420
#include "pch.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Student {
	int age;
	string first_name;
	string last_name;
	int standard;
};

int struct_run() {
	Student st;

	cin >> st.age >> st.first_name >> st.last_name >> st.standard;
	cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;

	return 0;
}
