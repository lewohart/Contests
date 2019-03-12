// https://www.codewars.com/kata/reverse-or-rotate/train/
#include "pch.h"
#include <igloo/igloo_alt.h>

using namespace igloo;

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

class RevRot
{
public:
	static std::string revRot(const std::string &str, unsigned int sz);
	static bool sum_of_the_cubes_of_its_digits_is_divisible_by_2(const std::string &str);
};

std::string RevRot::revRot(const std::string &str, unsigned int sz)
{
	const int chunks{ sz == 0 || str.size() < sz ? 0 : static_cast<int>(str.size() / sz) };

	if (chunks == 0) return{};

	std::vector<std::string> r(chunks);
	int p{ 0 };

	for (auto &s : r) {
		s = str.substr(p++ * sz, sz);

		if (sum_of_the_cubes_of_its_digits_is_divisible_by_2(s))
			std::reverse(s.begin(), s.end());
		else
			std::rotate(s.begin(), s.begin() + 1, s.end());
	}

	return std::accumulate(r.begin(), r.end(), std::string(), [](const auto& a, const auto& b) -> std::string { return a + b; });
}

bool RevRot::sum_of_the_cubes_of_its_digits_is_divisible_by_2(const std::string &s) {
	int sum{ 0 };

	for (const auto &c : s) {
		auto d = static_cast<int>(c - '0');
		sum += (d * d * d);
	}

	return (sum % 2) == 0;
}

void testequal(std::string ans, std::string sol)
{
	Assert::That(ans, Equals(sol));
}

static void dotest(std::string s, unsigned int sz, std::string expected)
{
	testequal(RevRot::revRot(s, sz), expected);
}

Describe(revRot_Tests)
{
	It(Fixed__Tests)
	{
		std::string s = "1234";
		dotest(s, 0, "");
		s = "";
		dotest(s, 0, "");
		s = "733049910872815764";
		dotest(s, 5, "330479108928157");
		s = "73304991087281576455176044327690580265896";
		dotest(s, 8, "1994033775182780067155464327690480265895");
	}
};