#include "BabaYaga.h"

BabaYaga::BabaYaga(std::string name)
{
	m_strength = 12;
	m_armor = 3;
	m_defDices.push_back(Dice(10));
	m_atkDices.push_back(Dice(6));
	m_type = Creature::Type::BABA_YAGA;
	m_name = name;

}

BabaYaga::~BabaYaga()
{
}

void BabaYaga::restore()
{
	m_strength = 12;
	m_armor = 3;
}

void BabaYaga::attack(Creature* victim)
{
	int damagedTaken = victim->defend(getAttackValue());

	if (damagedTaken > 0)
		m_strength += damagedTaken;
}