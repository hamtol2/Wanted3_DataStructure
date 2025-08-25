#pragma once

#include "Bounds.h"
#include <vector>

// 해제를 위한 삭제 함수.
template<typename T>
void SafeDelete(T*& pointer)
{
	if (pointer)
	{
		delete pointer;
		pointer = nullptr;
	}
}

// 영역 구분을 위한 열거형.
enum class NodeIndex
{
	// 완전히 포함하는 경우.
	TopLeft,		// 왼쪽 상단.
	TopRight,		// 오른쪽 상단.
	BottomLeft,		// 왼쪽 하단.
	BottomRight,	// 오른쪽 하단.

	Straddling,		// 두 영역에 겹친 경우.
	OutOfArea,		// 영역을 벗어난 경우.
};

class Node
{
public:

	Node(const Bounds& bounds, int depth = 0);
	~Node();

	// 삽입(Insert).
	void Insert(Node* node);

	// 질의(Query).
	void Query(const Bounds& queryBounds, std::vector<Node*>& possibleNodes);

	// 정리 함수.
	void Clear();

	// Getter.
	Bounds GetBounds() const { return bounds; }

	// 현재 노드에 포함된 노드 (배열).
	const std::vector<Node*>& GetPoints() const { return points; }

	// 자식 노드.
	Node* GetTopLeft() const { return topLeft; }
	Node* GetTopRight() const { return topRight; }
	Node* GetBottomLeft() const { return bottomLeft; }
	Node* GetBottomRight() const { return bottomRight; }

private:
	// 깊이.
	int depth = 0;

	// 영역.
	Bounds bounds;

	// 현재 노드에 포함된 노드 (배열).
	std::vector<Node*> points;

	// 자식 노드.
	Node* topLeft = nullptr;
	Node* topRight = nullptr;
	Node* bottomLeft = nullptr;
	Node* bottomRight = nullptr;
};