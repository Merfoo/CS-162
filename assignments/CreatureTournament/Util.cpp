#include "Util.h"

void initRandomNumber()
{
	srand(time(0));
}

int getRandomInt(int min, int max)
{
	return (rand() % (max - min)) + min;
}