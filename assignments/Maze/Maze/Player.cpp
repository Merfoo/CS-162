#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player()
{
	m_symbol = 'P';
	m_stepsSinceEatenApple = 0;
	m_apples = 0;
	m_keys = 0;
}

Player::~Player()
{
}

void Player::update(Level& level)
{
	while (true)
	{
		char command = getInput();

		if (command == 'w' || command == 'a' || command == 's' || command == 'd')
		{
			if (move(level, command))
			{
				if (level.isDoor(m_x, m_y))
				{
					m_keys--;
					level.setSpot(m_x, m_y, ' ');
				}

				else if (level.isKey(m_x, m_y) && m_keys < m_maxKeys)
				{
					m_keys++;
					level.setSpot(m_x, m_y, ' ');
				}

				else if (level.isApple(m_x, m_y) && m_apples < m_maxApples)
				{
					m_apples++;
					level.setSpot(m_x, m_y, ' ');
				}
			}

			else
			{
				cout << "Can't move there!" << endl;
				continue;
			}
		}

		else if (command == 'e')
		{
			if (!eatApple())
			{
				cout << "You don't have any apples to eat!" << endl;
				continue;
			}
		}

		else if (command == 'u')
		{
			if (level.isExit(m_x, m_y))
				level.setShouldLoadNext(true);
		}

		else if (command == 'q')
			level.setQuitLevel(true);

		break;
	}

	m_stepsSinceEatenApple++;
}

bool Player::immuneToSwans()
{
	return m_stepsSinceEatenApple <= m_stepsImmuneToSwans;
}

int Player::getApples()
{
	return m_apples;
}

int Player::getKeys()
{
	return m_keys;
}

bool Player::move(Level& level, char command)
{
	int x = m_x;
	int y = m_y;

	if (command == 'w')
		y--;

	else if (command == 's')
		y++;

	else if (command == 'a')
		x--;

	else if (command == 'd')
		x++;

	if(x < 0 || x >= level.getBoardWidth())
		return false;
	
	if (y < 0 || y >= level.getBoardHeight())
		return false;

	if (level.isWall(x, y))
		return false;
	
	if (level.isDoor(x, y) && m_keys <= 0)
		return false;

	m_x = x;
	m_y = y;
	return true;
}

// TODO: Finish this
bool Player::eatApple()
{
	if (m_apples > 0)
	{
		m_apples--;
		m_stepsSinceEatenApple = 0;
		return true;
	}

	return false;
}

char Player::getInput()
{
	/*
		Valid input

		‘w’ move up
		‘a’ move left
		‘s’ move down
		‘d’ move right
		‘e’ eat apple
		‘u’ use ladder
		‘q’ quit
	*/

	char validSymbols[] = { 'w', 'a', 's', 'd', 'e', 'u', 'q' };

	while (true)
	{
		cout << "Command: " << endl;
		string input;
		getline(cin, input);

		for (int i = 0; i < sizeof(validSymbols) / sizeof(char); i++)
			if (input[0] == validSymbols[i])
				return input[0];

		cout << "Invalid command!" << endl;
	}
}