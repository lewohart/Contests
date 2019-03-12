// https://www.codewars.com/kata/playing-with-digits/train/cpp
#include "pch.h"

#include <cmath>
#include <string>

class DigPow
{
public:
	static int digPow(int n, int p);
};

int  DigPow::digPow(int n, int p) {
	std::string s = std::to_string(n);
	long long succ_pow = 0, i = 0;

	for (const auto &c : s)
		succ_pow += std::pow(static_cast<int>(c - '0'), p + i++);

	return (succ_pow % n == 0) ? (succ_pow / n) : -1;
}

Describe(digPow_Tests)
{
	It(Fixed__Tests)
	{
		Assert::That(DigPow::digPow(89, 1), Equals(1));
		Assert::That(DigPow::digPow(92, 1), Equals(-1));
		Assert::That(DigPow::digPow(46288, 3), Equals(51));
		Assert::That(DigPow::digPow(114, 3), Equals(9));
	}
};

