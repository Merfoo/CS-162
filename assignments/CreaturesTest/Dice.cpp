#include "Dice.h"
#include "Util.h"

Dice::Dice(int sides)
{
	m_sides = sides;
}

Dice::~Dice()
{
}

void Dice::setSides(int sides)
{
	m_sides = sides;
}

int Dice::get()
{
	return getRandomInt(1, m_sides + 1);
}