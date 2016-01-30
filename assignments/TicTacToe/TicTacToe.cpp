#include "TicTacToe.h"
#include "Util.h"
#include <iostream>
#include <string>

using namespace std;

TicTacToe::TicTacToe(char playerOne, char playerTwo, char emptySpace):
    m_playerOne(playerOne),
    m_playerTwo(playerTwo),
    m_emptySpace(emptySpace) 
{
}

void TicTacToe::play()
{
    int aiPlay = false;
    int boardSize = 0;

    // Get boardsize
    while(true)
    {
        string resp = " ";
        
        cout << endl <<  "Board size (must be between 2 and 5, inclusive): ";
        getline(cin, resp);

        if(isDigit(resp[0]))
        {
            boardSize = toInt(resp[0]);
        
            if(boardSize >= 2 && boardSize <= 5)
                break;     
        }

        cout << "Invalid input!" << endl;
    }

    cout << endl;

    // Play vs ai?
    while(true)
    {
        char resp = ' ';

        cout << "Play against AI ('y', 'n'): ";
        cin >> resp;

        if(resp == 'y' || resp == 'n')
        {
            if(resp == 'y')
                aiPlay = true;

            else
                aiPlay = false;

            break;
        }

        cout << "Invalid input!" << endl;            
    }

    if(aiPlay)
        runWithAi(boardSize);

    else
        runWithoutAi(boardSize);
}

void TicTacToe::runWithAi(int boardSize)
{
    bool aiFirst = false;

    while(true)
    {
        char resp = ' ';

        cout << "AI goes first ('y', 'n'): ";
        cin >> resp;

        if(resp == 'y' || resp == 'n')
        {
            if(resp == 'y')
                aiFirst = true;

            else
                aiFirst = false;

            break;
        }

        cout << "Invalid input!" << endl;
    }
    
    GameBoard board(boardSize);
    bool aiTurn = aiFirst;
    char currPlayer = aiFirst ? m_playerTwo : m_playerOne;

    for(int i = 0; i < boardSize; i++)
        for(int j = 0; j < boardSize; j++)
            board.set(i, j, m_emptySpace);

    while(true)
    {
        char userX = ' ';
        char userY = ' ';
        
        while(true)
        {
            if(aiTurn)
            {
                int x = 0;
                int y = 0;

                getRandomAiMove(x, y, board);
                board.set(x, y, aiFirst ? m_playerOne : m_playerTwo);
                aiTurn = false;
                break;
            }

            else
            {
                board.print();
                cout << "Player " << (aiFirst ? 2 : 1) << " (";
                cout << currPlayer << ") turn" << endl;
                cout << "Enter coordinates 'x y'" << endl;
        
                cin >> userX >> userY;
                cout << endl << endl << endl;

                if(isDigit(userX) && isDigit(userY))
                {
                    int x = toInt(userX);
                    int y = toInt(userY);

                    if(x >= 0 && x < boardSize && y >= 0 && y < boardSize)
                    {
                        if(board.get(x, y) == m_emptySpace)
                        {
                            board.set(x, y, currPlayer);
                            aiTurn = true;
                            break;
                        }

                        else
                            cout << "Spot already taken!" << endl;
                    }      
                
                    else
                        cout << "Invalid coordinates!" << endl;  
                }

                else
                    cout << "Invalid coordinates!" << endl;
            }
        }

        int winner = getWinner(board);

        if(winner > -1)
        {
            cout << endl;
            board.print();

            if(winner == 0)
                cout << "Cats game!" << endl;

            else
                cout << "Player " << winner << " won!" << endl;

            cout << endl;
            break;
        }
    }
}

void TicTacToe::runWithoutAi(int boardSize)
{
    GameBoard board(boardSize);
    int turnCounter = 1;

    for(int i = 0; i < boardSize; i++)
        for(int j = 0; j < boardSize; j++)
            board.set(i, j, m_emptySpace);

    while(true)
    {
        bool playerOneTurn = turnCounter % 2 != 0;
        char currPlayer = playerOneTurn ? m_playerOne : m_playerTwo;
        char userX = ' ';
        char userY = ' ';
        
        while(true)
        {
            board.print();

            cout << "Player " << (playerOneTurn ? 1 : 2) << " (";
            cout << currPlayer << ") turn" << endl;
            cout << "Enter coordinates 'x y'" << endl;
        
            cin >> userX >> userY;
            cout << endl << endl << endl;

            if(isDigit(userX) && isDigit(userY))
            {
                int x = toInt(userX);
                int y = toInt(userY);

                if(x >= 0 && x < boardSize && y >= 0 && y < boardSize)
                {
                    if(board.get(x, y) == m_emptySpace)
                    {
                        board.set(x, y, currPlayer);
                        turnCounter++;
                        break;
                    }

                    else
                        cout << "Spot already taken!" << endl;
                }
                
                else
                    cout << "Invalid coordinates!" << endl;  
            }

            else
                cout << "Invalid coordinates!" << endl;
        }

        int winner = getWinner(board);

        if(winner > -1)
        {
            cout << endl;
            board.print();

            if(winner == 0)
                cout << "Cats game!" << endl;

            else
                cout << "Player " << winner << " won!" << endl;

            cout << endl;
            break;
        }
    }
}

void TicTacToe::getRandomAiMove(int& x, int& y, GameBoard& board)
{
    do
    {
        x = getRandomInt(0, board.getSize() - 1);
        y = getRandomInt(0, board.getSize() - 1);
    }
    while(board.get(x, y) != m_emptySpace);
}

const int TicTacToe::getWinner(GameBoard& board)
{
    bool catsGame = true;

    // For checking diagonals
    char initDiagLeft = ' ';
    char initDiagRight = ' ';
    bool diagLeft = true;
    bool diagRight = true;

    // Check both vert and horz at the same time
    for(int x = 0; x < board.getSize(); x++)
    {
        char initVert = ' ';
        char initHorz = ' ';
        bool vert = false;
        bool horz = false;

        for(int y = 0; y < board.getSize(); y++)
        {
            if(y == 0)
            {
                initVert = board.get(x, y);
                initHorz = board.get(y, x);

                if(initVert == m_emptySpace || initHorz == m_emptySpace)
                {
                    catsGame = false;
                    
                    // Both are empty spaces
                    if(initVert == initHorz)
                        break;
                }

                if(initVert != m_emptySpace)
                    vert = true;

                if(initHorz != m_emptySpace)
                    horz = true;
            }

            else
            {
                char currVert = board.get(x, y);
                char currHorz = board.get(y, x);

                if(initVert != currVert)
                    vert = false;

                if(initHorz != currHorz)
                    horz = false;

                if(m_emptySpace == currVert || m_emptySpace == currHorz)
                    catsGame = false;

                if(!vert && !horz)
                    break;
            }           
        }
        
        if(x == 0)
        {
            initDiagLeft = board.get(x, x);
            initDiagRight = board.get(x, board.getSize() - x - 1);
        }

        else if(diagLeft || diagRight)
        {
            char currDiagLeft = board.get(x, x);

            if(initDiagLeft != currDiagLeft || currDiagLeft == m_emptySpace)
                diagLeft = false;
            
            char currDiagRight = board.get(x, board.getSize() - x - 1);

            if(initDiagRight != currDiagRight || currDiagRight == m_emptySpace)
                diagRight = false;
        }

        if(vert)
            return initVert == m_playerOne ? 1 : 2;

        else if(horz)
            return initHorz == m_playerOne ? 1 : 2;
    }

    if(diagLeft)
        return initDiagLeft == m_playerOne ? 1 : 2;

    else if(diagRight)
        return initDiagRight == m_playerOne ? 1 : 2;

    return catsGame ? 0 : -1;
}
