#pragma once

#include <iostream>
#include "Creature.h"

class LinkedList
{
private:
    struct Node
    {
        Creature* creature;
        Node* next;  
    };

    Node* m_head;
    Node* m_tail;

public:
    LinkedList();
    ~LinkedList();

	// TODO: Implement copy constructor assignment overrider
	LinkedList(const LinkedList& newList);
	LinkedList& operator=(const LinkedList& rhs);

    void pushBack(Creature* creature);
    Creature* popFront();
	void clearAllNodes();
    void print();
};
