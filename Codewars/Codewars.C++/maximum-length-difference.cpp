// https://www.codewars.com/kata/maximum-length-difference/train/cpp/
#include "pch.h"

#include <string>
#include <vector>

class MaxDiffLength
{
public:
	static int mxdiflg(std::vector<std::string> &a, std::vector<std::string> &b)
	{
		auto comp = [](auto m, auto n) {return m.size() < n.size(); };
		auto x = std::minmax_element(a.begin(), a.end(), comp);
		auto y = std::minmax_element(b.begin(), b.end(), comp);

		return x.first == a.end() || y.first == b.end() ? -1 :
			std::max(
				std::abs(static_cast<int>(x.second->size() - y.first->size())),
				std::abs(static_cast<int>(x.first->size() - y.second->size())));
	}
};

Describe(Maximum_Length_Difference_Tests)
{
	It(All_Tests)
	{
		{
			std::vector<std::string> s1 = { "hoqq", "bbllkw", "oox", "ejjuyyy", "plmiis", "xxxzgpsssa", "xxwwkktt", "znnnnfqknaz", "qqquuhii", "dvvvwz" };
			std::vector<std::string> s2 = { "cccooommaaqqoxii", "gggqaffhhh", "tttoowwwmmww" };
			Assert::That(MaxDiffLength::mxdiflg(s1, s2), Equals(13));
		}
		{
			std::vector<std::string> s1 = { "ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx", "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh" };
			std::vector<std::string> s2 = { "bbbaaayddqbbrrrv" };
			Assert::That(MaxDiffLength::mxdiflg(s1, s2), Equals(10));
		}
	}
};

