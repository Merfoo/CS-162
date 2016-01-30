#ifndef VEHICULE_H
#define VEHICULE_H

#include <iostream>
#include <string>
#include "Util.h"

class Vehicule
{
	public:
		Vehicule();
		virtual ~Vehicule() = 0;

		int getHorsepower();
		void setHorsepower(int horsepower);

		int getLotNumber();
		void setLotNumber(int lotNumber);

		double getMileage();
		void setMileage(double mileage);

		double getMpg();
		void setMpg(double mpg);

		double getPrice();
		void setPrice(double price);

		std::string getMake();
		void setMake(std::string make);

		std::string getModel();
		void setModel(std::string model);

		std::string getColor();
		void setColor(std::string color);

		void askForMileage();

	protected:
		void askForPrice();
		void askForData();
		void printInfo();

		int m_horsepower;
		int m_lotNum;
		double m_mileage;
		double m_mpg;
		double m_price;
		std::string m_make;
		std::string m_model;
		std::string m_color;
};

#endif