#pragma once

#include <iostream>
#include <vector>
#include "Creature.h"
#include "Dice.h"
#include "Util.h"

class Gollum : public Creature
{
public:
	Gollum();
	~Gollum();

	virtual int getAttackValue();
private:
	std::vector<Dice> m_specialAtk;
};