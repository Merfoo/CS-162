#include <iostream>
#include <string>
#include "List.h"
#include "item.h"

using namespace std;

int main()
{
    List list;

    while(true)
    {
        cout << "Add new item (a)" << endl;
        cout << "Remove item (r)" << endl;
        cout << "Print item (i)" << endl;
        cout << "Quit program (q)" << endl;
        
        string input;
        getline(cin, input);

        if(input == "a")
        {
            string name;
            string unitType;
            string unitQuantity;
            string unitPrice;

            getline(cin, name);
            getline(cin, unitType);
            getline(cin, unitQuantity);
            getline(cin, unitPrice);

            int iUnitQuantity = stoi(unitQuantity, 0);
            int iUnitPrice = stoi(unitPrice, 0);
            item newItem(name, unitType, iUnitQuantity, iUnitPrice);
            list.addItem(newItem);   
        }       
    } 

    item itemOne("Rice", "Food", 1, 2);

    list.addItem(itemOne);

    list.printItem(0);
    return 0;
}
