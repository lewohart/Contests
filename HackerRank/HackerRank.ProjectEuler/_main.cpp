// HackerRank.ProjectEuler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc < 2)
		return EXIT_FAILURE;

	if (strcmp(argv[1], "euler001") == 0)
	{
		extern int euler001();
		euler001();
	}
}
