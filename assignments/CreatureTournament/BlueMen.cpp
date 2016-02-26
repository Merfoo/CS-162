#include "BlueMen.h"

BlueMen::BlueMen(std::string name)
{
	m_strength = 12;
	m_armor = 3;
	m_defDices.push_back(Dice(6));
	m_defDices.push_back(Dice(6));
	m_defDices.push_back(Dice(6));
	m_atkDices.push_back(Dice(10));
	m_atkDices.push_back(Dice(10));
	m_type = Creature::Type::BLUE_MEN;
	m_name = name;
}

BlueMen::~BlueMen()
{
}

void BlueMen::restore()
{
	m_strength = 12;
	m_armor = 3;
	m_defDices.clear();
	m_defDices.push_back(Dice(6));
	m_defDices.push_back(Dice(6));
	m_defDices.push_back(Dice(6));
}

int BlueMen::defend(int atk)
{
	int dmg = Creature::defend(atk);

	if (m_strength / 4 < m_defDices.size())
	{
		m_defDices.pop_back();
		//std::cout << "Lost a def dice!" << std::endl;
	}

	return dmg;
}