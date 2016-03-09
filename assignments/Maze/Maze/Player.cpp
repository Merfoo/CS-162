#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player()
{
	m_symbol = 'P';
	m_apples = 0;
	m_keys = 0;
}

Player::~Player()
{
}

void Player::update(Level& level)
{
	char command = getInput();

	if (command == 'w' || command == 'a' || command == 's' || command == 'd')
	{
		if (!move(level, command))
			cout << "Can't move there!" << endl;

		if (level.isApple(m_x, m_y))
		{
			m_apples++;
			level.setSpot(m_x, m_y, ' ');
		}

		// TODO: Maybe print out if you're on a key or something
	}

	else if (command == 'e')
	{
		// TODO: Finish this
		if (!eatApple())
			cout << "You don't have any apples to eat!" << endl;
	}
}

bool Player::move(Level& level, char command)
{
	bool moved = false;

	// Move up
	if (command == 'w' && m_y > 0)
	{
		if (!level.isWall(m_x, m_y - 1))
		{
			m_y--;
			moved = true;
		}
	}

	// Move down
	if (command == 's' && m_y < level.getBoardHeight() - 1)
	{
		if (!level.isWall(m_x, m_y + 1))
		{
			m_y++;
			moved = true;
		}
	}

	// Move left
	if (command == 'a' && m_x > 0)
	{
		if (!level.isWall(m_x - 1, m_y))
		{
			m_x--;
			moved = true;
		}
	}

	// Move right
	if (command == 'd' && m_x < level.getBoardWidth() - 1)
	{
		if (!level.isWall(m_x + 1, m_y))
		{
			m_x++;
			moved = true;
		}
	}

	return moved;
}

// TODO: Finish this
bool Player::eatApple()
{
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