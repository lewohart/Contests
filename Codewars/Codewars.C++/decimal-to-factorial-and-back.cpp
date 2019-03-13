// https://www.codewars.com/kata/decimal-to-factorial-and-back/train/cpp/
#include "pch.h"

#include <string>
#include <functional>

class Dec2Fact
{
public:
	static std::string dec2FactString(long long n) {
		std::string res;
		int p = 1;

		res.reserve(std::numeric_limits<int>::digits);

		while (n > 0) {
			int remainder = n % p;
			char digit = ((remainder <= 9) ? '0' : ('A' - 10)) + static_cast<char>(remainder);
			res.insert(res.begin(), digit);
			n /= p++;
		}

		return res;
	}

	static long long factString2Dec(const std::string &s) {
		long long res{}, fact = s.size() - 1;
		std::function<long long(long long)> factorial = [&](long long x) { return x == 1 || x == 0 ? 1 : x * factorial(x - 1); };

		for (auto & c : s) {
			int val = c - ((c <= '9') ? '0' : ('A' - 10));
			res += (val * factorial(fact--));
		}

		return res;
	}
};

Describe(Dec2Fact_and_Back_Tests)
{
	It(All_Tests)
	{
		Assert::That(Dec2Fact::dec2FactString(2982), Equals("4041000"));
		Assert::That(Dec2Fact::dec2FactString(463), Equals("341010"));

		Assert::That(Dec2Fact::factString2Dec("341010"), Equals(463));
		Assert::That(Dec2Fact::factString2Dec("65341010"), Equals(34303));

		Assert::That(Dec2Fact::factString2Dec(Dec2Fact::dec2FactString(999999999)), Equals(999999999));
	}
};