// https://www.codewars.com/kata/bundesliga-1-spieltag-first-match-day/train/cpp/
#include "pch.h"

#if defined(_WIN32) || defined(_WIN64) 
#define strcasecmp _stricmp 
#endif

#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <sstream>


class Team {
private:
	std::string name;
	int pos, wins, lost, ties;
	int shots, gotten, points;

	const int diff() const {
		return shots - gotten;
	}

	const int matches() const {
		return wins + lost + ties;
	}

	const bool tied_with(const Team &b) const {
		return points == b.points && diff() == b.diff() && shots == b.shots;
	}
public:
	Team(std::string &name) : name(name), pos(), wins(), lost(), ties(), shots(), gotten(), points() { }

	void match(int s, int g) {
		if (s == -1 || g == -1) return;
		shots += s, gotten += g;
		if (s == g) ++ties, points += 1;
		else if (s > g) wins++, points += 3;
		else ++lost;
	}

	void rank_after(const int &index, const Team &b) {
		pos = tied_with(b) ? b.pos : index;
	}

	const bool equals(const Team &b) const {
		return name == b.name;
	}

	const bool operator < (const Team &b) const {
		return b.points != points ?
			b.points < points :
			b.diff() != diff() ?
			b.diff() < diff() :
			b.shots != shots ?
			b.shots < shots :
			::strcasecmp(b.name.c_str(), name.c_str()) > 0;
	}

	friend std::ostream& operator << (std::ostream& os, const Team & t) {
		os << std::setw(2) << std::right << t.pos + 1 << ". "
			<< std::setw(30) << std::left << t.name << ""
			<< t.matches() << "  "
			<< t.wins << "  "
			<< t.ties << "  "
			<< t.lost << "  "
			<< t.shots << ":" << t.gotten << "  "
			<< t.points;
		return os;
	}
};

class Bundesliga : public std::vector<Team>
{
private:
	Team& get_team(std::string name) {
		auto found = std::find_if(begin(), end(), [&](const  Team &a) {
			return a.equals(name);
		});

		return *(found != end() ? found : insert(end(), Team(name)));
	}
public:
	void add_game(std::string s) {
		auto try_stoi = [&](auto v) {
			return v.compare("-") == 0 ? -1 : std::stoi(v);
		};

		size_t t[] = { s.find(':'), s.find(' '), s.find('-', s.find(' ') + 1) };

		auto x = try_stoi(s.substr(0, t[0])), y = try_stoi(s.substr(t[0] + 1, t[1] - 1 - t[0]));
		auto team1 = (s.substr(t[1] + 1, t[2] - 2 - t[1])), team2 = (s.substr(t[2] + 2));

		get_team(team1).match(x, y);
		get_team(team2).match(y, x);
	}

	void close_round() {
		std::sort(begin(), end());

		for (auto p = begin(), c = begin() + 1; c != end(); ++c, ++p)
			c->rank_after(std::distance(begin(), c), *p);
	}

	std::string placard() const {
		std::ostringstream res;
		std::function<std::string()> f = [&]() {f = []() { return "\n"; }; return ""; };

		for (auto l : *this)
			res << f() << l;

		return res.str();
	}

	std::string table(std::vector<std::string> results)
	{
		Bundesliga league;

		for (auto s : results)
			league.add_game(s);

		league.close_round();
		return league.placard();
	}
};

Describe(Bundesliga_1_Spieltag_First_Match_Day_Tests)
{
	It(FridayEveningTest)
	{
		std::vector<std::string> results =
		{
			"6:0 FC Bayern Muenchen - Werder Bremen",
			"-:- Eintracht Frankfurt - Schalke 04",
			"-:- FC Augsburg - VfL Wolfsburg",
			"-:- Hamburger SV - FC Ingolstadt",
			"-:- 1. FC Koeln - SV Darmstadt",
			"-:- Borussia Dortmund - FSV Mainz 05",
			"-:- Borussia Moenchengladbach - Bayer Leverkusen",
			"-:- Hertha BSC Berlin - SC Freiburg",
			"-:- TSG 1899 Hoffenheim - RasenBall Leipzig"
		};

		std::string expected =
			" 1. FC Bayern Muenchen            1  1  0  0  6:0  3\n"
			" 2. 1. FC Koeln                   0  0  0  0  0:0  0\n"
			" 2. Bayer Leverkusen              0  0  0  0  0:0  0\n"
			" 2. Borussia Dortmund             0  0  0  0  0:0  0\n"
			" 2. Borussia Moenchengladbach     0  0  0  0  0:0  0\n"
			" 2. Eintracht Frankfurt           0  0  0  0  0:0  0\n"
			" 2. FC Augsburg                   0  0  0  0  0:0  0\n"
			" 2. FC Ingolstadt                 0  0  0  0  0:0  0\n"
			" 2. FSV Mainz 05                  0  0  0  0  0:0  0\n"
			" 2. Hamburger SV                  0  0  0  0  0:0  0\n"
			" 2. Hertha BSC Berlin             0  0  0  0  0:0  0\n"
			" 2. RasenBall Leipzig             0  0  0  0  0:0  0\n"
			" 2. SC Freiburg                   0  0  0  0  0:0  0\n"
			" 2. Schalke 04                    0  0  0  0  0:0  0\n"
			" 2. SV Darmstadt                  0  0  0  0  0:0  0\n"
			" 2. TSG 1899 Hoffenheim           0  0  0  0  0:0  0\n"
			" 2. VfL Wolfsburg                 0  0  0  0  0:0  0\n"
			"18. Werder Bremen                 1  0  0  1  0:6  0";

		auto actual = Bundesliga().table(results);
		Assert::That("\n" + actual, Is().EqualTo("\n" + expected));
	}

	It(SaturdayEveningTest)
	{
		std::vector<std::string> results =
		{
			"6:0 FC Bayern Muenchen - Werder Bremen",
			"1:0 Eintracht Frankfurt - Schalke 04",
			"0:2 FC Augsburg - VfL Wolfsburg",
			"1:1 Hamburger SV - FC Ingolstadt",
			"2:0 1. FC Koeln - SV Darmstadt",
			"2:1 Borussia Dortmund - FSV Mainz 05",
			"2:1 Borussia Moenchengladbach - Bayer Leverkusen",
			"-:- Hertha BSC Berlin - SC Freiburg",
			"-:- TSG 1899 Hoffenheim - RasenBall Leipzig"
		};

		std::string expected =
			" 1. FC Bayern Muenchen            1  1  0  0  6:0  3\n"
			" 2. 1. FC Koeln                   1  1  0  0  2:0  3\n"
			" 2. VfL Wolfsburg                 1  1  0  0  2:0  3\n"
			" 4. Borussia Dortmund             1  1  0  0  2:1  3\n"
			" 4. Borussia Moenchengladbach     1  1  0  0  2:1  3\n"
			" 6. Eintracht Frankfurt           1  1  0  0  1:0  3\n"
			" 7. FC Ingolstadt                 1  0  1  0  1:1  1\n"
			" 7. Hamburger SV                  1  0  1  0  1:1  1\n"
			" 9. Hertha BSC Berlin             0  0  0  0  0:0  0\n"
			" 9. RasenBall Leipzig             0  0  0  0  0:0  0\n"
			" 9. SC Freiburg                   0  0  0  0  0:0  0\n"
			" 9. TSG 1899 Hoffenheim           0  0  0  0  0:0  0\n"
			"13. Bayer Leverkusen              1  0  0  1  1:2  0\n"
			"13. FSV Mainz 05                  1  0  0  1  1:2  0\n"
			"15. Schalke 04                    1  0  0  1  0:1  0\n"
			"16. FC Augsburg                   1  0  0  1  0:2  0\n"
			"16. SV Darmstadt                  1  0  0  1  0:2  0\n"
			"18. Werder Bremen                 1  0  0  1  0:6  0";

		auto actual = Bundesliga().table(results);
		Assert::That("\n" + actual, Is().EqualTo("\n" + expected));
	}

	It(SundayEveningTest)
	{
		std::vector<std::string> results =
		{
			"6:0 FC Bayern Muenchen - Werder Bremen",
			"1:0 Eintracht Frankfurt - Schalke 04",
			"0:2 FC Augsburg - VfL Wolfsburg",
			"1:1 Hamburger SV - FC Ingolstadt",
			"2:0 1. FC Koeln - SV Darmstadt",
			"2:1 Borussia Dortmund - FSV Mainz 05",
			"2:1 Borussia Moenchengladbach - Bayer Leverkusen",
			"2:1 Hertha BSC Berlin - SC Freiburg",
			"2:2 TSG 1899 Hoffenheim - RasenBall Leipzig"
		};

		std::string expected =
			" 1. FC Bayern Muenchen            1  1  0  0  6:0  3\n"
			" 2. 1. FC Koeln                   1  1  0  0  2:0  3\n"
			" 2. VfL Wolfsburg                 1  1  0  0  2:0  3\n"
			" 4. Borussia Dortmund             1  1  0  0  2:1  3\n"
			" 4. Borussia Moenchengladbach     1  1  0  0  2:1  3\n"
			" 4. Hertha BSC Berlin             1  1  0  0  2:1  3\n"
			" 7. Eintracht Frankfurt           1  1  0  0  1:0  3\n"
			" 8. RasenBall Leipzig             1  0  1  0  2:2  1\n"
			" 8. TSG 1899 Hoffenheim           1  0  1  0  2:2  1\n"
			"10. FC Ingolstadt                 1  0  1  0  1:1  1\n"
			"10. Hamburger SV                  1  0  1  0  1:1  1\n"
			"12. Bayer Leverkusen              1  0  0  1  1:2  0\n"
			"12. FSV Mainz 05                  1  0  0  1  1:2  0\n"
			"12. SC Freiburg                   1  0  0  1  1:2  0\n"
			"15. Schalke 04                    1  0  0  1  0:1  0\n"
			"16. FC Augsburg                   1  0  0  1  0:2  0\n"
			"16. SV Darmstadt                  1  0  0  1  0:2  0\n"
			"18. Werder Bremen                 1  0  0  1  0:6  0";

		auto actual = Bundesliga().table(results);
		Assert::That("\n" + actual, Is().EqualTo("\n" + expected));
	}
};