#include "GameBoard.h"
#include <iostream>

using namespace std;

GameBoard::GameBoard()
{
}

GameBoard::GameBoard(int boardSize)
{
    m_size = boardSize;
    m_board = new char*[m_size];
 
    for(int i = 0; i < m_size; i++)
       m_board[i] = new char[m_size];
}

GameBoard::~GameBoard()
{
    for(int i = 0; i < m_size; i++)
    {
        delete[] m_board[i];
        m_board[i] = 0;
    }

    delete[] m_board;
    m_board = 0;
}

void GameBoard::set(int x, int y, char val)
{
    m_board[x][y] = val;
}

const char GameBoard::get(int x, int y)
{
    return m_board[x][y];
}

const int GameBoard::getSize()
{
    return m_size;
}

void GameBoard::print()
{
    for(int y = 0; y < m_size; y++)
    {
        for(int x = 0; x < m_size; x++)
            cout << m_board[x][y] << ' ';

        cout << endl;
    }
}
