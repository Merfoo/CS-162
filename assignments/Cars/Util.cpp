#include "Util.h"

double getDouble()
{
	std::string input;
	double val = 0;

	while (true)
	{
		getline(std::cin, input);

		try
		{
			val = stod(input);
		}

		catch (...)
		{
			std::cout << "Invalid input!" << std::endl;
			continue;
		}

		break;
	}

	return val;
}

double getDoubleWithMin(double min)
{
	double val = 0.0;

	while (true)
	{
		val = getDouble();

		if (val >= min)
			break;

		std::cout << "Value too low!" << std::endl;
	}

	return val;
}

int getIntWithLimits(int min, int max)
{
	int val;

	while (true)
	{
		val = getDouble();

		if (val >= min && val <= max)
			break;

		std::cout << "Out of bounds!" << std::endl;
	}

	return val;
}