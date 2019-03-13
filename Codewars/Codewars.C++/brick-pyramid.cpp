// https://www.codewars.com/kata/brick-pyramid/train/cpp/
#include "pch.h"

class Pyramid {
public:
	static double w(int r, int p) {
		return (0 > p || p > r) ? 0 : 1 + (w(r - 1, p - 1) + w(r - 1, p)) / 2;
	}

	static double weight(int row, int pos) {
		return w(row, pos) - 1;
	}
};

Describe(Brick_Pyramid_Tests)
{
	It(All_Tests)
	{
		Assert::That(Pyramid::weight(0, 0), Equals(0));
		Assert::That(Pyramid::weight(1, 0), Equals(0.5));
		Assert::That(Pyramid::weight(1, 1), Equals(0.5));

		Assert::That(Pyramid::weight(2, 0), Equals(0.75));
		Assert::That(Pyramid::weight(2, 1), Equals(1.5));
		Assert::That(Pyramid::weight(2, 2), Equals(0.75));

		Assert::That(Pyramid::weight(3, 0), Equals(0.875));
		Assert::That(Pyramid::weight(3, 1), Equals(2.125));
		Assert::That(Pyramid::weight(3, 2), Equals(2.125));
		Assert::That(Pyramid::weight(3, 3), Equals(0.875));
	}
};