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

};