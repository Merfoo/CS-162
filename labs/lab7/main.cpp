#include <iostream>

using namespace std;

int main()
{
    #ifdef DEBUG
    cout << "Debug MACRO exists" << endl;
    #else
    cout << "Debug MACRO does not exist" << endl;
    #endif

    return 0;
}
