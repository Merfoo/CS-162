#include "Util.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

namespace Util
{
	void initRandomNumber()
	{
		srand(time(0));
	}

	int getRandomInt(int min, int max)
	{
		return (rand() % (max - min)) + min;
	}

	int readInt()
	{
		int val;

		while (true)
		{
			string input;
			getline(cin, input);

			try
			{
				val = stoi(input);
				break;
			}

			catch (...)
			{
				cout << "Invalid input!" << endl;
			}
		}

		return val;
	}
}