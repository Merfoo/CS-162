#include <iostream>
#include <string>
#include "Util.h"
#include "List.h"
#include "AutomobileList.h"
#include "Automobile.h"
#include "MotorcycleList.h"
#include "Motorcycle.h"

using namespace std;

bool userChoseVehicule()
{
	string input = "";
	bool car = false;

	while (true)
	{
		cout << "[m]otorcycle or [a]utomobile?" << endl;
		getline(cin, input);

		if (input == "m")
		{
			car = false;
			break;
		}

		if (input == "a")
		{
			car = true;
			break;
		}

		cout << "Invalid input!" << endl;
	}

	return car;
}

int main()
{
	AutomobileList automobileList;
	MotorcycleList motorcycleList;
	
	while (true)
	{
		cout << endl << endl;
		cout << "[1] Show all vehicules" << endl;
		cout << "[2] Adjust mileage for a vehicule" << endl;
		cout << "[3] Search for a vehicule" << endl;
		cout << "[4] Add a vehicule" << endl;
		cout << "[5] Buy a vehicule" << endl;
		cout << "[6] Exit" << endl;

		string input = "";
		getline(cin, input);

		// Print all data from every vehicule
		if (input == "1")
		{
			for (int i = 0; i < automobileList.getLength(); i++)
			{
				cout << "Automobile " << (i + 1) << ":" << endl;
				automobileList.get(i).printInfo();
			}

			for (int i = 0; i < motorcycleList.getLength(); i++)
			{
				cout << "Motorcycle " << (i + 1) << ":" << endl;
				motorcycleList.get(i).printInfo();
			}
		}

		// Adjust mileage for a vehicule
		else if (input == "2")
		{
			bool car = userChoseVehicule();

			if (car && automobileList.getLength() <= 0)
			{
				cout << "There are no automobiles for sale!" << endl;
				continue;
			}

			else if (!car && motorcycleList.getLength() <= 0)
			{
				cout << "There are no motorcycles for sale!" << endl;
				continue;
			}

			while (true)
			{
				cout << "Vehicule #: " << endl;
				int index;

				if (car)
				{
					index = getIntWithLimits(1, automobileList.getLength())-1;
					Automobile car = automobileList.get(index);
					car.askForMileage();
					automobileList.set(index, car);
					break;
				}

				else
				{
					index = getIntWithLimits(1, motorcycleList.getLength())-1;
					Motorcycle cycle = motorcycleList.get(index);
					cycle.askForMileage();
					motorcycleList.set(index, cycle);
					break;
				}

				cout << "Invalid input!" << endl;
			}
		}

		// Search for a vehicule
		else if (input == "3")
		{
			cout << "Search for ";
			bool car = userChoseVehicule();

			if (car && automobileList.getLength() <= 0)
			{
				cout << "There are no automobiles for sale!" << endl;
				continue;
			}

			else if (!car && motorcycleList.getLength() <= 0)
			{
				cout << "There are no motorcycles for sale!" << endl;
				continue;
			}

			List<int> results;

			while (true)
			{
				cout << "Search by" << endl;
				cout << "[1] Horsepower: " << endl;
				cout << "[2] Lot number: " << endl;
				cout << "[3] Mileage: " << endl;
				cout << "[4] MPG: " << endl;
				cout << "[5] Listing price: " << endl;
				cout << "[6] Make: " << endl;
				cout << "[7] Model: " << endl;
				cout << "[8] Color: " << endl;

				if (car)
					cout << "[9] Number of doors: " << endl;

				else
					cout << "[9] CC: " << endl;

				int iVal;
				double dVal;
				string sVal;

				getline(cin, input);

				if (car)
				{
					if (input == "1")
					{
						cout << "Horsepower: " << endl;
						iVal = getDoubleWithMin(0);
						results = automobileList.searchByHorsepower(iVal);
						break;
					}

					if (input == "2")
					{
						cout << "Lot number: " << endl;
						iVal = getDoubleWithMin(0);
						results = automobileList.searchByLotNumber(iVal);
						break;
					}

					if (input == "3")
					{
						cout << "Mileage: " << endl;
						dVal = getDoubleWithMin(0);
						results = automobileList.searchByMileage(dVal);
						break;
					}

					if (input == "4")
					{
						cout << "MPG: " << endl;
						dVal = getDoubleWithMin(0);
						results = automobileList.searchByMpg(dVal);
						break;
					}

					if (input == "5")
					{
						cout << "Listing Price: " << endl;
						dVal = getDoubleWithMin(0);
						results = automobileList.searchByPrice(dVal);
						break;
					}

					if (input == "6")
					{
						cout << "Make: " << endl;
						getline(cin, sVal);
						results = automobileList.searchByMake(sVal);
						break;
					}

					if (input == "7")
					{
						cout << "Model: " << endl;
						getline(cin, sVal);
						results = automobileList.searchByModel(sVal);
						break;
					}

					if (input == "8")
					{
						cout << "Color: " << endl;
						getline(cin, sVal);
						results = automobileList.searchByColor(sVal);
						break;
					}

					if (input == "9")
					{
						cout << "Number of doors: " << endl;
						iVal = getDoubleWithMin(0);
						results = automobileList.searchByNumberOfDoors(iVal);
						break;
					}

					else
						cout << "Invalid input!" << endl;
				}

				else
				{
					if (input == "1")
					{
						cout << "Horsepower: " << endl;
						iVal = getDoubleWithMin(0);
						results = motorcycleList.searchByHorsepower(iVal);
						break;
					}

					if (input == "2")
					{
						cout << "Lot number: " << endl;
						iVal = getDoubleWithMin(0);
						results = motorcycleList.searchByLotNumber(iVal);
						break;
					}

					if (input == "3")
					{
						cout << "Mileage: " << endl;
						dVal = getDoubleWithMin(0);
						results = motorcycleList.searchByMileage(dVal);
						break;
					}

					if (input == "4")
					{
						cout << "MPG: " << endl;
						dVal = getDoubleWithMin(0);
						results = motorcycleList.searchByMpg(dVal);
						break;
					}

					if (input == "5")
					{
						cout << "Listing Price: " << endl;
						dVal = getDoubleWithMin(0);
						results = motorcycleList.searchByPrice(dVal);
						break;
					}

					if (input == "6")
					{
						cout << "Make: " << endl;
						getline(cin, sVal);
						results = motorcycleList.searchByMake(sVal);
						break;
					}

					if (input == "7")
					{
						cout << "Model: " << endl;
						getline(cin, sVal);
						results = motorcycleList.searchByModel(sVal);
						break;
					}

					if (input == "8")
					{
						cout << "Color: " << endl;
						getline(cin, sVal);
						results = motorcycleList.searchByColor(sVal);
						break;
					}

					if (input == "9")
					{
						cout << "CC: " << endl;
						iVal = getDoubleWithMin(0);
						results = motorcycleList.searchByCc(iVal);
						break;
					}

					else
						cout << "Invalid input!" << endl;
				}
			}

			cout << endl;

			for (int i = 0; i < results.getLength(); i++)
			{
				if (car)
				{
					cout << "Automobile " << (results.getItem(i) + 1) << endl;
					automobileList.get(results.getItem(i)).printInfo();
				}

				else
				{
					cout << "Motorcycle " << (results.getItem(i) + 1) << endl;
					motorcycleList.get(results.getItem(i)).printInfo();
				}
			}
		}

		// Add a vehicule
		else if (input == "4")
		{
			bool car = userChoseVehicule();

			if (car)
			{
				Automobile car;
				car.askForData();
				automobileList.add(car);
			}

			else
			{
				Motorcycle cycle;
				cycle.askForData();
				motorcycleList.add(cycle);
			}
		}

		// Buy a vehicule, aka remove it from its list
		else if (input == "5")
		{
			cout << "Buy a ";
			bool car = userChoseVehicule();

			if (car && automobileList.getLength() <= 0)
			{
				cout << "There are no automobiles for sale!" << endl;
				continue;
			}

			else if (!car && motorcycleList.getLength() <= 0)
			{
				cout << "There are no motorcycles for sale!" << endl;
				continue;
			}

			while (true)
			{
				bool willBuy = true;
				cout << "Vehicule #: " << endl;
				int index;
 
				if (car)
				{
					index = getIntWithLimits(1, automobileList.getLength())-1;
					cout << "This vehicule is "
						<< automobileList.get(index).getPrice()
						<< " dollars" << endl;
					cout << "Are you sure? [y]es [n]o" << endl;
					
					while (true)
					{
						getline(cin, input);

						if (input == "y")
							break;

						else if (input == "n")
						{
							willBuy = false;
							break;
						}
					}

					if (willBuy)
					{
						automobileList.remove(index);
						cout << "You bought automobile " << (index + 1) << endl;
					}

					break;
				}

				else
				{
					index = getIntWithLimits(1, motorcycleList.getLength())-1;
					cout << "This vehicule is "
						<< motorcycleList.get(index).getPrice()
						<< " dollars" << endl;
					cout << "Are you sure? [y]es [n]o" << endl;

					while (true)
					{
						getline(cin, input);

						if (input == "y")
							break;

						else if (input == "n")
						{
							willBuy = false;
							break;
						}
					}

					if (willBuy)
					{
						motorcycleList.remove(index);
						cout << "You bought motorcycle " << (index + 1) << endl;
					}

					break;
				}

				cout << "Invalid input!" << endl;
			}
		}

		// Exit program
		else if (input == "6")
		{
			cout << "Bye!" << endl;
			break;
		}

		else
			cout << "Invalid input!" << endl;
	}

	return 0;
}