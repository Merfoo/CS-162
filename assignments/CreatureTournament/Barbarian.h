#pragma once

#include <iostream>
#include "Creature.h"

class Barbarian : public Creature
{
public:
	Barbarian(std::string name);
	~Barbarian();

	virtual void restore();
};