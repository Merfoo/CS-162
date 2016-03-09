#include "Game.h"
#include <iostream>
#include <string>
#include "Util.h"

using namespace std;
using namespace Util;

Game::Game()
{
	m_rowDivider = "";
	m_boardWidth = 0;
	m_boardWidth = 0;
	m_bombs = 0;
	m_board = 0;
}

Game::~Game()
{
	cleanup();
}

void Game::play(int rows, int cols, int bombs)
{
	int openedSpots = 0;
	setupBoard(rows, cols, bombs);

	while (true)
	{
		printBoard();
		bool openSpot = getSpotAction();
		int x, y;

		while(true)
		{
			getSpotPosition(x, y);

			if (getSpotAvailablity(x, y, openSpot))
				break;

			cout << "Spot taken!" << endl;
		}

		if (openSpot)
		{
			if (m_bombs[x][y])
			{
				cout << "YOU DIED YOU!" << endl;
				return;
			}

			m_board[x][y] = getNearbyBombs(x, y);
			openedSpots++;
		}

		else
			m_board[x][y] = 'F';

		if (bombs + openedSpots == rows * cols)
		{
			cout << "Wow nice job you won!" << endl;
			return;
		}
	}
}

void Game::setupBoard(int rows, int cols, int bombs)
{
	cleanup();
	m_boardWidth = cols;
	m_boardHeight = rows;
	m_bombs = new bool*[m_boardWidth];
	m_board = new char*[m_boardWidth];

	for (int x = 0; x < m_boardWidth; x++)
	{
		m_bombs[x] = new bool[m_boardHeight];
		m_board[x] = new char[m_boardHeight];

		for (int y = 0; y < m_boardHeight; y++)
		{
			m_bombs[x][y] = false;
			m_board[x][y] = ' ';
		}
	}

	while (bombs > 0)
	{
		while (true)
		{
			int x = getRandomInt(0, m_boardWidth);
			int y = getRandomInt(0, m_boardHeight);

			if (!m_bombs[x][y])
			{
				m_bombs[x][y] = true;
				bombs--;
				break;
			}
		}
	}

	m_rowDivider = "-";

	for (int i = 0; i < m_boardWidth * 2; i++)
		m_rowDivider += "-";
}

void Game::printBoard()
{
	string colDivider = "|";

	for (int y = 0; y < m_boardHeight; y++)
	{
		cout << m_rowDivider << endl;

		for (int x = 0; x < m_boardWidth; x++)
			cout << colDivider << m_board[x][y];

		cout << colDivider << endl;
	}

	cout << m_rowDivider << endl;
}

void Game::cleanup()
{
	if (m_board != 0)
	{
		for (int i = 0; i < m_boardWidth; i++)
			delete[] m_board[i];

		delete[] m_board;
		m_board = 0;
	}

	if (m_bombs != 0)
	{
		for (int i = 0; i < m_boardWidth; i++)
			delete[] m_bombs[i];

		delete[] m_bombs;
		m_bombs = 0;
	}

	m_boardWidth = 0;
	m_boardHeight = 0;
}

bool Game::getSpotAvailablity(int x, int y, bool openSpot)
{
	// Wants to open the spot
	if (openSpot && (m_board[x][y] == ' ' || m_board[x][y] == 'F'))
		return true;

	// Wants to flag the spot
	if (!openSpot && m_board[x][y] == ' ')
		return true;

	return false;
}

// True means they want to open the spot, false means they want to flag it
bool Game::getSpotAction()
{
	while (true)
	{
		cout << "Flag(1) or Open(2): ";
		string input;
		getline(cin, input);

		if (input == "1" || input == "2")
			return input == "1" ? false : true;

		cout << "Invalid input!" << endl;
	}
}

void Game::getSpotPosition(int& x, int& y)
{
	while (true)
	{
		cout << "Row Col: ";
		string input;
		getline(cin, input);
		bool foundDigit = false;

		for (int i = 0; i < input.length(); i++)
		{
			if (!foundDigit && input[i] >= '0' && input[i] <= '9')
				foundDigit = true;

			else if (foundDigit && input[i] == ' ')
			{
				try
				{
					x = stoi(input.substr(0, i));
					y = stoi(input.substr(i, input.length()));
					return;
				}

				catch (...) {}

				cout << "Invalid input!" << endl;
				break;
			}
		}
	}
}

char Game::getNearbyBombs(int x, int y)
{
	int bombs = 0;

	if (x > 0)
	{
		// Top left
		if (y > 0)
			if (m_bombs[x - 1][y - 1])
				bombs++;

		// Bot Left
		if (y < m_boardHeight - 1)
			if (m_bombs[x - 1][y + 1])
				bombs++;

		// Mid Left
		if (m_bombs[x - 1][y])
			bombs++;
	}

	if (x < m_boardWidth - 1)
	{
		// Top Right
		if (y > 0)
		{
			if (m_bombs[x + 1][y - 1])
				bombs++;
		}

		// Bot Right
		if (y < m_boardHeight - 1)
			if (m_bombs[x + 1][y + 1])
				bombs++;

		// Mid Right
		if (m_bombs[x + 1][y])
			bombs++;
	}

	// Top Mid
	if (y > 0)
		if (m_bombs[x][y - 1])
			bombs++;

	// Bot Mid
	if (y < m_boardHeight - 1)
		if (m_bombs[x][y + 1])
			bombs++;

	return bombs + '0';
}