#include "Node.h"

Node::Node(const Bounds& bounds, int depth)
	: bounds(bounds), depth(depth)
{

}

Node::~Node()
{
	// Todo: ��带 ��� �����ϴ� �Լ� �ۼ� �� ȣ��.
	Clear();
}

// ����(Insert).
void Node::Insert(Node* node)
{

}

// ����(Query).
void Node::Query(const Bounds& queryBounds, std::vector<Node*>& possibleNodes)
{

}

// ���� �Լ�.
void Node::Clear()
{

}