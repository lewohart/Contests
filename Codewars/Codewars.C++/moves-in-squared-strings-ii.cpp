// https://www.codewars.com/kata/moves-in-squared-strings-ii/train/cpp/
#include "pch.h"

#include <functional>
#include <string>

class Opstrings1
{
private:
	using string_operation = std::function<std::string(const std::string &)>;
public:
	static std::string rot(const std::string &s) {
		std::string r{ s };
		std::reverse(r.begin(), r.end());
		return r;
	}

	static std::string selfieAndRot(const std::string &s) {
		std::string r(s.size() * 4 + 3, '.');
		int line_count = 0;

		for (int i = 0, x = 0, len = 0; i < s.size(); ++i, ++x, ++len) {
			if (s[i] == '\n') {
				x += len;
				len = -1;
				++line_count;
			}

			r[r.size() - x - 1] = r[x] = s[i];
		}

		int middle = (int)s.size() * 2 - line_count;
		r[middle] = '\n';
		r.erase(middle + 1, (line_count + 1) * 2);
		return r;
	}
};

Describe(Moves_In_Squared_String_II_Tests)
{
	It(rot_Tests)
	{
		std::string s = "fijuoo\nCqYVct\nDrPmMJ\nerfpBA\nkWjFUG\nCVUfyL";
		std::string sol = "LyfUVC\nGUFjWk\nABpfre\nJMmPrD\ntcVYqC\nooujif";
		Assert::That(Opstrings1::rot(s), Equals(sol));

		s = "rkKv\ncofM\nzXkh\nflCB";
		sol = "BClf\nhkXz\nMfoc\nvKkr";
		Assert::That(Opstrings1::rot(s), Equals(sol));
	}

	It(selfieAndRot_Tests)
	{
		std::string s = "xZBV\njsbS\nJcpN\nfVnP";
		std::string sol = "xZBV....\njsbS....\nJcpN....\nfVnP....\n....PnVf\n....NpcJ\n....Sbsj\n....VBZx";
		Assert::That(Opstrings1::selfieAndRot(s), Equals(sol));

		s = "xZBV\njsbS\nJcpN\nfVnP";
		sol = "xZBV....\njsbS....\nJcpN....\nfVnP....\n....PnVf\n....NpcJ\n....Sbsj\n....VBZx";
		Assert::That(Opstrings1::selfieAndRot(s), Equals(sol));
	}
};

