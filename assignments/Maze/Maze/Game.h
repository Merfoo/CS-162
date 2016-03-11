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
	bool nextToEachOther(Actor* a, Actor* b);
	bool createLevels(int numberOfLevels);
	void createActors();
	void setupActors(Level& level);
	void spawnSwan(Level& level);

	const int m_swanSpawnSteps = 30;
	int m_gameSteps;
	int m_levelsLength;
	Level* m_levels;
	int m_actorsLength;
	Actor** m_actors;
};