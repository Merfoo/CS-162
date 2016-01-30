#include "Motorcycle.h"

Motorcycle::Motorcycle()
{
	m_cc = 0;
}

Motorcycle::~Motorcycle()
{
}

int Motorcycle::getCc()
{
	return m_cc;
}

void Motorcycle::setCc(int cc)
{
	m_cc = cc;
}

void Motorcycle::printInfo()
{
	Vehicule::printInfo();
	std::cout << "\tCC: " << m_cc << std::endl;
}

void Motorcycle::askForData()
{
	Vehicule::askForData();

	std::string input;
	std::cout << "CC: " << std::endl;
	m_cc = getDoubleWithMin(0);
}