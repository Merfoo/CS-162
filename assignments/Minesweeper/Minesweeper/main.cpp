#include <iostream>
#include "Util.h"
#include "Game.h"

using namespace std;
using namespace Util;

int main(int argc, char* argv[])
{
	initRandomNumber();
	cout << "Welcome to Minesweeper!" << endl;

	int width, height, bombs;

	while (true)
	{
		cout << "Game Width: ";
		width = readInt();

		if (width > 0 && width < 39)
			break;

		cout << "Width must be between 0 and 39!" << endl;
	}

	while (true)
	{
		cout << "Game Height: ";
		height = readInt();

		if (height > 0 && height < 39)
			break;

		cout << "Height must be between 0 and 39!" << endl;
	}

	while (true)
	{
		cout << "Game Bombs: ";
		bombs = readInt();

		if (bombs > 0 && bombs <= width * height)
			break;

		cout << "Bombs must be between 0 and width * height!" << endl;
	}

	Game game;
	game.play(height, width, bombs);

	cout << "Press enter to exit..." << endl;
	return cin.get();
}