#include <iostream>
#include <string>
#include "Game.h"
#include "Util.h"
#include "Gollum.h"
#include "Barbarian.h"
#include "BabaYaga.h"
#include "BlueMen.h"
#include "Unicorn.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::getTeam(LinkedList& team, std::string teamName)
{
	std::cout << "Number of fighters: ";
	int numberOfFighters = getInt();

	for (int i = 0; i < numberOfFighters; i++)
	{
		int type = 0;
		
		while (true)
		{
			std::string input;

			std::cout << "[1] Gollum" << std::endl;
			std::cout << "[2] Barbarian" << std::endl;
			std::cout << "[3] Baba Yaga" << std::endl;
			std::cout << "[4] Blue Men" << std::endl;
			std::cout << "[5] Unicorn" << std::endl;

			std::cout << "Fighter type: ";
			type = getInt();

			if (type > 0 && type < 6)
				break;

			std::cout << "Invalid fighter type!" << std::endl;
		}

		std::string name;
		std::cout << "Name of fighter: ";
		getline(std::cin, name);
		name = teamName + ": " + name;

		if (type == 1)
			team.pushBack(new Gollum(name));

		else if (type == 2)
			team.pushBack(new Barbarian(name));

		else if (type == 3)
			team.pushBack(new BabaYaga(name));

		else if (type == 4)
			team.pushBack(new BlueMen(name));

		else if (type == 5)
			team.pushBack(new Unicorn(name));
	}
}

void Game::play()
{
	LinkedList teamA;
	LinkedList teamB;
	LinkedList losers;

	std::cout << "Lineup for Team A" << std::endl;
	getTeam(teamA, "Team A");

	std::cout << "Lineup for Team B" << std::endl;
	getTeam(teamB, "Team B");

	std::cout << std::endl;

	while (teamA.size() > 0 && teamB.size() > 0)
	{
		Creature* a = teamA.popFront();
		Creature* b = teamB.popFront();
		Creature* winner;

		while (true)
		{
			// A won
			if (attack(a, b))
			{
				winner = a;
				teamA.pushBack(a);
				losers.pushBack(b);
				break;
			}

			// B won
			else if (attack(b, a))
			{
				winner = b;
				teamB.pushBack(b);
				losers.pushBack(a);
				break;
			}
		}

		std::cout << "Fighter " << winner->getName() << " won!" << std::endl;
		winner->print();
		int currStr = winner->getStrength();
		winner->restore();
		winner->setPoints(winner->getPoints() + (winner->getStrength() - currStr));
	}

	LinkedList winners;
}

bool Game::attack(Creature* attacker, Creature* defender)
{
	/*std::cout << "Before attack:" << std::endl;
	std::cout << "Attacker" << std::endl;
	attacker->print();
	std::cout << "Defender" << std::endl;
	defender->print();*/

	attacker->attack(defender);

	/*std::cout << "After attack:" << std::endl;
	std::cout << "Attacker" << std::endl;
	attacker->print();
	std::cout << "Defender" << std::endl;
	defender->print();
	std::cout << std::endl;*/

	if (defender->getStrength() <= 0)
		return true;

	return false;
}
