#ifndef item_h
#define item_h
#include <string>

using namespace std;

class item {
   public:
      item();
      item(string name, string unitType, int unitQuantity, int unitPrice);
      void calculatePrice();
      void printPrice();

   private:
      string name;
      string unitType;
      int unitQuantity;
      int unitPrice;
      int totalPrice;
};

#endif 
