#include "Actor.h"

Actor::Actor()
{
}

Actor::~Actor()
{
}

void Actor::setPos(Point pos)
{
	m_x = pos.getX();
	m_y = pos.getY();
}

int Actor::getX()
{
	return m_x;
}

int Actor::getY()
{
	return m_y;
}

char Actor::getSymbol()
{
	return m_symbol;
}