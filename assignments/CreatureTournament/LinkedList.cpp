#include "LinkedList.h"

LinkedList::LinkedList()
{
    m_head = new Node;
	m_head->prev = 0;
    m_head->next = 0;
    
    m_tail = m_head;

	m_next = m_head->next;

	m_size = 0;
}

LinkedList::~LinkedList()
{
	clearAllNodes();
	delete m_head;
}

int LinkedList::size()
{
	return m_size;
}

void LinkedList::pushBack(Creature* creature)
{
    Node* node = new Node;
    node->creature = creature;
	node->prev = m_tail;
    node->next = 0;

    m_tail->next = node;
    m_tail = node;

	m_size++;
}

void LinkedList::pushFront(Creature* creature)
{
	Node* node = new Node;
	node->creature = creature;
	node->prev = m_head;
	node->next = m_head->next;

	if(m_head->next != 0)
		m_head->next->prev = node;

	m_head->next = node;

	if (m_size == 0)
		m_tail = node;

	m_size++;
}

Creature* LinkedList::popBack()
{
	if (m_size <= 0)
		return 0;

	Node* node = m_tail;
	Creature* creature = node->creature;
	node->prev->next = 0;
	
	m_tail = node->prev;
	delete node;

	m_size--;

	return creature;
}

Creature* LinkedList::popFront()
{
	if (m_size <= 0)
		return 0;

    Node* node = m_head->next;
    Creature* creature = node->creature;

	if(node->next != 0)
		node->next->prev = m_head;

    m_head->next = node->next;
    delete node;
	m_size--;

	if (m_size == 0)
		m_tail = m_head;

    return creature;
}

Creature* LinkedList::pop(int index)
{
	if (index >= 0 && index < m_size)
	{
		Node* node = m_head;
		int i = -1;

		while (i < index)
		{
			node = node->next;
			i++;
		}

		Creature* creature = node->creature;

		node->prev->next = node->next;

		if (node->next != 0)
			node->next->prev = node->prev;

		delete node;
		m_size--;

		return creature;
	}

	return 0;
}

Creature* LinkedList::getNext()
{
	if (m_next != 0)
	{
		Creature* creature = m_next->creature;
		m_next = m_next->next;

		return creature;
	}

	return 0;
}

void LinkedList::resetNext()
{
	m_next = m_head->next;
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
	m_size = 0;
}

void LinkedList::print()
{
    Node* node = m_head->next;
   
    while(node != 0)
    {
		node->creature->print();
        node = node->next;       
    }
}
