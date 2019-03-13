// https://www.codewars.com/kata/how-many-times-does-it-contain/train/cpp/
#include "pch.h"

#include <string>
#include <numeric>

static int stringCounter(std::string v, char c) {
	return std::accumulate(v.begin(), v.end(), 0,
		[&c](const auto &a, const auto &b) -> int {
		return a + (b == c ? 1 : 0);
	});
}

Describe(How_Many_Times_Does_it_Contain_Test)
{
	It(Hello_World_Tests)
	{
		Assert::That(stringCounter("Hello World", 'o'), Equals(2));
	}
	It(Cinical_test_case)
	{
		Assert::That(stringCounter("Wait isn't it supposed to be cynical?", 'i'), Equals(4));
	}
	It(Lets_see_how_you_handle_this)
	{
		Assert::That(stringCounter("I'm gona be the best code warrior ever dad", 'r'), Equals(4));
	}
	It(What_do_you_think)
	{
		Assert::That(stringCounter("Do you like Harry Potter?", '?'), Equals(1));
	}
};