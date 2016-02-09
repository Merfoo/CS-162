#include "LinkedList.h"

LinkedList::LinkedList()
{
    m_head = new Node;
    m_head->next = 0;
    
    m_tail = m_head;
}

LinkedList::~LinkedList()
{
    Node* node = m_head;
    Node* tmp;

    while(node != 0)
    {
        tmp = node->next;

        delete node;
        node = tmp;
    }
}

void LinkedList::add(char val)
{
    Node* node = new Node;
    node->val = val;
    node->next = 0;

    m_tail->next = node;
    m_tail = node;
}

char LinkedList::remove()
{
    Node* node = m_head->next;
    char val = node->val;

    m_head->next = node->next;
    delete node;

    return val;
}

void LinkedList::print()
{
    Node* node = m_head->next;
   
    while(node != 0)
    {
        std::cout << node->val << std::endl;
        node = node->next;       
    }

    delete node;
}
