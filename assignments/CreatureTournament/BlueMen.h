#pragma once

#include <iostream>
#include "Creature.h"

class BlueMen : public Creature
{
public:
	BlueMen(std::string name);
	~BlueMen();

	virtual void restore();

	virtual int defend(int atk);
};