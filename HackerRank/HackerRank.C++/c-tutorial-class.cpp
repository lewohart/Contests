// https://www.hackerrank.com/challenges/c-tutorial-class/
#include "pch.h"

#include <iostream>
#include <sstream>
using namespace std;

class Student {
private:
	int age;
	string first_name;
	string last_name;
	int standard;
public:
	const int &get_age() const { return this->age; }
	void set_age(const int &age) { this->age = age; }

	const string &get_first_name() const { return this->first_name; }
	void set_first_name(const string &first_name) { this->first_name = first_name; }

	const string &get_last_name() const { return last_name; }
	void set_last_name(const string &last_name) { this->last_name = last_name; }

	const int &get_standard() const { return standard; }
	void set_standard(const int &standard) { this->standard = standard; }

	const string to_string() const {
		stringstream r;
		r << age << ',' << first_name << ',' << last_name << ',' << standard;
		return r.str();
	}
};

int class_run() {
	int age, standard;
	string first_name, last_name;

	cin >> age >> first_name >> last_name >> standard;

	Student st;
	st.set_age(age);
	st.set_standard(standard);
	st.set_first_name(first_name);
	st.set_last_name(last_name);

	cout << st.get_age() << "\n";
	cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
	cout << st.get_standard() << "\n";
	cout << "\n";
	cout << st.to_string();

	return 0;
}
