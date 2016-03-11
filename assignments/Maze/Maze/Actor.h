#pragma once
#include "Point.h"
#include "Level.h"

class Actor
{
public:
	Actor();
	virtual ~Actor();
	virtual void update(Level& level) = 0;
	void setPos(Point pos);
	void setPos(int x, int y);
	int getX();
	int getY();
	char getSymbol();

protected:
	int m_x;
	int m_y;
	char m_symbol;
};