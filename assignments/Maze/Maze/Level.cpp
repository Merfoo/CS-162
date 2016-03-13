#include "Level.h"
#include <string>
#include "Actor.h"

using namespace std;

Level::Level()
{
	m_levelFinished = false;
	m_quitLevel = false;
	m_board = 0;
}

Level::~Level()
{
	if (m_board != 0)
	{
		for (int i = 0; i < m_boardWidth; i++)
			delete[] m_board[i];

		delete[] m_board;
	}
}

bool Level::create(std::string filename, bool isLastLevel)
{
	cout << "Creating level from file '" << filename << "'\n\t";
	ifstream file(filename);

	if (!file.is_open())
	{
		cout << "Couldn't open file '" << filename << "'" << endl;
		return false;
	}

	if (!setBoardDimensions(file))
	{
		cout << "Invalid board dimensions!" << endl;
		return false;
	}

	if (!setBoardData(file, isLastLevel))
	{
		cout << "Invalid board data!" << endl;
		return false;
	}

	cout << "Level from file '" << filename << "' created successfuly" << endl;
	file.close();
	return true;
}

bool Level::isWall(int x, int y)
{
	if (x >= 0 && x < m_boardWidth && y >= 0 && y < m_boardHeight)
		return m_board[x][y] == '#';

	// TODO: Perhaps do something else if out of bounds
	return true;
}

bool Level::isApple(int x, int y)
{
	if (x >= 0 && x < m_boardWidth && y >= 0 && y < m_boardHeight)
		return m_board[x][y] == 'A';

	// TODO: Perhaps do something else if out of bounds
	return false;
}

bool Level::isKey(int x, int y)
{
	// Consider turning out of bounds check a function
	if (x >= 0 && x < m_boardWidth && y >= 0 && y < m_boardHeight)
		return m_board[x][y] == 'K';

	return false;
}

bool Level::isDoor(int x, int y)
{
	if (x >= 0 && x < m_boardWidth && y >= 0 && y < m_boardHeight)
		return m_board[x][y] == 'D';

	return false;
}

bool Level::isExit(int x, int y)
{
	if (x >= 0 && x < m_boardWidth && y >= 0 && y < m_boardHeight)
		return m_board[x][y] == 'X' || m_board[x][y] == 'L';

	return false;
}

bool Level::isEmpty(int x, int y)
{
	if (x >= 0 && x < m_boardWidth && y >= 0 && y < m_boardHeight)
		return m_board[x][y] == ' ';

	return false;
}

void Level::setSpot(int x, int y, char c)
{
	if (x >= 0 && x < m_boardWidth && y >= 0 && y < m_boardHeight)
		m_board[x][y] = c;
}

void Level::setShouldLoadNext(bool shouldLoad)
{
	m_levelFinished = shouldLoad;
}

bool Level::shouldLoadNext()
{
	return m_levelFinished;
}

void Level::setQuitLevel(bool shouldQuit)
{
	m_quitLevel = shouldQuit;
}

bool Level::shouldQuit()
{
	return m_quitLevel;
}

void Level::print(Actor** actors, int actorLength)
{
	for (int y = 0; y < m_boardHeight; y++)
	{
		for (int x = 0; x < m_boardWidth; x++)
		{
			char c = m_board[x][y];

			for (int i = 0; i < actorLength; i++)
			{
				if (actors[i]->getX() == x && actors[i]->getY() == y)
				{
					c = actors[i]->getSymbol();
					break;
				}
			}

			cout << c;
		}

		cout << endl;
	}
}

bool Level::isValidSymbol(char c)
{
	/* '
		Valid characters
		‘#’ - walls
		‘D’ - door
		‘L’ - Ladder
		‘P’ - Player
		‘S’ - Swan(the starting location of the first swan)
		‘K’ - Key
		‘A’ - Apple
		‘E’ - Starting location for each level
		‘X’ - Exit(one way out)
		‘ ‘ - empty space(blank character)
	*/

	char validSymbols[] = { '#', 'D', 'L', 'P', 'S', 'K', 'A', 'E', 'X', ' ' };

	for (int i = 0; i < sizeof(validSymbols) / sizeof(char); i++)
		if (c == validSymbols[i])
			return true;

	return false;
}

bool Level::setBoardDimensions(std::ifstream& file)
{
	m_boardWidth = m_boardHeight = 0;
	string input;
	getline(file, input);

	try
	{
		bool foundDigit = false;

		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] >= '0' && input[i] <= '9')
				foundDigit = true;

			else if (foundDigit && input[i] == ' ')
			{
				m_boardHeight = stoi(input.substr(0, i));
				m_boardWidth = stoi(input.substr(i, input.length()));
				
				m_board = new char*[m_boardWidth];

				for (int j = 0; j < m_boardWidth; j++)
					m_board[j] = new char[m_boardHeight];

				return true;
			}
		}
	}

	catch (...)
	{
		return false;
	}

	return false;
}

bool Level::setBoardData(std::ifstream& file, bool isLastLevel)
{
	/*
		Valid characters
		‘#’ - walls
		‘D’ - door
		‘L’ - Ladder
		‘P’ - Player
		‘S’ - Swan(the starting location of the first swan)
		‘K’ - Key
		‘A’ - Apple
		‘E’ - Starting location for each level
		‘X’ - Exit(one way out)
		‘ ‘ - empty space(blank character)
	*/

	int charsInFile = 0;
	bool foundLadder = false;
	bool foundPlayerSpawn = false;
	bool foundSwanSpawn = false;

	while (!file.eof())
	{
		char c;
		file >> noskipws >> c;
		
        if (c == '\n')
	        continue;

		if (!isValidSymbol(c) || charsInFile > m_boardWidth * m_boardHeight)
			return false;

		int y = charsInFile / m_boardWidth;
		int x = charsInFile - (m_boardWidth * y);
		m_board[x][y] = c;

		if (c == 'L')
		{
			if (!foundLadder)
			{
				if (isLastLevel)
					m_board[x][y] = 'X';

				m_ladder.set(x, y);
				foundLadder = true;
			}

			else
			{
				cout << "Error: Found multiple Ladders" << endl;
				return false;
			}
		}

		else if (c == 'E')
		{
			if (!foundPlayerSpawn)
			{
				m_playerSpawn.set(x, y);
				foundPlayerSpawn = true;
			}

			else
			{
				cout << "Error: Found starting locations" << endl;
				return false;
			}
		}

		else if (c == 'S')
		{
			if (!foundSwanSpawn)
			{
				m_board[x][y] = ' ';
				m_swanSpawn.set(x, y);
				foundSwanSpawn = true;
			}

			else
			{
				cout << "Error: Found multiple Swan spawns" << endl;
				return false;
			}
		}

		charsInFile++;
	}

	if (!foundLadder || !foundPlayerSpawn || !foundSwanSpawn)
	{
		if (!foundLadder)
			cout << "Error: Didn't find Ladder" << endl;

		if (!foundPlayerSpawn)
			cout << "Error: Didn't find starting location" << endl;

		if (!foundSwanSpawn)
			cout << "Error: Didn't find Swan spawn" << endl;

		return false;
	}

	if (charsInFile != m_boardWidth * m_boardHeight)
	{
		cout << "Not enough data in file to make level" << endl;
		return false;
	}

	return true;
}

int Level::getBoardWidth()
{
	return m_boardWidth;
}

int Level::getBoardHeight()
{
	return m_boardHeight;
}

Point Level::getLadderPos()
{
	return m_ladder;
}

Point Level::getPlayerSpawnPos()
{
	return m_playerSpawn;
}

Point Level::getSwanSpawnPos()
{
	return m_swanSpawn;
}
