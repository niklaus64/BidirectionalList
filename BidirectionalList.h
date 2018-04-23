#pragma once
#include <memory>
#include <functional>

struct Node
{
	Node* prev = nullptr;
	Node* next = nullptr;
	double value;
};

class BidirectionalList
{
	using Range = std::pair<uint32_t, uint32_t>; // TODO: should be extracted to common namespace
	using Comparator = std::function<bool(double, double)>;
public:
	BidirectionalList(Range, const Comparator&);
	~BidirectionalList();

	void push(double);
	void print();
	void pop();

private:
	Node *head, *tail;
	Range listRange;
	Comparator comparator;
};
