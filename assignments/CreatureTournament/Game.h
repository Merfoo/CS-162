#pragma once

#include "Creature.h"
#include "LinkedList.h"

class Game
{
public:
	Game();
	~Game();
	
	void play();

private:
	bool attack(Creature* attacker, Creature* defender);
	void getTeam(LinkedList& team, std::string teamName);
};