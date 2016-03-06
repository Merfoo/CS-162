#include "Game.h"
#include <iostream>
#include <string>
#include "Player.h"
#include "Swan.h"

using namespace std;

Game::Game()
{
	m_levelsLength = 0;
	m_levels = 0;
}

Game::~Game()
{
	if (m_levels != 0)
		delete[] m_levels;

	if (m_actors != 0)
	{
		for (int i = 0; i < m_actorsLength; i++)
			delete m_actors[i];

		delete[] m_actors;
	}
}

void Game::play(int numberOfLevels)
{
	if (!createLevels(numberOfLevels))
		return;

	int levelIndex = 0;
	createActors();
	setupActors(m_levels[levelIndex]);

	while (true)
	{
		for (int i = 0; i < m_actorsLength; i++)
			m_actors[i]->update(m_levels[levelIndex]);

		m_levels[levelIndex].print(m_actors, m_actorsLength);
		
		int x;
		cin >> x;
	}
}

bool Game::createLevels(int numberOfLevels)
{
	m_levelsLength = numberOfLevels;

	if (m_levels != 0)
		delete[] m_levels;

	m_levels = new Level[m_levelsLength];

	for (int i = 0; i < m_levelsLength; i++)
	{
		string filename = "floor_" + to_string(i + 1) + ".txt";

		if (!m_levels[i].create(filename, i == m_levelsLength - 1))
			return false;
	}

	return true;
}

void Game::createActors()
{
	if (m_actors != 0)
	{
		for (int i = 0; i < m_actorsLength; i++)
			delete m_actors[i];

		delete[] m_actors;
	}

	m_actorsLength = 1;
	m_actors = new Actor*[m_actorsLength];
	m_actors[0] = new Player;
}

void Game::setupActors(Level& level)
{
	Actor* tmpPlayer = m_actors[0];

	for (int i = 1; i < m_actorsLength; i++)
		delete m_actors[i];

	delete[] m_actors;
	m_actorsLength = 2;
	m_actors = new Actor*[m_actorsLength];

	m_actors[0] = tmpPlayer;
	m_actors[1] = new Swan;
	
	m_actors[0]->setPos(level.getPlayerSpawnPos());
	m_actors[1]->setPos(level.getSwanSpawnPos());
}