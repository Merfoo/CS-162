#include <iostream>
#include <string>
#include "Game.h"
#include "Level.h"
#include "Util.h"

using namespace std;
using namespace Util;

void printErrorMessage(string programName)
{
	cout << "Error, expected: " << programName << " <number of floors>" << endl;
	cout << "ex: " << programName << " 2" << endl;
}

int main(int argc, char* argv[])
{
	// Not enough arguments
	if (argc < 2)
	{
		printErrorMessage(argv[0]);
		return -1;
	}

	// Try converting 2nd element to number
	int numberOfFloors = 0;

	try
	{
		numberOfFloors = stoi(string(argv[1]));
	}

	catch (...)
	{
		printErrorMessage(argv[0]);
		return -1;
	}

	// Floor number isn't big enough
	if (numberOfFloors <= 0)
	{
		printErrorMessage(argv[0]);
		return -1;
	}

	initRandomNumber();
	cout << "Welcome to the maze!" << endl;
	
	Game game;
	game.play(numberOfFloors);

	cout << "Press enter to quit..." << endl;
	return cin.get();
}