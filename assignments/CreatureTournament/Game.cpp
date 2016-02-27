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

void Game::getLowestPoints(LinkedList& src, LinkedList& dest)
{
	for (int i = 0; i < 3 && src.size() > 0; i++)
	{
		src.resetNext();

		int smallest = src.getNext()->getPoints();
		int index = 0;

		for (int j = 1; j < src.size(); j++)
		{
			int currPoints = src.getNext()->getPoints();

			if (currPoints < smallest)
			{
				smallest = currPoints;
				index = j;
			}
		}

		dest.pushBack(src.pop(index));
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

		std::cout << a->getName();
		std::cout << " vs ";
		std::cout << b->getName();
		std::cout << std::endl;

		while (true)
		{
			// A won
			if (attack(a, b))
			{
				winner = a;
				teamA.pushBack(a);
				b->setPoints(0);
				losers.pushFront(b);
				break;
			}

			// B won
			else if (attack(b, a))
			{
				winner = b;
				teamB.pushBack(b);
				a->setPoints(0);
				losers.pushFront(a);
				break;
			}
		}

		std::cout << "Fighter " << winner->getName() << " won!" << std::endl;
		std::cout << "\tType: " << winner->getReadableType() << std::endl;
		int currStr = winner->getStrength();
		winner->restore();
		winner->setPoints(winner->getPoints() + (winner->getStrength() - currStr));
		std::cout << std::endl;
	}

	std::string winningTeam = (teamA.size() > 0 ? "A" : "B");
	LinkedList winners;
	teamA.size() > 0 ? getLowestPoints(teamA, winners) : getLowestPoints(teamB, winners);
	
	if (winners.size() < 3)
		while (winners.size() < 3 && losers.size() > 0)
			winners.pushBack(losers.popFront());
	
	std::cout << "Team " << winningTeam << " scored the most points!" << std::endl;
	std::cout << "WINNERS" << std::endl;

	winners.resetNext();

	for (int i = 0; i < winners.size(); i++)
	{
		std::cout << (i + 1) << ")" << std::endl;
		Creature* creature = winners.getNext();
		std::cout << "\tType: " << creature->getReadableType() << std::endl;
		std::cout << "\tName: " << creature->getName() << std::endl;
		std::cout << "\tPoints: " << creature->getPoints() << std::endl;
	}

	std::cout << "Display losers? [y] [n]" << std::endl;
	std::string input;

	while (true)
	{
		getline(std::cin, input);

		if (input != "y" && input != "n")
			std::cout << "Invalid input!" << std::endl;

		else
			break;
	}

	if (input == "y")
	{
		std::cout << "LOSERS" << std::endl;
		int place = winners.size();

		while (losers.size() > 0)
		{
			Creature* creature = losers.popFront();
			std::cout << (++place) << ")" << std::endl;
			std::cout << "\tType: " << creature->getReadableType() << std::endl;
			std::cout << "\tName: " << creature->getName() << std::endl;
			std::cout << "\tPoints: " << creature->getPoints() << std::endl;
			delete creature;
		}
	}
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
