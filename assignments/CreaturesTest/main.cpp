#include <iostream>
#include "Util.h"
#include "Game.h"

using namespace std;

int main()
{
	initRandomNumber();
	
	Game game;
	game.play();

	string str;
	getline(cin, str);

	return 0;
}