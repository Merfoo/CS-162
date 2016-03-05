#include <iostream>
#include "Level.h"

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Hello World!" << endl;

	Level level;
	level.create("level.txt");
	level.print();

	return cin.get();
}