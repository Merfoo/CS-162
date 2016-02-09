#pragma once

#include <iostream>

class LinkedList
{
private:
    struct Node
    {
        char val;
        Node* next;  
    };

    Node* m_head;
    Node* m_tail;

public:
    LinkedList();
    ~LinkedList();

    void add(char val);
    char remove();
    void print();
};
