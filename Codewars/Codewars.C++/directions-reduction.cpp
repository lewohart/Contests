// https://www.codewars.com/kata/directions-reduction/train/cpp/
#include "pch.h"

#include <string>
#include <vector>

class DirReduction
{
public:
	static std::vector<std::string> dirReduc(std::vector<std::string> &arr) {
		auto needless = [](const std::string &from, const std::string &to) -> bool {
			return (from == "NORTH" && to == "SOUTH") || (from == "SOUTH" && to == "NORTH")
				|| (from == "EAST"  && to == "WEST") || (from == "WEST"  && to == "EAST");
		};

		std::vector<std::string> path;

		for (auto &c : arr) {
			if (!path.empty() && needless(path.back(), c))
				path.pop_back();
			else
				path.push_back(c);
		}

		return path;
	}
};

Describe(Directions_Reduction_Tests)
{
	It(All_Tests)
	{
		std::vector<std::string> d1 = { "NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST" };
		std::vector<std::string> ans1 = DirReduction::dirReduc(d1);
		std::vector<std::string> sol1 = { "WEST" };
		Assert::That(ans1, Equals(sol1));

		std::vector<std::string> d2 = { "NORTH","SOUTH","SOUTH","EAST","WEST","NORTH", "NORTH" };
		std::vector<std::string> ans2 = DirReduction::dirReduc(d2);
		std::vector<std::string> sol2 = { "NORTH" };
		Assert::That(ans2, Equals(sol2));
	}
};
