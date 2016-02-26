#pragma once

#include <iostream>
#include <vector>
#include "Creature.h"
#include "Dice.h"
#include "Util.h"

class Gollum : public Creature
{
public:
	Gollum(std::string name);
	~Gollum();

	virtual void restore();

	virtual int getAttackValue();

private:
	std::vector<Dice> m_specialAtk;
};