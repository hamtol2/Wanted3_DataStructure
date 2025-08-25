#pragma once

#include "Bounds.h"
#include <vector>

// ������ ���� ���� �Լ�.
template<typename T>
void SafeDelete(T*& pointer)
{
	if (pointer)
	{
		delete pointer;
		pointer = nullptr;
	}
}

// ���� ������ ���� ������.
enum class NodeIndex
{
	// ������ �����ϴ� ���.
	TopLeft,		// ���� ���.
	TopRight,		// ������ ���.
	BottomLeft,		// ���� �ϴ�.
	BottomRight,	// ������ �ϴ�.

	Straddling,		// �� ������ ��ģ ���.
	OutOfArea,		// ������ ��� ���.
};

class Node
{
public:

	Node(const Bounds& bounds, int depth = 0);
	~Node();

	// ����(Insert).
	void Insert(Node* node);

	// ����(Query).
	void Query(const Bounds& queryBounds, std::vector<Node*>& possibleNodes);

	// ���� �Լ�.
	void Clear();

	// Getter.
	Bounds GetBounds() const { return bounds; }

	// ���� ��忡 ���Ե� ��� (�迭).
	const std::vector<Node*>& GetPoints() const { return points; }

	// �ڽ� ���.
	Node* GetTopLeft() const { return topLeft; }
	Node* GetTopRight() const { return topRight; }
	Node* GetBottomLeft() const { return bottomLeft; }
	Node* GetBottomRight() const { return bottomRight; }

private:
	// ����.
	int depth = 0;

	// ����.
	Bounds bounds;

	// ���� ��忡 ���Ե� ��� (�迭).
	std::vector<Node*> points;

	// �ڽ� ���.
	Node* topLeft = nullptr;
	Node* topRight = nullptr;
	Node* bottomLeft = nullptr;
	Node* bottomRight = nullptr;
};