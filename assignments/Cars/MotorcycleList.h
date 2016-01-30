#ifndef MOTORCYCLE_LIST_H
#define MOTORCYCLE_LIST_H

#include <iostream>
#include "List.h"
#include "Motorcycle.h"

class MotorcycleList
{
	public:
		MotorcycleList();
		~MotorcycleList();

		void add(Motorcycle motorcyle);
		void remove(int index);
		void set(int index, Motorcycle motorcycle);

		int getLength();

		Motorcycle get(int index);

		List<int> searchByHorsepower(int horsepower);
		List<int> searchByLotNumber(int lotNumber);
		List<int> searchByMileage(double mileage);
		List<int> searchByMpg(double mpg);
		List<int> searchByPrice(double price);
		List<int> searchByMake(std::string make);
		List<int> searchByModel(std::string model);
		List<int> searchByColor(std::string color);
		List<int> searchByCc(int cc);

	private:
		List<Motorcycle> m_list;
};

#endif // MOTORCYCLE_LIST_H