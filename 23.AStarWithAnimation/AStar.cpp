#include "AStar.h"
#include "Node.h"
#include <Windows.h>

AStar::AStar()
{
}

AStar::~AStar()
{
	// �޸� ����.
	for (Node* node : openList)
	{
		SafeDelete(node);
	}
	openList.clear();

	for (Node* node : closedList)
	{
		SafeDelete(node);
	}
	closedList.clear();
}

std::vector<Node*> AStar::FindPath(
	Node* startNode, Node* goalNode, 
	/*const */std::vector<std::vector<int>>& grid)
{
	// ���� ��� / ��ǥ ��� ����.
	this->startNode = startNode;
	this->goalNode = goalNode;

	// ���� ��带 ���� ���(openlist)�� ����.
	openList.emplace_back(startNode);

	// �����¿�, �밢�� ���� �� ���.
	std::vector<Direction> directions =
	{
		// �ϻ���� �̵�.
		{ 0, 1, 1.0f }, { 0, -1, 1.0f }, { 1, 0, 1.0f }, { -1, 0, 1.0f },

		// �밢�� �̵�.
		{ 1, 1, 1.414f }, { 1, -1, 1.414f }, { -1, 1, 1.414f }, { -1, -1, 1.414f },
	};

	// �湮.
	while (!openList.empty())
	{
		// ���� ����� ���� ��� ���� (���� Ž������ �˻�).
		// ����ȭ ���� -> ���� ���� ���� ������ ã�� �� �ֵ���.
		Node* lowestNode = openList[0];
		for (Node* node : openList)
		{
			if (node->fCost < lowestNode->fCost)
			{
				lowestNode = node;
			}
		}

		// fCost�� ���� ���� ��带 ���� ���� ����.
		Node* currentNode = lowestNode;

		// ���� ��尡 ��ǥ ������� Ȯ��.
		if (IsDestination(currentNode))
		{
			// ��ǥ �����, ���ݱ����� ��θ� ����ؼ� ��ȯ.
			return ConstructPath(currentNode);
		}

		// ���� ��Ͽ� �߰�. (���� ��Ͽ����� ����).
		for (int ix = 0; ix < (int)openList.size(); ++ix)
		{
			// ��ġ ��.
			if (*openList[ix] == *currentNode)
			{
				// iterator�� Ȱ���� ���� �迭���� ��� ����.
				openList.erase(openList.begin() + ix);
				break;
			}
		}

		// ���� ��带 ���� ��Ͽ� �߰�.
		// �̹� ������ �߰� ���ϰ�, ������ �߰�.
		bool isNodeInList = false;
		for (Node* node : closedList)
		{
			if (*node == *currentNode)
			{
				isNodeInList = true;
				break;
			}
		}

		// �湮 ������ �Ʒ� �ܰ� �ǳʶٱ�.
		if (isNodeInList)
		{
			continue;
		}

		// ��Ͽ� �߰�.
		closedList.emplace_back(currentNode);

		// �̿���� �湮.
		for (const Direction& direction : directions)
		{
			// ������ �̵��� ��ġ ����.
			int newX = currentNode->position.x + direction.x;
			int newY = currentNode->position.y + direction.y;

			// �׸��� ������ Ȯ��.
			if (!IsInRange(newX, newY, grid))
			{
				// �׸��� ���̸� ����.
				continue;
			}

			// (�ɼ�) ��ֹ����� Ȯ��.
			// ���� 1�̸� ��ֹ��̶�� ���.
			if (grid[newY][newX] == 1)
			{
				continue;
			}

			// �̹� �湮 �߾ ����.
			// �̹� �湮�ߴ��� Ȯ���ϴ� �Լ� ȣ��.
			float gCost = currentNode->gCost + direction.cost;
			if (HasVisited(newX, newY, gCost))
			{
				continue;
			}

			// �湮�� ���� ��� ����.
			// ��뵵 ���.
			Node* neighborNode = new Node(newX, newY, currentNode);
			neighborNode->gCost = currentNode->gCost + direction.cost;
			// �޸���ƽ ��� ��� �Լ� ȣ��.
			neighborNode->hCost = CalculateHeuristic(neighborNode, goalNode);
			neighborNode->fCost = neighborNode->gCost + neighborNode->hCost;

			// �̿� ��尡 ���� ����Ʈ�� �ִ��� Ȯ��.
			Node* openListNode = nullptr;
			for (Node* node : openList)
			{
				if (*node == *neighborNode)
				{
					openListNode = node;
					break;
				}
			}

			// ��尡 ��Ͽ� ���ų� ����� �θ�, �� ��� �߰�.
			if (openListNode == nullptr
				|| openListNode->gCost > neighborNode->gCost
				|| openListNode->fCost > neighborNode->fCost)
			{
				// �湮�� ��带 Ư�� ������ ����.
				grid[newY][newX] = 5;

				openList.emplace_back(neighborNode);
			}
			else
			{
				SafeDelete(neighborNode);
			}

			// ������.
			DisplayGrid(grid);
			int delay = (int)(0.1f * 1000);
			Sleep(delay);
		}
	}

	return std::vector<Node*>();
}

void AStar::DisplayGridWithPath(
	std::vector<std::vector<int>>& grid, 
	const std::vector<Node*>& path)
{
	static COORD position = { 0, 0 };
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, position);

	int white = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
	int green = FOREGROUND_GREEN;

	// ������ ���� �����ߴ� ������ �ʱ�ȭ.
	for (int y = 0; y < grid.size(); ++y)
	{
		for (int x = 0; x < grid[0].size(); ++x)
		{
			int& value = grid[y][x];
			if (value == 2 || value == 3 || value == 5)
			{
				value = 0;
			}
		}
	}

	// ��θ� ������ �� ���.
	for (int y = 0; y < grid.size(); ++y)
	{
		for (int x = 0; x < grid[0].size(); ++x)
		{
			// ��ֹ�.
			if (grid[y][x] == 1)
			{
				SetConsoleTextAttribute(handle, white);
				std::cout << "1 ";
			}


			// �� ����.
			else if (grid[y][x] == 0)
			{
				SetConsoleTextAttribute(handle, white);
				std::cout << "0 ";
			}
		}

		std::cout << "\n";
	}

	// ��� ���.
	for (const Node* node : path)
	{
		// ��δ� '2'�� ǥ��.
		COORD position{ 
			static_cast<short>(node->position.x * 2), 
			static_cast<short>(node->position.y) 
		};
		SetConsoleCursorPosition(handle, position);
		SetConsoleTextAttribute(handle, green);

		std::cout << "* ";
		int delay = static_cast<int>(0.05f * 1000);
		Sleep(delay);
	}
}

std::vector<Node*> AStar::ConstructPath(Node* goalNode)
{
	// ��� ��ȯ.

	// ��¿� ��� �迭 ����.
	std::vector<Node*> path;
	Node* currentNode = goalNode;
	while (currentNode != nullptr)
	{
		path.emplace_back(currentNode);
		currentNode = currentNode->parent;
	}

	// ���ݱ����� ��δ� ��ǥ -> ���� ��� ����.
	// ���� �� ������ ������� ��.
	std::reverse(path.begin(), path.end());
	return path;
}

bool AStar::IsDestination(const Node* node)
{
	// ��尡 ��ǥ ���� ��ġ�� ������ ��.
	return *node == *goalNode;
}

bool AStar::IsInRange(int x, int y, const std::vector<std::vector<int>>& grid)
{
	// x, y ������ ����� false.
	if (x < 0 || y < 0 || x >= (int)grid[0].size() || y >= (int)grid.size())
	{
		return false;
	}

	// ����� �ʾ����� true.
	return true;
}

bool AStar::HasVisited(int x, int y, float gCost)
{
	// ���� ����Ʈ�� ���� ����Ʈ�� �̹� �ش� ��尡 ������ �湮�� ������ �Ǵ�.
	for (int ix = 0; ix < (int)openList.size(); ++ix)
	{
		Node* node = openList[ix];
		if (node->position.x == x && node->position.y == y)
		{
			// ��ġ�� ����, ��뵵 �� ũ�� �湮�� ���� ����.
			if (node->gCost < gCost)
			{
				return true;
			}
			else if (node->gCost > gCost)
			{
				openList.erase(openList.begin() + ix);
				SafeDelete(node);
			}
		}
	}

	for (int ix = 0; ix < (int)closedList.size(); ++ix)
	{
		Node* node = closedList[ix];
		if (node->position.x == x && node->position.y == y)
		{
			// ��ġ�� ����, ��뵵 ������ �湮�� ���� ����.
			if (node->gCost < gCost)
			{
				return true;
			}
			// ��ġ�� ������ ����� �۴ٸ�, ���� ��� ����.
			else if (node->gCost > gCost)
			{
				closedList.erase(closedList.begin() + ix);
				SafeDelete(node);
			}
		}
	}

	// ��Ͽ� ���ٰ� Ȯ�εǸ� �湮���� ���� ������ �Ǵ�.
	return false;
}

float AStar::CalculateHeuristic(Node* currentNode, Node* goalNode)
{
	// �ܼ� �Ÿ� ������� �޸���ƽ ������� Ȱ��.
	Position diff = *currentNode - *goalNode;

	// �밢�� ���� ���ϱ�. 
	return (float)std::sqrt(diff.x * diff.x + diff.y * diff.y);
}

void AStar::DisplayGrid(std::vector<std::vector<int>>& grid)
{
	static COORD position = { 0, 0 };
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, position);

	int white = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
	int green = FOREGROUND_GREEN;

	for (int y = 0; y < grid.size(); ++y)
	{
		for (int x = 0; x < grid[0].size(); ++x)
		{
			// ���� ��ġ.
			if (grid[y][x] == 2)
			{
				SetConsoleTextAttribute(handle, FOREGROUND_RED);
				std::cout << "S ";
			}

			// ��ǥ ��ġ.
			if (grid[y][x] == 3)
			{
				SetConsoleTextAttribute(handle, FOREGROUND_RED);
				std::cout << "G ";
			}

			// ��ֹ�.
			if (grid[y][x] == 1)
			{
				SetConsoleTextAttribute(handle, white);
				std::cout << "1 ";
			}

			// ���.
			else if (grid[y][x] == 5)
			{
				SetConsoleTextAttribute(handle, green);
				std::cout << "+ ";
			}

			// �� ����.
			else if (grid[y][x] == 0)
			{
				SetConsoleTextAttribute(handle, white);
				std::cout << "0 ";
			}
		}

		std::cout << "\n";
	}
}