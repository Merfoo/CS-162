#include "Util.h"
#include <iostream>
#include <time.h>

void Util::initRandomNumber()
{
	srand(time(0));
}

int Util::getRandomInt(int min, int max)
{
	return (rand() % (max - min)) + min;
}