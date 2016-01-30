#include <iostream>
#include <string>
#include "TicTacToe.h"
#include "Util.h"

using namespace std;

int main()
{
    initRandomInt();
    TicTacToe game('X', 'O', '*');
    bool playGame = true;

    while(playGame)
    {
        game.play();
        
        while(true)
        {
            cout << "Play again? (y, n): " << endl;
            string input = " ";

            getline(cin, input);

            if(input[0] == 'y')
                break;

            if(input[0] == 'n')
            {
                playGame = false;
                break;
            }

            cout << "Invalid input!" << endl;
        }
        
        cout << endl;
    }

    return 0;
}
