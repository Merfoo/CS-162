#include "Barbarian.h"

Barbarian::Barbarian(std::string name)
{
	m_strength = 12;
	m_armor = 0;
	m_defDices.push_back(Dice(6));
	m_defDices.push_back(Dice(6));
	m_atkDices.push_back(Dice(6));
	m_atkDices.push_back(Dice(6));
	m_type = Creature::Type::BARBARIAN;
	m_name = name;
}

Barbarian::~Barbarian()
{
}

void Barbarian::restore()
{
	m_strength = 12;
	m_armor = 0;
}