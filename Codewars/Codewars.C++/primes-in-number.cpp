// https://www.codewars.com/kata/primes-in-numbers/train/cpp/
#include "pch.h"

#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

class PrimeDecomp {
private:
	static const bool is_prime = false;

	static void sieve(const int n, std::function<bool(const int)> need_more_after_this) {
		std::vector<bool> A(n + 1);
		auto limit = static_cast<int>(std::floor(std::sqrt(n)));

		for (auto i = 2; i < limit; ++i)
			if (A[i] == is_prime && need_more_after_this(i))
				for (auto j = (i * i); j < n; j += i)
					A[j] = !is_prime;

		for (auto i = limit; i < n; ++i)
			if (A[i] == is_prime && !need_more_after_this(i))
				break;
	}

public:
	static std::string factors(int n)
	{
		std::string res;

		std::function<bool(const int &)> get_factors = [&n, &res](const int prime) -> bool {
			if (n < prime)
				return false;

			int i = 0;

			while ((n % prime) == 0)
				n /= prime, ++i;

			if (i != 0) {
				res += (i == 1) ?
					"(" + std::to_string(prime) + ")" :
					"(" + std::to_string(prime) + "**" + std::to_string(i) + ")";
			}

			return true;
		};

		sieve(static_cast<int>(std::floor(std::sqrt(n))), get_factors);

		if (n > 1)
			res += "(" + std::to_string(n) + ")";

		return res;
	}
};

Describe(factors_Tests)
{
	It(Fixed_Tests)
	{
		Assert::That(PrimeDecomp::factors(7775460), Equals("(2**2)(3**3)(5)(7)(11**2)(17)"));
		Assert::That(PrimeDecomp::factors(7919), Equals("(7919)"));
	}
};
