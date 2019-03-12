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


void testequal1(std::string ans, std::string sol) {
	Assert::That(ans, Equals(sol));
}
void testequal2(long long ans, long long sol) {
	Assert::That(ans, Equals(sol));
}
static void dotest1(long long nb, std::string expected)
{
	testequal1(Dec2Fact::dec2FactString(nb), expected);
}
static void dotest2(const std::string &str, long long expected)
{
	testequal2(Dec2Fact::factString2Dec(str), expected);
}
static void dotest3(long long nb, long long expected)
{
	testequal2(Dec2Fact::factString2Dec(Dec2Fact::dec2FactString(nb)), expected);
}

Describe(Dec2Fact_and_back_Tests)
{
	It(Fixed__Tests)
	{
		dotest1(2982, "4041000");
		dotest1(463, "341010");

		dotest2("341010", 463);
		dotest2("65341010", 34303);

		dotest3(999999999, 999999999);
	}
};