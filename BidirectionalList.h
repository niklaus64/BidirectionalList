#pragma once
#include <memory>

struct Node
{
	std::shared_ptr<Node> prev;
	std::shared_ptr<Node> next;
	double value;
};

class BidirectionalList
{
	using NodePtr = std::shared_ptr<Node>;
	using Range = std::pair<uint32_t, uint32_t>;
public:
	BidirectionalList(std::pair<uint32_t, uint32_t>);
	~BidirectionalList();

	NodePtr head, tail;

	void push(double);

private:
	Range listRange;
};
