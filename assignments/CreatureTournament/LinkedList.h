#pragma once

#include <iostream>
#include "Creature.h"

class LinkedList
{
private:
    struct Node
    {
        Creature* creature;
		Node* prev;
        Node* next;
    };

    Node* m_head;
    Node* m_tail;

	int m_size;

public:
    LinkedList();
    ~LinkedList();

	int size();
	// WARNING: There is no copy constructor or assignment operator

    void pushBack(Creature* creature);
	void pushFront(Creature* creature);
	Creature* popBack();
    Creature* popFront();
	void clearAllNodes();
    void print();
};
