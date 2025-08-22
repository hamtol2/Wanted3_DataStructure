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

// A* 길찾기 알고리즘을 처리하는 클래스.
class Node;
class AStar
{
	// 방향 처리를 위한 구조체.
	struct Direction
	{
		// 위치.
		int x = 0;
		int y = 0;

		// 이동 비용.
		float cost = 0.0f;
	};

public:
	AStar();
	~AStar();

private:
	// 열린 리스트(방문할 노드의 목록).
	std::vector<Node*> openList;

	// 닫힌 리스트(방문한 노드의 목록).
	std::vector<Node*> closedList;

	// 시작 노드.
	Node* startNode = nullptr;

	// 목표 노드.
	Node* goalNode = nullptr;
};