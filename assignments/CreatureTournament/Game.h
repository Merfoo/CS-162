#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "LinkedList.h"
#include "Creature.h"
#include "Gollum.h"
#include "Barbarian.h"
#include "BabaYaga.h"
#include "BlueMen.h"
#include "Unicorn.h"

class Game
{
public:
	Game();
	~Game();
	
	void play();

private:
	bool attack(Creature* attacker, Creature* defender);
	
	std::vector<Creature*> m_creatures;
};