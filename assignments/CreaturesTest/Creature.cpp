#include "Creature.h"

Creature::Creature()
{
}

Creature::~Creature()
{
}

void Creature::attack(Creature* victim)
{
	victim->defend(getAttackValue());
}

int Creature::defend(int attackValue)
{
	int dmg = attackValue - getDefenseValue() - m_armor;

	if (dmg > 0)
	{
		m_strength -= dmg;
		return dmg;
	}

	return 0;
}

int Creature::getAttackValue()
{
	int atk = 0;

	for (int i = 0; i < m_atkDices.size(); i++)
		atk += m_atkDices.at(i).get();

	std::cout << "Atk: " << atk << std::endl;
	return atk;
}

int Creature::getDefenseValue()
{
	int def = 0;

	for (int i = 0; i < m_defDices.size(); i++)
		def += m_defDices.at(i).get();

	std::cout << "Def: " << def << std::endl;
	return def;
}

void Creature::setStrength(int strength)
{
	m_strength = strength;
}

int Creature::getStrength()
{
	return m_strength;
}

int Creature::getArmor()
{
	return m_armor;
}

Creature::Type Creature::getType()
{
	return m_type;
}

std::string Creature::getReadableType()
{
	if (m_type == Creature::Type::BABA_YAGA)
		return "BABA_YAGA";

	if (m_type == Creature::Type::BARBARIAN)
		return "BARBARIAN";

	if (m_type == Creature::Type::BLUE_MEN)
		return "BLUE_MEN";

	if (m_type == Creature::Type::GOLLUM)
		return "GOLLUM";

	if (m_type == Creature::Type::UNICORN)
		return "UNICORN";

	return "UNKOWN";
}