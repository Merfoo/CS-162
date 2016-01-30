#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include <iostream>
#include <string>
#include "Vehicule.h"

class Motorcycle :public Vehicule
{
	public:
		Motorcycle();
		~Motorcycle();

		int getCc();
		void setCc(int cc);

		void printInfo();
		void askForData();

	private:
		int m_cc;

};

#endif // MOTORCYCLE_H