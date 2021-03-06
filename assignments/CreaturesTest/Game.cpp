#include "Game.h"
#include "Util.h"

Game::Game()
{
	m_creatures.push_back(new Gollum);
	m_creatures.push_back(new Barbarian);
	m_creatures.push_back(new BabaYaga);
	m_creatures.push_back(new BlueMen);
	m_creatures.push_back(new Unicorn);
}

Game::~Game()
{
	for (int i = 0; i < m_creatures.size(); i++)
		delete m_creatures.at(i);
}

void Game::play()
{
	Creature* a = 0;
	Creature* b = 0;
	int indexA = 0;
	int indexB = 0;

	while (true)
	{
		bool aUni = a != 0 ? a->getType() == Creature::Type::UNICORN : false;
		bool bUni = b != 0 ? b->getType() == Creature::Type::UNICORN : false;

		if (!(aUni && bUni))
		{
			indexA = getRandomInt(0, m_creatures.size());
			indexB = 0;

			while ((indexB = getRandomInt(0, m_creatures.size())) == indexA);

			a = m_creatures.at(indexA);
			b = m_creatures.at(indexB);
		}

		std::cout << "NEW BATTLE" << std::endl;

		if (attack(a, b))
		{
			delete b;
			b = 0;
			m_creatures.erase(m_creatures.begin() + indexB);
		}

		else if (attack(b, a))
		{
			delete a;
			a = 0;
			m_creatures.erase(m_creatures.begin() + indexA);
		}

		if (m_creatures.size() == 1)
			break;
	}

	std::cout << "The winner is: " << m_creatures.at(0)->getReadableType()
		<< "!" << std::endl;
}

bool Game::attack(Creature* attacker, Creature* defender)
{
	std::cout << "Before attack:" << std::endl;
	std::cout << "Attacker: " << attacker->getReadableType() << std::endl;
	std::cout << "Attacker Strength: " << attacker->getStrength() << std::endl;
	std::cout << "Attacker Armor: " << attacker->getArmor() << std::endl;
	std::cout << "Defender: " << defender->getReadableType() << std::endl;
	std::cout << "Defender Strength: " << defender->getStrength() << std::endl;
	std::cout << "Defender Armor: " << defender->getArmor() << std::endl;

	attacker->attack(defender);

	std::cout << "After attack:" << std::endl;
	std::cout << "Attacker: " << attacker->getReadableType() << std::endl;
	std::cout << "Attacker Strength: " << attacker->getStrength() << std::endl;
	std::cout << "Attacker Armor: " << attacker->getArmor() << std::endl;
	std::cout << "Defender: " << defender->getReadableType() << std::endl;
	std::cout << "Defender Strength: " << defender->getStrength() << std::endl;
	std::cout << "Defender Armor: " << defender->getArmor() << std::endl;
	std::cout << std::endl;

	if (defender->getStrength() <= 0)
		return true;

	return false;
}
