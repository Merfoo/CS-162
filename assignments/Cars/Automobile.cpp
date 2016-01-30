#include "Automobile.h"

Automobile::Automobile()
{
	m_numDoors = 0;
}

Automobile::~Automobile()
{
}

int Automobile::getNumberOfDoors()
{
	return m_numDoors;
}

void Automobile::setNumberOfDoors(int numberOfDoors)
{
	m_numDoors = numberOfDoors;
}

void Automobile::printInfo()
{
	Vehicule::printInfo();
	std::cout << "\tNumber of doors: " << m_numDoors << std::endl;
}

void Automobile::askForData()
{
	Vehicule::askForData();

	std::string input;
	std::cout << "Number of doors: " << std::endl;
	m_numDoors = getDoubleWithMin(0);
}