#pragma once

class Point
{
public:
	Point();
	Point(int x, int y);
	~Point();
	bool operator==(const Point& point);
	void set(int x, int y);
	int getX();
	int getY();

private:
	int m_x;
	int m_y;
};