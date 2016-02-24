#include "LinkedList.h"

LinkedList::LinkedList()
{
    m_head = new Node;
    m_head->next = 0;
    
    m_tail = m_head;
}

LinkedList::~LinkedList()
{
	clearAllNodes();
	delete m_head;
}

// TODO: This doesn't deep copy, MAKE IT DEEP COPY
LinkedList::LinkedList(const LinkedList& newList)
{
	m_head = new Node;
	m_head->next = 0;

	m_tail = m_head;
	Node* node = newList.m_head->next;

	while (node != 0)
	{
		pushBack(node->creature);
		node = node->next;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& rhs)
{
	clearAllNodes();
	Node* node = rhs.m_head->next;

	while (node != 0)
	{
		pushBack(node->creature);
		node = node->next;
	}

	return *this;
}

void LinkedList::pushBack(Creature* creature)
{
    Node* node = new Node;
    node->creature = creature;
    node->next = 0;

    m_tail->next = node;
    m_tail = node;
}

Creature* LinkedList::popFront()
{
    Node* node = m_head->next;
    Creature* creature = node->creature;

    m_head->next = node->next;
    delete node;

    return creature;
}

void LinkedList::clearAllNodes()
{
	Node* node = m_head->next;
	Node* tmp;

	while (node != 0)
	{
		tmp = node->next;
        
        delete node->creature;
		delete node;
		node = tmp;
	}

	m_head->next = 0;
	m_tail = m_head;
}

void LinkedList::print()
{
    Node* node = m_head->next;
   
    while(node != 0)
    {
		node->creature->print();
        node = node->next;       
    }

    delete node;
}
