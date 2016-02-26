#pragma once

#include <iostream>
#include "Creature.h"

class BabaYaga : public Creature
{
public:
	BabaYaga(std::string name);
	~BabaYaga();

	virtual void restore();

	virtual void attack(Creature* victim);
};