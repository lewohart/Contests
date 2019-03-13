// https://www.codewars.com/kata/thinking-and-testing-incomplete-string/train/cpp/
#include "pch.h"

#include <string>

std::string testit(std::string s)
{
	std::string r((s.size() / 2) + s.size() % 2, s[std::max<int>(0, (int)s.size() - 1)]);
	for (auto i = 0; i < s.size() / 2; i++) r[i] = (s[i * 2] + s[i * 2 + 1]) / 2;
	return r;
}

Describe(Thinking_And_Testing_Incomplete_String_Tests)
{
	It(All_Tests)
	{
		//return s ?
		Assert::That(testit(""), Is().EqualTo(""));
		Assert::That(testit("a"), Is().EqualTo("a"));
		Assert::That(testit("b"), Is().EqualTo("b"));

		//return s.Substring(0,1) ?
		Assert::That(testit("aa"), Is().EqualTo("a"));
		Assert::That(testit("ab"), Is().EqualTo("a"));
		Assert::That(testit("bc"), Is().EqualTo("b"));

		//return s.Substring(0,s.Length/2) ?
		Assert::That(testit("aaaa"), Is().EqualTo("aa"));
		Assert::That(testit("aaaaaa"), Is().EqualTo("aaa"));
	}
};