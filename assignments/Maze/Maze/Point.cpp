#include "Point.h"

Point::Point()
{
	m_x = 0;
	m_y = 0;
}

Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
}

Point::~Point()
{
}

bool Point::operator==(const Point& point)
{
	return m_x == point.m_x && m_y == point.m_y;
}

void Point::set(int x, int y)
{
	m_x = x;
	m_y = y;
}

int Point::getX()
{
	return m_x;
}

int Point::getY()
{
	return m_y;
}