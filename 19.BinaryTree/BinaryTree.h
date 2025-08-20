#pragma once

#include <iostream>
#include "Node.h"

template<typename T>
class BinaryTree
{
public:
	BinaryTree()
		: root(nullptr)
	{
	}

	BinaryTree(const T& data)
	{
		// ��Ʈ ��� ����.
		root = new Node<T>(data);
	}

	~BinaryTree()
	{
		// null üũ �� ����.
		if (root)
		{
			root->Destroy();
		}
	}

	// �ڼ� �߰� �Լ�.

	// ���� �ڼ� �߰�.
	void AddLeftChild(const T& parentData, const T& childData)
	{
		// 1. �˻�(�θ� ã��).
		Node<T>* parent = nullptr;
		bool result = Find(parentData, parent);

		// �˻� ����.
		if (result)
		{
			parent->AddLeftChild(childData);
			return;
		}

		// �˻� ����.
		std::cout << "�߰� ����: �θ� ��带 ã�� ���߽��ϴ�.\n";
	}

	// ������ �ڼ� �߰�.
	void AddRightChild(const T& parentData, const T& childData)
	{
		// 1. �˻�(�θ� ã��).
		Node<T>* parent = nullptr;
		bool result = Find(parentData, parent);

		// �˻� ����.
		if (result)
		{
			parent->AddRightChild(childData);
			return;
		}

		// �˻� ����.
		std::cout << "�߰� ����: �θ� ��带 ã�� ���߽��ϴ�.\n";
	}

	bool Find(const T& data, Node<T>*& outNode)
	{
		// ��� �˻� �Լ� ȣ��.
		return FindRecursive(data, root, outNode);
	}

	// ���� ��ȸ �Լ�.
	void PreorderTraverse()
	{
		// ��� ��ȸ �Լ� ȣ��.
		PreorderTraverseRecursive(root);
	}

	// ����.
	bool DeleteNode(const T& data)
	{
		// 1 �˻�.
		Node<T>* deleteNode = nullptr;
		bool result = Find(data, deleteNode);

		// ã������ ����.
		if (result)
		{
			deleteNode->Destroy();
			return true;
		}

		// ��ã���� �޽��� ���.
		std::cout << "���� ����: ��带 ã�� ���߽��ϴ�.\n";
		return false;
	}

	// Getter.
	// ����/������ �ڼ� ��ȯ �Լ�.
	Node<T>* GetLeft() const { return root->GetLeftChild(); }
	Node<T>* GetRight() const { return root->GetRightChild(); }

private:
	// ��� �˻� �Լ�.
	bool FindRecursive(const T& data, Node<T>* node, Node<T>*& outNode)
	{
		// ���� ����.
		if (!node)
		{
			// ��¿� null ����.
			outNode = nullptr;
			return false;
		}

		// Ȯ��.
		if (node->GetData() == data)
		{
			outNode = node;
			return true;
		}

		// ���� �ڼ����� �˻� ����.
		bool result = FindRecursive(data, node->GetLeftChild(), outNode);
		if (result)
		{
			return true;
		}

		// ������ �ڼ����� �˻� ����.
		result = FindRecursive(data, node->GetRightChild(), outNode);
		if (result)
		{
			return true;
		}

		// �˻� ����.
		outNode = nullptr;
		return false;
	}

	// ��� ���� ��ȸ �Լ�.
	void PreorderTraverseRecursive(Node<T>* node, int depth = 0)
	{
		// ���� ����.
		if (!node)
		{
			return;
		}

		// �X�� ���.
		for (int ix = 0; ix < depth; ++ix)
		{
			std::cout << "    ";
		}

		// �θ� �湮.
		std::cout << node->GetData() << "\n";

		// ���� �ڼ� �湮.
		PreorderTraverseRecursive(node->GetLeftChild(), depth + 1);
		
		// ������ �ڼ� �湮.
		PreorderTraverseRecursive(node->GetRightChild(), depth + 1);
	}

private:

	// ��Ʈ ���.
	Node<T>* root = nullptr;
};