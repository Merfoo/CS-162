#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "GameBoard.h"

class TicTacToe
{
    public:
        TicTacToe(char playerOne, char playerTwo, char emptySpace);
        void play();

    private:
        void runWithAi(int boardSize);
        void runWithoutAi(int boardSize);
        const int getWinner(GameBoard& board);        

        char m_playerOne;
        char m_playerTwo;
        char m_emptySpace;
};

#endif // TICTACTOE_H
