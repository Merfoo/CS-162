#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main()
{
    TicTacToe game('X', 'O', '*');
    game.play();    
    
    return 0;
}
