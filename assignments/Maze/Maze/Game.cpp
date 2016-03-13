#include "Game.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Util.h"
#include "Player.h"
#include "Swan.h"

using namespace std;
using namespace Util;

Game::Game()
{
	m_gameSteps = 0;
	m_levelsLength = 0;
	m_levels = 0;
	m_actors = 0;
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
	Player* player = (Player*)m_actors[0];

	while (true)
	{
		m_gameSteps++;
		m_levels[levelIndex].print(m_actors, m_actorsLength);
		cout << "Apples: " << player->getApples();
		cout << ", Keys: " << player->getKeys();
		cout << ", Game Step: " << m_gameSteps << endl;

		if ((m_gameSteps + 1) % m_swanSpawnSteps == 0)
			spawnSwan(m_levels[levelIndex]);

		for (int i = 0; i < m_actorsLength; i++)
			m_actors[i]->update(m_levels[levelIndex]);

		if (m_levels[levelIndex].shouldLoadNext())
		{
			if (++levelIndex < numberOfLevels)
			{
				m_levels[levelIndex] = m_levels[levelIndex];
				setupActors(m_levels[levelIndex]);
                m_gameSteps = 0;
			}

			else
			{
				cout << "You have escaped the maze!" << endl;
				break;
			}
		}

		else if (m_levels[levelIndex].shouldQuit())
		{
			cout << "Bye you quitter!" << endl;
			break;
		}

		else if (!player->immuneToSwans())
			for (int i = 1; i < m_actorsLength; i++)
				if (nextToEachOther(player, m_actors[i]))
					player->setPos(m_levels[levelIndex].getPlayerSpawnPos());
	}
}

bool Game::nextToEachOther(Actor* a, Actor* b)
{
	return abs(a->getX() - b->getX()) <= 1 && abs(a->getY() - b->getY()) <= 1;
}

bool Game::createLevels(int numberOfLevels)
{
	if (m_levels != 0)
		delete[] m_levels;

	m_levelsLength = numberOfLevels;
	m_levels = new Level[m_levelsLength];

	for (int i = 0; i < m_levelsLength; i++)
	{
		string filename = "floor_" + to_string((long long)(i + 1)) + ".txt";

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

void Game::spawnSwan(Level& level)
{
	Actor** tmp = new Actor*[m_actorsLength + 1];

	for (int i = 0; i < m_actorsLength; i++)
		tmp[i] = m_actors[i];

	Swan* swan = new Swan;

	while (!level.isEmpty(swan->getX(), swan->getY()))
	{
		int x = getRandomInt(0, level.getBoardWidth());
		int y = getRandomInt(0, level.getBoardHeight());
		swan->setPos(x, y);
	}
	
	tmp[m_actorsLength] = swan;
	delete[] m_actors;
	m_actors = tmp;
	m_actorsLength++;
}
