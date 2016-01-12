#include "average.h"
#include "summation.h"

double avg(double data[], int len)
{    
    return sum(data, len) / len;
}
