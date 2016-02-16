#pragma once

#include "Creature.h"

class BabaYaga : public Creature
{
public:
	BabaYaga();
	~BabaYaga();

	virtual void attack(Creature* victim);
};