// https://www.codewars.com/kata/the-supermarket-queue/train/cpp/
#include "pch.h"

#include <numeric>
#include <algorithm>

long queueTime(std::vector<int> c, const int n) {
	if (c.size() == 0)
		return 0;

	if (n == 1)
		return std::accumulate(c.begin(), c.end(), 0);

	if (n >= c.size())
		return *std::max_element(c.begin(), c.end());

	long count = 0, next = 0;
	std::vector<int*> at_tills(n);

	for (long count = 0; ; ++count) {
		for (auto &p : at_tills)
			if (p == nullptr || *p == 0)
				p = (next < c.size()) ? &c[next++] : nullptr;

		if (std::count(at_tills.begin(), at_tills.end(), nullptr) == n)
			return count;

		for (int i = 0; i < n; ++i)
			if (at_tills[i] != nullptr)
				--(*at_tills[i]);
	}
}

Describe(The_Supermarket_Queue_Tests)
{
	It(All_Tests)
	{
		Assert::That(queueTime(std::vector<int>{}, 1), Equals(0));
		Assert::That(queueTime(std::vector<int>{1, 2, 3, 4}, 1), Equals(10));
		Assert::That(queueTime(std::vector<int>{2, 2, 3, 3, 4, 4}, 2), Equals(9));
		Assert::That(queueTime(std::vector<int>{1, 2, 3, 4, 5}, 100), Equals(5));
	}
};