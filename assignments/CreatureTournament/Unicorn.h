#pragma once

#include <iostream>
#include "Creature.h"

class Unicorn : public Creature
{
public:
	Unicorn(std::string name);
	~Unicorn();

	virtual void restore();

	virtual void attack(Creature* victim);
	virtual int defend(int attack);

private:
	bool m_atkMode;
};