#include "BlueMen.h"

BlueMen::BlueMen()
{
	m_strength = 12;
	m_armor = 3;

	m_defDices.push_back(Dice(6));
	m_defDices.push_back(Dice(6));
	m_defDices.push_back(Dice(6));

	m_atkDices.push_back(Dice(10));
	m_atkDices.push_back(Dice(10));

	m_type = Creature::Type::BLUE_MEN;
}

BlueMen::~BlueMen()
{
}

int BlueMen::defend(int atk)
{
	int dmg = Creature::defend(atk);

	if (m_strength / 4 < m_defDices.size())
	{
		m_defDices.pop_back();
		std::cout << "Lost a def dice!" << std::endl;
	}

	return dmg;
}