// https://www.codewars.com/kata/consecutive-strings/train/cpp/
#include "pch.h"

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

class LongestConsec
{
public:
	static std::string longestConsec(std::vector<std::string> &sa, int k) {
		if (sa.size() == 0 || k > sa.size() || k <= 0)
			return std::string();

		int p = 0, max = 0;

		for (int i = 0; i < sa.size(); ++i) {
			int size = 
				std::accumulate(
					sa.begin() + i,
					sa.begin() + std::min(i + k, (int)sa.size()), 0,
					[](int sum, const auto& s) -> int { return sum + (int)s.size(); });

			if (size > max) {
				p = i;
				max = size;
			}
		}

		return 
			std::accumulate(
				sa.begin() + p,
				sa.begin() + std::min(p + k, (int)sa.size()), std::string(),
				[](auto a, auto b) -> std::string { return a + b; });
	}
};

Describe(Consecutive_Strings_Tests)
{
	It(All_Tests)
	{
		{
			std::vector<std::string> arr = { "zone", "abigail", "theta", "form", "libe", "zas", "theta", "abigail" };
			Assert::That(LongestConsec::longestConsec(arr, 2), Equals("abigailtheta"));
		}

		{
			std::vector<std::string> arr = { "ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx", "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh" };
			Assert::That(LongestConsec::longestConsec(arr, 1), Equals("oocccffuucccjjjkkkjyyyeehh"));
		}
	}
};
