#include <iostream>
#include "Game.h"
#include "Level.h"

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Hello World!" << endl;

	Game game;
	game.play(1);

	return cin.get();
}