#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList list;

    list.add('a');
    list.add('b');
    list.add('c');
    list.print();

    char c = list.remove();
    cout << "REMOVED: " << c << endl;
    
    list.print();
    return 0;
}
