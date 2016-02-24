#pragma once

class Dice
{
public:
	Dice(int sides);
	~Dice();

	void setSides(int sides);

	int get();

private:
	int m_sides;
};