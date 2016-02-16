#pragma once

#include <iostream>
#include <vector>
#include "Dice.h"

class Creature
{
public:
	enum Type {GOLLUM, BARBARIAN, BABA_YAGA, BLUE_MEN, UNICORN};

	Creature();
	virtual ~Creature() = 0;

	virtual void attack(Creature* victim);
	virtual int defend(int attackValue);

	virtual int getAttackValue();
	int getDefenseValue();

	void setStrength(int strength);
	int getStrength();

	int getArmor();

	Type getType();
	std::string getReadableType();

protected:
	int m_strength;
	int m_armor;
	std::vector<Dice> m_defDices;
	std::vector<Dice> m_atkDices;
	Type m_type;
};
