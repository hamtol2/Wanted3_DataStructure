#pragma once

#include <vector>

template<typename T>
void SafeDelete(T*& pointer)
{
	if (pointer)
	{
		delete pointer;
		pointer = nullptr;
	}
}

// A* ��ã�� �˰����� ó���ϴ� Ŭ����.
class Node;
class AStar
{
	// ���� ó���� ���� ����ü.
	struct Direction
	{
		// ��ġ.
		int x = 0;
		int y = 0;

		// �̵� ���.
		float cost = 0.0f;
	};

public:
	AStar();
	~AStar();

private:
	// ���� ����Ʈ(�湮�� ����� ���).
	std::vector<Node*> openList;

	// ���� ����Ʈ(�湮�� ����� ���).
	std::vector<Node*> closedList;

	// ���� ���.
	Node* startNode = nullptr;

	// ��ǥ ���.
	Node* goalNode = nullptr;
};