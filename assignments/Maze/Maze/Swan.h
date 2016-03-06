#pragma once
#include "Actor.h"
#include "Level.h"

class Swan : public Actor
{
public:
	Swan();
	~Swan();
	virtual void update(Level& level);
};