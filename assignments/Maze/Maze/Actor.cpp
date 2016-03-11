#include "Actor.h"

Actor::Actor()
{
	m_x = 0;
	m_y = 0;
}

Actor::~Actor()
{
}

void Actor::setPos(Point pos)
{
	m_x = pos.getX();
	m_y = pos.getY();
}

void Actor::setPos(int x, int y)
{
	m_x = x;
	m_y = y;
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