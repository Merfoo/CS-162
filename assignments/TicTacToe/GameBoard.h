#ifndef GAMEBOARD_H
#define GAMEBOARD_H

class GameBoard
{
    public:
        GameBoard();
        GameBoard(int size);
        ~GameBoard(); 
        
        void set(int x, int y, char val);
        const char get(int x, int y);
        const int getSize();
        void print();        

    private:
        int m_size;
        char ** m_board;
};

#endif // GAMEBOARD_H
