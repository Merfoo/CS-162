#ifndef LIST_H
#define LIST_H
#include "item.h"

class List
{
    public:
        List();
        ~List();

        void addItem(item newItem);
        void removeItem(int index);
        void printItem(int index);    
  
    private:
        int m_amount;
        int m_maxAmount;
        item* m_items;
};

#endif // LIST_H
