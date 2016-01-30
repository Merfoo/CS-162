#include "List.h"
#include <iostream>

using namespace std;

List::List()
{
    m_amount = 0;
    m_maxAmount = 1;
    m_items = 0;  
}

List::~List()
{
    if(m_items != 0)
    {
        delete[] m_items;
        m_items = 0;
        m_amount = 0;
        m_maxAmount = 1;
    }
}

void List::addItem(item newItem)
{
    if(m_amount >= m_maxAmount || m_amount == 0)
    {
        // Create new array with new length to contain items
        m_maxAmount *= 2;
        item* items = new item[m_maxAmount];
    
        // Copy over data from previous array
        for(int i = 0; i < m_amount; i++)
            items[i] = m_items[i];

        // Delete m_items, set it to new array, items
        delete[] m_items;
        m_items = items;
    }

    // Add item to end of new array
    m_items[m_amount] = newItem;  
    m_amount++;
}

void List::removeItem(int index)
{
    // Bounds check
    if(index >= 0 && index < m_amount)
    {
        item* items = new item[m_amount - 1];

        for(int i = 0; i < m_amount; i++)
        {
            if(i == index)
                continue;

            else if(i < index)
                items[i] = m_items[i];

            else
                items[i - 1] = m_items[i];
        }

        delete[] m_items;
        m_items = items;
        m_amount--;
    }
}

void List::printItem(int index)
{
    m_items[index].printPrice();
}
