#ifndef AUTOMOBILE_LIST_H
#define AUTOMOBILE_LIST_H

#include <iostream>
#include "List.h"
#include "Automobile.h"

class AutomobileList
{
public:
	AutomobileList();
	~AutomobileList();

	void add(Automobile motorcyle);
	void remove(int index);
	void set(int index, Automobile Automobile);

	int getLength();

	Automobile get(int index);

	List<int> searchByHorsepower(int horsepower);
	List<int> searchByLotNumber(int lotNumber);
	List<int> searchByMileage(double mileage);
	List<int> searchByMpg(double mpg);
	List<int> searchByPrice(double price);
	List<int> searchByMake(std::string make);
	List<int> searchByModel(std::string model);
	List<int> searchByColor(std::string color);
	List<int> searchByNumberOfDoors(int numberOfDoors);

private:
	List<Automobile> m_list;
};

#endif // AUTOMOBILE_LIST_H