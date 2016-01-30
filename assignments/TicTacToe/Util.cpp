#include "Util.h"
#include <cstdlib>
#include <time.h>

const bool isDigit(char n)
{
    int num = int(n);
  
     return num >= 48 && num <= 57;
}

const int toInt(char n)
{
    return int(n) - 48;
}

void initRandomInt()
{
    srand(time(0));   
}

const int getRandomInt(int min, int max)
{
    return (rand() % (max - min + 1)) + min; 
}
