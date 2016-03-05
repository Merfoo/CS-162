#pragma once

#include <iostream>
#include <fstream>
#include "Point.h"

class Level
{
public:
	Level();
	~Level();
	bool create(std::string filename);
	void print();

private:
	bool isValidChar(char c);
	bool setBoardDimensions(std::ifstream& file);
	bool setBoardData(std::ifstream& file);

	int m_boardWidth;
	int m_boardHeight;
	char** m_board;
	Point m_ladder;
	Point m_playerSpawn;
	Point m_swanSpawn;

};