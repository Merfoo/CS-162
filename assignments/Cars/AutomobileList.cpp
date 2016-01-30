#include "AutomobileList.h"

AutomobileList::AutomobileList()
{
}

AutomobileList::~AutomobileList()
{
}

void AutomobileList::add(Automobile automobile)
{
	m_list.addItem(automobile);
}

void AutomobileList::remove(int index)
{
	m_list.removeItem(index);
}

void AutomobileList::set(int index, Automobile automobile)
{
	m_list.setItem(index, automobile);
}

int AutomobileList::getLength()
{
	return m_list.getLength();
}

Automobile AutomobileList::get(int index)
{
	return m_list.getItem(index);
}

List<int> AutomobileList::searchByHorsepower(int horsepower)
{
	List<int> list;

	for (int i = 0; i < m_list.getLength(); i++)
		if (m_list.getItem(i).getHorsepower() == horsepower)
			list.addItem(i);

	return list;
}

List<int> AutomobileList::searchByLotNumber(int lotNumber)
{
	List<int> list;

	for (int i = 0; i < m_list.getLength(); i++)
		if (m_list.getItem(i).getLotNumber() == lotNumber)
			list.addItem(i);

	return list;
}

List<int> AutomobileList::searchByMileage(double mileage)
{
	List<int> list;

	for (int i = 0; i < m_list.getLength(); i++)
		if (m_list.getItem(i).getMileage() == mileage)
			list.addItem(i);

	return list;
}

List<int> AutomobileList::searchByMpg(double mpg)
{
	List<int> list;

	for (int i = 0; i < m_list.getLength(); i++)
		if (m_list.getItem(i).getMpg() == mpg)
			list.addItem(i);

	return list;
}

List<int> AutomobileList::searchByPrice(double price)
{
	List<int> list;

	for (int i = 0; i < m_list.getLength(); i++)
		if (m_list.getItem(i).getPrice() == price)
			list.addItem(i);

	return list;
}

List<int> AutomobileList::searchByMake(std::string make)
{
	List<int> list;

	for (int i = 0; i < m_list.getLength(); i++)
		if (m_list.getItem(i).getMake() == make)
			list.addItem(i);

	return list;
}

List<int> AutomobileList::searchByModel(std::string model)
{
	List<int> list;

	for (int i = 0; i < m_list.getLength(); i++)
		if (m_list.getItem(i).getModel() == model)
			list.addItem(i);

	return list;
}

List<int> AutomobileList::searchByColor(std::string color)
{
	List<int> list;

	for (int i = 0; i < m_list.getLength(); i++)
		if (m_list.getItem(i).getColor() == color)
			list.addItem(i);

	return list;
}

List<int> AutomobileList::searchByNumberOfDoors(int numberOfDoors)
{
	List<int> list;

	for (int i = 0; i < m_list.getLength(); i++)
		if (m_list.getItem(i).getNumberOfDoors() == numberOfDoors)
			list.addItem(i);

	return list;
}