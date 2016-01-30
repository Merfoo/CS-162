#include "Vehicule.h"

Vehicule::Vehicule()
{
	m_horsepower = 0;
	m_lotNum = 0;
	m_mileage = 0.0;
	m_mpg = 0.0;
	m_price = 0.0;
	m_make = "Default";
	m_model = "Default";
	m_color = "Default";
}

Vehicule::~Vehicule()
{
}

int Vehicule::getHorsepower()
{
	return m_horsepower;
}

void Vehicule::setHorsepower(int horsepower)
{
	m_horsepower = horsepower;
}

int Vehicule::getLotNumber()
{
	return m_lotNum;
}

void Vehicule::setLotNumber(int lotNumber)
{
	m_lotNum = lotNumber;
}

double Vehicule::getMileage()
{
	return m_mileage;
}

void Vehicule::setMileage(double mileage)
{
	m_mileage = mileage;
}

double Vehicule::getMpg()
{
	return m_mpg;
}

void Vehicule::setMpg(double mpg)
{
	m_mpg = mpg;
}

double Vehicule::getPrice()
{
	return m_price;
}

void Vehicule::setPrice(double price)
{
	m_price = price;
}

std::string Vehicule::getMake()
{
	return m_make;
}

void Vehicule::setMake(std::string make)
{
	m_make = make;
}

std::string Vehicule::getModel()
{
	return m_model;
}

void Vehicule::setModel(std::string model)
{
	m_model = model;
}

std::string Vehicule::getColor()
{
	return m_color;
}

void Vehicule::setColor(std::string color)
{
	m_color = color;
}

void Vehicule::askForMileage()
{
	double mileage = 0.0;

	while (true)
	{
		std::cout << "New mileage: " << std::endl;
		mileage = getDouble();

		if (mileage < 0.0)
		{
			std::cout << "Invalid mileage!" << std::endl;
			continue;
		}

		break;
	}

	m_mileage = mileage;
}

void Vehicule::askForPrice()
{
	double val;
	std::string input;

	while (true)
	{
		val = getDoubleWithMin(0);

		if (val >= 10000)
		{
			std::cout << "Are you sure?" << std::endl;
			std::cout << "\t[y]es" << std::endl;
			std::cout << "\t[n]o" << std::endl;
			getline(std::cin, input);

			if (input == "y")
				break;

			if (input == "n")
				continue;

			std::cout << "Invalid input!" << std::endl;
		}

		else
			break;
	}

	m_price = val;
}

void Vehicule::askForData()
{
	std::string input;

	std::cout << "Listing price: " << std::endl;
	askForPrice();

	std::cout << "Horsepower: " << std::endl;
	m_horsepower = getDoubleWithMin(0);

	std::cout << "Lot number: " << std::endl;
	m_lotNum = getDoubleWithMin(0);

	std::cout << "Mileage: " << std::endl;
	m_mileage = getDoubleWithMin(0);

	std::cout << "MPG: " << std::endl;
	m_mpg = getDoubleWithMin(0);

	std::cout << "Make: " << std::endl;
	getline(std::cin, m_make);

	std::cout << "Model: " << std::endl;
	getline(std::cin, m_model);

	std::cout << "Color: " << std::endl;
	getline(std::cin, m_color);
}

void Vehicule::printInfo()
{
	std::cout << "\tHorsepower: " << m_horsepower << std::endl;
	std::cout << "\tLot number: " << m_lotNum << std::endl;
	std::cout << "\tMileage: " << m_mileage << std::endl;
	std::cout << "\tMPG: " << m_mpg << std::endl;
	std::cout << "\tListing price: " << m_price << std::endl;
	std::cout << "\tMake: " << m_make << std::endl;
	std::cout << "\tModel: " << m_model << std::endl;
	std::cout << "\tColor: " << m_color << std::endl;
}