#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Dice.h"

class Creature
{
public:
	enum Type {GOLLUM, BARBARIAN, BABA_YAGA, BLUE_MEN, UNICORN};

	Creature();
	virtual ~Creature() = 0;

	virtual void restore() = 0;

	virtual void attack(Creature* victim);
	virtual int defend(int attackValue);

	virtual int getAttackValue();
	int getDefenseValue();

	void setStrength(int strength);
	int getStrength();

	int getArmor();

	Type getType();
	std::string getReadableType();

	void setName(std::string name);
	std::string getName();

	void setPoints(int points);
	int getPoints();

	void print();

protected:
	int m_points;
	int m_strength;
	int m_armor;
	std::vector<Dice> m_defDices;
	std::vector<Dice> m_atkDices;
	Type m_type;
	std::string m_name;
};
