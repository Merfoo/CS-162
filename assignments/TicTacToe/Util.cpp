#include "Util.h"

const bool isDigit(char n)
{
    int num = int(n);
  
     return num >= 48 && num <= 57;
}

const int toInt(char n)
{
    return int(n) - 48;
}
