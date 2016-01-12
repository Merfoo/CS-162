#include "summation.h"

double sum(double data[], int len)
{
    double sum = 0.0;

    for(int i = 0; i < len; i++)
        sum += data[i];
    
    return sum;
}
