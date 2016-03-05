#include "Level.h"
#include <string>

using namespace std;

Level::Level()
{
}

Level::~Level()
{
	for (int i = 0; i < m_boardWidth; i++)
		delete[] m_board[i];

	delete[] m_board;
}

bool Level::create(std::string filename)
{
	cout << "Creating level from file '" << filename << "'" << endl;
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

	if (!setBoardData(file))
	{
		cout << "Invalid board data!" << endl;
		return false;
	}

	cout << "Level from file '" << filename << "' created successfuly" << endl;
	file.close();
}

void Level::print()
{
	for (int y = 0; y < m_boardHeight; y++)
	{
		for (int x = 0; x < m_boardWidth; x++)
			cout << m_board[x][y];

		cout << endl;
	}
}

bool Level::isValidChar(char c)
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

	char validChars[] = { '#', 'D', 'L', 'P', 'S', 'K', 'A', 'E', 'X', ' ' };

	for (int i = 0; i < sizeof(validChars) / sizeof(char); i++)
		if (c == validChars[i])
			return true;

	return false;
}

bool Level::setBoardDimensions(std::ifstream& file)
{
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

bool Level::setBoardData(std::ifstream& file)
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

		if (!isValidChar(c) || charsInFile > m_boardWidth * m_boardHeight)
			return false;

		int y = charsInFile / m_boardWidth;
		int x = charsInFile - (m_boardWidth * y);
		m_board[x][y] = c;

		if (c == 'L')
		{
			if (!foundLadder)
			{
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