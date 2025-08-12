#include "Node.h"

Node::Node()
	//: data(0), next(nullptr)
	: Node(0)
{
}

Node::Node(int data)
	: data(data), next(nullptr)
{
}

std::ostream& operator<<(std::ostream& os, const Node& node)
{
	return os << "Data: " << node.data;
}