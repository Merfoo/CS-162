#pragma once
#include "Level.h"
#include "Actor.h"

class Game
{
public:
	Game();
	~Game();
	void play(int numberOfLevels);

private:
	bool createLevels(int numberOfLevels);
	void createActors();
	void setupActors(Level& level);

	int m_levelsLength;
	Level* m_levels;
	int m_actorsLength;
	Actor** m_actors;
};