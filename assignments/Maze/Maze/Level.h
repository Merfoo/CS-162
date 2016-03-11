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
	bool isWall(int x, int y);
	bool isApple(int x, int y);
	bool isKey(int x, int y);
	bool isDoor(int x, int y);
	bool isExit(int x, int y);
	bool isEmpty(int x, int y);
	void setSpot(int x, int y, char c);
	void setShouldLoadNext(bool shouldLoad);
	bool shouldLoadNext();
	void setQuitLevel(bool shouldQuit);
	bool shouldQuit();
	void print(Actor** actors, int actorsLength);
	int getBoardWidth();
	int getBoardHeight();
	Point getLadderPos();
	Point getPlayerSpawnPos();
	Point getSwanSpawnPos();

private:
	bool isValidSymbol(char c);
	bool setBoardDimensions(std::ifstream& file);
	bool setBoardData(std::ifstream& file, bool isLastLevel);

	bool m_levelFinished;
	bool m_quitLevel;
	int m_boardWidth;
	int m_boardHeight;
	char** m_board;
	Point m_ladder;
	Point m_playerSpawn;
	Point m_swanSpawn;
};