#include <iostream>
#include "item.h"

using namespace std;

item::item()
{
}

item::item(string name, string unitType, int unitQuantity, int unitPrice) {

   this->name = name;
   this->unitType = unitType;
   this->unitQuantity = unitQuantity;
   this->unitPrice = unitPrice;

   calculatePrice();
}

void item::calculatePrice() {

   totalPrice = unitQuantity * unitPrice;
}

void item::printPrice() {

   cout << "The total price of " << name << " is: " << totalPrice << endl;
}
