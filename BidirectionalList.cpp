#include "BidirectionalList.h"
#include <cassert>
#include <iostream>


BidirectionalList::BidirectionalList(Range a_range, const Comparator &a_comparator)
{
	listRange = a_range;
	comparator = a_comparator;
}

BidirectionalList::~BidirectionalList()
{
	while (head)
		pop();
}

void BidirectionalList::push(double newElement)
{
	//Element is not in range
	if (newElement < listRange.first || newElement > listRange.second)
		return;

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
}

void BidirectionalList::pop()
{
	if (head)
	{
		Node * p = head;
		head = head->next;
		if (!head) tail = nullptr;
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