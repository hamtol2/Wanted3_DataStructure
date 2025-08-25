#include "Node.h"

Node::Node(const Bounds& bounds, int depth)
	: bounds(bounds), depth(depth)
{

}

Node::~Node()
{
	// Todo: 노드를 모두 제거하는 함수 작성 후 호출.
	Clear();
}

// 삽입(Insert).
void Node::Insert(Node* node)
{

}

// 질의(Query).
void Node::Query(const Bounds& queryBounds, std::vector<Node*>& possibleNodes)
{

}

// 정리 함수.
void Node::Clear()
{

}