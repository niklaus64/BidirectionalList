#pragma once
#include <memory>

struct Node
{
	Node* prev;
	Node* next;
	double value;
};

class BidirectionalList
{
	using Range = std::pair<uint32_t, uint32_t>; // TODO: should be extracted to common namespace
public:
	BidirectionalList(Range);
	~BidirectionalList();

	void push(double);
private:
	Node *head, *tail;
	Range listRange;
};
