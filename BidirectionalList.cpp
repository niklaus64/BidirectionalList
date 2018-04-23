#include "BidirectionalList.h"
#include <cassert>
#include <iostream>


BidirectionalList::BidirectionalList(Range range, const Comparator &comparator)
	: head(nullptr), tail(nullptr), listRange(range), comparator(comparator)
{
    std::cout << "BidirectionalList::BidirectionalList()" << std::endl;
}

BidirectionalList::~BidirectionalList()
{
    std::cout << "BidirectionalList::~BidirectionalList()" << std::endl;
	while (head)
		pop();
}

void BidirectionalList::push(double newElement)
{
    std::cout << "BidirectionalList::push()\n";
	//Element is not in range
	if (newElement < listRange.first || newElement > listRange.second)
	{
    	std::cout << "\tNew element=" << newElement << " NOT in valid range." << std::endl;
		return;
	}

	Node * p, *r;
	p = new Node;
	p->value = newElement;

	if (!head) head = tail = p;
	else if (comparator(p->value, head->value))
	{
		p->next = head;
		head->prev = p;
		head = p;
	}
	else
	{
		r = head;
		while ((r->next) && (!comparator(p->value, r->next->value)))
		{
			r = r->next;
		}
		p->prev = r;
		p->next = r->next;
		r->next = p;
		if (!p->next) tail = p;
	}
	std::cout << "\tNew element added properly" << std::endl;
}

void BidirectionalList::pop()
{
    std::cout << "BidirectionalList::pop()\n";
	if (head)
	{
		Node * p = head;
		head = head->next;
		if (!head) tail = nullptr;
    	std::cout << "\tPopping value=" << p->value << std::endl;
		delete p;
	}
}

void BidirectionalList::print()
{
	Node* p = head;
	while (p != nullptr)
	{
		std::cout << p->value << " ";
		p = p->next;
	}
}