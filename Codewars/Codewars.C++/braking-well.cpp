// https://www.codewars.com/kata/braking-well/train/cpp/
#include "pch.h"

#include <iomanip>
#include <cmath>

class Braking
{
public:
	static double dist(double km_h, double mu) {
		double a = 2 * mu * 9.81;
		double v = km_h * 1000 / 3600;
		double d = v * (1.0 + v / a);
		return d;
	}

	static double speed(double d, double mu) {
		double a = 2 * mu * 9.81;
		double v = (std::sqrt(a) * std::sqrt(a + 4 * d) - a);
		double km_h = 1.8 * v;
		return km_h;
	}
};

static void Braking_Dist_Test(double v, double mu, double expected) {
	auto act = Braking::dist(v, mu);
	auto inrange = std::abs(act - expected) <= 1e-6;

	if (inrange == false) {
		std::cout << std::setprecision(25);
		std::cout << "At 1e-6: Expected should be " << expected << ", but got " << act << std::endl;
	}

	Assert::That(true, Equals(inrange));
}

static void Braking_Speed_Test(double d, double mu, double expected) {
	auto act = Braking::speed(d, mu);
	auto inrange = std::abs(act - expected) <= 1e-6;

	if (inrange == false) {
		std::cout << std::setprecision(25);
		std::cout << "At 1e-6: Expected should be " << expected << ", but got " << act << std::endl;
	}

	Assert::That(true, Equals(inrange));
}

Describe(Braking_Well_Tests)
{
	It(Dist_Tests)
	{
		Braking_Dist_Test(144, 0.3, 311.83146449201496);
		Braking_Dist_Test(92, 0.5, 92.12909477605366);
	}

	It(Speed_Tests)
	{
		Braking_Speed_Test(159, 0.8, 153.79671564846308);
		Braking_Speed_Test(164, 0.7, 147.91115701756493);
	}
};
