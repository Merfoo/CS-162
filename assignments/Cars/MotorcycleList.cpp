#include "MotorcycleList.h"

MotorcycleList::MotorcycleList()
{
}

MotorcycleList::~MotorcycleList()
{
}

void MotorcycleList::add(Motorcycle motorcycle)
{
	m_list.addItem(motorcycle);
}

void MotorcycleList::remove(int index)
{
	m_list.removeItem(index);
}

void MotorcycleList::set(int index, Motorcycle motorcycle)
{
	m_list.setItem(index, motorcycle);
}

int MotorcycleList::getLength()
{
	return m_list.getLength();
}

Motorcycle MotorcycleList::get(int index)
{
	return m_list.getItem(index);
}

List<int> MotorcycleList::searchByHorsepower(int horsepower)
{
	List<int> list;

	for (int i = 0; i < m_list.getLength(); i++)
		if (m_list.getItem(i).getHorsepower() == horsepower)
			list.addItem(i);

	return list;
}

List<int> MotorcycleList::searchByLotNumber(int lotNumber)
{
	List<int> list;

	for (int i = 0; i < m_list.getLength(); i++)
		if (m_list.getItem(i).getLotNumber() == lotNumber)
			list.addItem(i);

	return list;
}

List<int> MotorcycleList::searchByMileage(double mileage)
{
	List<int> list;

	for (int i = 0; i < m_list.getLength(); i++)
		if (m_list.getItem(i).getMileage() == mileage)
			list.addItem(i);

	return list;
}

List<int> MotorcycleList::searchByMpg(double mpg)
{
	List<int> list;

	for (int i = 0; i < m_list.getLength(); i++)
		if (m_list.getItem(i).getMpg() == mpg)
			list.addItem(i);

	return list;
}

List<int> MotorcycleList::searchByPrice(double price)
{
	List<int> list;

	for (int i = 0; i < m_list.getLength(); i++)
		if (m_list.getItem(i).getPrice() == price)
			list.addItem(i);

	return list;
}

List<int> MotorcycleList::searchByMake(std::string make)
{
	List<int> list;

	for (int i = 0; i < m_list.getLength(); i++)
		if (m_list.getItem(i).getMake() == make)
			list.addItem(i);

	return list;
}

List<int> MotorcycleList::searchByModel(std::string model)
{
	List<int> list;

	for (int i = 0; i < m_list.getLength(); i++)
		if (m_list.getItem(i).getModel() == model)
			list.addItem(i);

	return list;
}

List<int> MotorcycleList::searchByColor(std::string color)
{
	List<int> list;

	for (int i = 0; i < m_list.getLength(); i++)
		if (m_list.getItem(i).getColor() == color)
			list.addItem(i);

	return list;
}

List<int> MotorcycleList::searchByCc(int cc)
{
	List<int> list;

	for (int i = 0; i < m_list.getLength(); i++)
		if (m_list.getItem(i).getCc() == cc)
			list.addItem(i);

	return list;
}