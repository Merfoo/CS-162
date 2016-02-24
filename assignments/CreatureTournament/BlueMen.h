#pragma once

#include "Creature.h"

class BlueMen : public Creature
{
public:
	BlueMen();
	~BlueMen();

	virtual int defend(int atk);
};