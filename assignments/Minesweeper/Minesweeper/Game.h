#pragma once

#include <iostream>

class Game
{
public:
	Game();
	~Game();
	void play(int cols, int rows, int bombs);

private:
	void setupBoard(int rows, int cols, int bombs);
	void printBoard();
	void cleanup();
	bool getSpotAvailablity(int x, int y, bool openSpot);
	bool getSpotAction();
	void getSpotPosition(int& x, int& y);
	char getNearbyBombs(int x, int y);

	std::string m_rowDivider;
	int m_boardWidth;
	int m_boardHeight;
	bool** m_bombs;
	char** m_board;
};