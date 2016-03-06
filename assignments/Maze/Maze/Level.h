#pragma once

#include <iostream>
#include <fstream>
#include "Point.h"

class Actor;

class Level
{
public:
	Level();
	~Level();
	bool create(std::string filename, bool isLastLevel);
	void print(Actor** actors, int actorsLength);
	Point getLadderPos();
	Point getPlayerSpawnPos();
	Point getSwanSpawnPos();

private:
	bool isValidSymbol(char c);
	bool setBoardDimensions(std::ifstream& file);
	bool setBoardData(std::ifstream& file, bool isLastLevel);

	int m_boardWidth;
	int m_boardHeight;
	char** m_board;
	Point m_ladder;
	Point m_playerSpawn;
	Point m_swanSpawn;
};