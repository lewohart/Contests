// https://www.codewars.com/kata/multiples-of-3-or-5/train/cpp/
#include "pch.h"

int solution(int n)
{
	int sum{ 0 };

	for (int i = 0; i < n; i += 3)
		sum += i;

	for (int i = 0; i < n; i += 5)
		if (i % 3 != 0) sum += i;

	return sum;
}

Describe(Multiples_of_3_or_5_Tests)
{
	It(All_Tests)
	{
		Assert::That(solution(10), Equals(23));
	}
};