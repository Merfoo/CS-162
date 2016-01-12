#include "average.h"
#include "summation.h"
#include <iostream>

using namespace std;

int main()
{
    int len = 0;
    cout << "Amount of numbers: ";
    cin >> len;
    cout << endl;    

    double * data = new double[len];

    for(int i = 0; i < len; i++)
    {
        cout << "Number " << (i + 1) << ": ";
        cin >> data[i];
    }

    cout << endl;
    cout << "Sum: " << sum(data, len) << endl;
    cout << "Avg: " << avg(data, len) << endl;

    delete[] data;  
    return 0;
}
