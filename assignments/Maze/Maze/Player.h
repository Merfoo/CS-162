#pragma once
#include "Actor.h"
#include "Level.h"

class Player : public Actor
{
public:
	Player();
	~Player();
	virtual void update(Level& level);
	bool immuneToSwans();
	int getApples();
	int getKeys();

private:
	bool move(Level& level, char command);
	bool eatApple();
	char getInput();

	const int m_maxKeys = 3;
	const int m_maxApples = 2;
	const int m_stepsImmuneToSwans = 15;
	int m_stepsSinceEatenApple;
	int m_apples;
	int m_keys;
};