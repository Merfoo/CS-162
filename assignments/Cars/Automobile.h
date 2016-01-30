#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include <iostream>
#include <string>
#include "Vehicule.h"
#include "Util.h"

class Automobile: public Vehicule
{
	public:
		Automobile();
		~Automobile();

		int getNumberOfDoors();
		void setNumberOfDoors(int numberOfDoors);

		void printInfo();
		void askForData();

	private:
		int m_numDoors;
};

#endif // AUTOMOBILE_H