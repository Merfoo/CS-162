#pragma once
#include "Actor.h"
#include "Level.h"

class Player : public Actor
{
public:
	Player();
	~Player();
	virtual void update(Level& level);

private:
	bool move(Level& level, char command);
	bool eatApple();
	char getInput();

	int m_apples;
	int m_keys;
};