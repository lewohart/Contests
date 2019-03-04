// https://www.hackerrank.com/challenges/saveprincess/
#include "pch.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayPathtoPrincess(int n, vector <string> grid) {
	string step[2];
	n -= 1;
	if (grid[0][0] == 'p') step[0] = "UP", step[1] = "LEFT";
	else if (grid[0][n] == 'p') step[0] = "DOWN", step[1] = "LEFT";
	else if (grid[n][0] == 'p') step[0] = "UP", step[1] = "RIGHT";
	else if (grid[n][n] == 'p') step[0] = "DOWN", step[1] = "RIGHT";

	for (int i = 0; i < (n / 2); ++i)
		cout << step[0] << endl << step[1] << endl;
}

int save_princess_run(void) {

	int m;
	vector <string> grid;

	cin >> m;

	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		grid.push_back(s);
	}

	displayPathtoPrincess(m, grid);

	return 0;
}
