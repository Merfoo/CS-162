#include "Swan.h"
#include "Util.h"

using namespace Util;

Swan::Swan()
{
	m_symbol = 'S';
}

Swan::~Swan()
{
}

void Swan::update(Level& level)
{
	int curX = m_x;
	int curY = m_y;
	int x = 0;
	int y = 0;

	while (true)
	{
		x = curX + getRandomInt(-1, 2);
		y = curY + getRandomInt(-1, 2);

		if (x >= 0 && x < level.getBoardWidth())
			if (y >= 0 && y < level.getBoardHeight())
				if ((x != m_x || y != m_y) && level.isEmpty(x, y))
					break;
	}

	m_x = x;
	m_y = y;
}