#include <stdlib.h>
#include <time.h>
#include "Util.h"
#include <iostream>
#include <string>

void initRandomNumber()
{
	srand(time(0));
}

int getRandomInt(int min, int max)
{
	return (rand() % (max - min)) + min;
}

int getInt()
{
	int val = 0;

	while (true)
	{
		std::string input;
		getline(std::cin, input);

		try
		{
			val = stoi(input);
			break;
		}

		catch (...)
		{
			std::cout << "Invalid input!" << std::endl;
		}
	}

	return val;
}