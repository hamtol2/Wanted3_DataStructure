#include "QuadTree.h"

QuadTree::QuadTree(const Bounds& bounds)
	: root(new Node(bounds))
{
}

QuadTree::~QuadTree()
{
	SafeDelete(root);
}

void QuadTree::Insert(Node* node)
{
	root->Insert(node);
}

std::vector<Node*> QuadTree::Query(Node* queryNode)
{
	// ��ħ ���ɼ��� �ִ� ���� Ȯ��.
	std::vector<Node*> possibleNode;
	root->Query(queryNode->GetBounds(), possibleNode);

	// ���ɼ��� �ִ� ��忡�� ������ ��ġ�� ��� �˻�.
	std::vector<Node*> intersects;

	// ��ħ ���ɼ� �ִ� ���� ��ȸ.
	for (Node* node : possibleNode)
	{
		// �� ������ ������ ��� ��ȸ.
		for (Node* point : node->GetPoints())
		{
			// ��ħ �˻�.
			if (point->GetBounds().Intersects(queryNode->GetBounds()))
			{
				intersects.emplace_back(point);
				continue;
			}
		}
	}

	// ���� ��� ��ȯ.
	// ��Ʈ: �Լ����� ��¿� �迭�� ������ ������ ����ȭ ����.
	return intersects;
}