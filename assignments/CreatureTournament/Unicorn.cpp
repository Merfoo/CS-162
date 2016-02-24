#include "Unicorn.h"

Unicorn::Unicorn()
{
	m_strength = 18;
	m_armor = 3;

	m_defDices.push_back(Dice(6));
	m_defDices.push_back(Dice(6));

	m_atkDices.push_back(Dice(20));
	m_atkDices.push_back(Dice(6));
	m_atkDices.push_back(Dice(6));

	m_type = Creature::Type::UNICORN;

	m_atkMode = false;
}

Unicorn::~Unicorn()
{
}

void Unicorn::attack(Creature* victim)
{
	int atk = 0;

	if (m_atkMode || victim->getType() == Creature::Type::UNICORN)
	{
		atk = getAttackValue();
		m_atkMode = false;
	}

	victim->defend(atk);
}

int Unicorn::defend(int attack)
{
	int dmgTaken = Creature::defend(attack);

	if (dmgTaken > 0)
		m_atkMode = true;

	return dmgTaken;
}