#pragma once

#include "Creature.h"

class Unicorn : public Creature
{
public:
	Unicorn();
	~Unicorn();

	virtual void attack(Creature* victim);
	virtual int defend(int attack);

private:
	bool m_atkMode;
};