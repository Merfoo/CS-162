#include "Gollum.h"

Gollum::Gollum()
{
	m_strength = 8;
	m_armor = 1;

	m_defDices.push_back(Dice(6));
	m_defDices.push_back(Dice(6));

	m_atkDices.push_back(Dice(6));

	m_type = Creature::Type::GOLLUM;

	m_specialAtk.push_back(Dice(6));
	m_specialAtk.push_back(Dice(6));
	m_specialAtk.push_back(Dice(6));
}

Gollum::~Gollum()
{
}

int Gollum::getAttackValue()
{
	int atk = 0;

	if (getRandomInt(0, 100) < 5)
	{
		for (int i = 0; i < m_specialAtk.size(); i++)
			atk += m_specialAtk.at(i).get();

		std::cout << "Atk: " << atk << std::endl;
	}

	else
		atk = Creature::getAttackValue();

	return atk;
}