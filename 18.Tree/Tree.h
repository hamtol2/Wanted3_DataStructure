#pragma once

#include "List.h"
#include "Node.h"

template<typename T>
class Tree
{
public:
	Tree(const T& data)
		: root(new Node<T>(data))	// ��� �̴ϼȶ�����.
	{
		//root = new Node<T>(data);
	}

	~Tree()
	{
		// �ڼ� ��� ����.
		List<Node<T>*>& children = root->GetChildren();
		while (children.Size() > 0)
		{
			root->RemoveChild(children[0]);
		}

		// ��Ʈ ����.
		delete root;
		root = nullptr;
	}

	void AddChild(const T& parentData, const T& childData)
	{
		// 1. �˻�.
		Node<T>* outParent = nullptr;
		bool result = Find(parentData, outParent);

		// �θ� ��� �˻��� ���� ������, �θ� ����� �ڼ����� ��� �߰�.
		if (result)
		{
			outParent->AddChild(childData);
			return;
		}

		// �θ� ��� �˻� ����.
		std::cout << "�ش� ���� ���� �θ� ��� �˻��� �����߽��ϴ�.\n";
	}

	bool Remove(const T& data)
	{
		// ������ ��带 �˻��ϰ�, ����.
		Node<T>* outNode = nullptr;
		bool result = Find(data, outNode);

		// �˻� ����(���� ����).
		if (!result)
		{
			std::cout << "������ ��带 ã�� ���߽��ϴ�.\n";
			return false;
		}

		// �˻� ����.
		// ����� ��1: ������ ��尡 ��Ʈ ����� ���.
		// ��Ʈ�� �������� ���ϰ�.
		if (outNode == root)
		{
			//// ��Ʈ�� �ڼ��� ��� ����.
			//while (root->GetChildren().Size() > 0)
			//{
			//	root->RemoveChild(root->GetChildren()[0]);
			//}

			//// ��Ʈ ��� ����.
			//delete root;
			//root = nullptr;
			std::cout << "��Ʈ ���� ������ �� �����ϴ�.\n";
			return false;
		}

		// ����� ��2: ��Ʈ ��尡 �ƴ� ���.
		// ������ ����� �θ� ��忡�� ������ ��带 �����ش޶�� ��û.
		// parent�� �׻� null�� �ƴ���?(������ �� �ִ���?).
		Node<T>* parent = outNode->GetParent();
		parent->RemoveChild(outNode);
		return true;
	}

	/// <summary>
	/// �����ͷ� Ư�� ��带 �˻��ϴ� �Ϲ� �Լ�.
	/// </summary>
	/// <param name="data">�˻��� ������</param>
	/// <param name="outNode">�ش� �����͸� ���� ���(��¿�)</param>
	/// <returns></returns>
	bool Find(const T& data, Node<T>*& outNode)
	{
		return FindRecursive(data, root, outNode);
	}

	bool FindRecursive(const T& data, Node<T>* node, Node<T>*& outNode)
	{
		// ��� �Լ� ���� ����.
		if (node == nullptr)
		{
			outNode = nullptr;
			return false;
		}

		// �˻� ����.
		if (node->GetData() == data)
		{
			outNode = node;
			return true;
		}

		// �ڼ��� ��������� �˻�.
		List<Node<T>*>& children = node->GetChildren();
		int count = children.Size();
		for (int ix = 0; ix < count; ++ix)
		{
			// �ڼ� �˻� ����.
			Node<T>* child = children[ix];
			bool result = FindRecursive(data, child, outNode);

			if (result)
			{
				return true;
			}
		}

		// �˻� ����.
		outNode = nullptr;
		return false;
	}

	// ���� ��ȸ �Լ� (�θ� ���� �湮 -> �ڼ� �湮).
	void PreorderTraverse()
	{
		// ��ȸ ��� �Լ� ȣ��.
		PreorderTraverseRecursive(root);
	}

	// ���� ��ȸ ��� �Լ�.
	// node: �湮�� ���� ���.
	// depth: ����� �� �θ�-�ڼ� ������ ���� �鿩������ ��.
	void PreorderTraverseRecursive(Node<T>* node, int depth = 0)
	{
		// ��� �Լ� ���� ����.
		// if (node == nullptr)
		if (!node)
		{
			return;
		}

		// �X�� ���.
		for (int ix = 0; ix < depth; ++ix)
		{
			std::cout << "    ";
		}

		// �θ� ��� �湮.
		std::cout << node->GetData() << "\n";

		// �ڼ� �湮.
		List<Node<T>*>& children = node->GetChildren();
		if (children.Size() == 0)
		{
			return;
		}

		for (int ix = 0; ix < children.Size(); ++ix)
		{
			Node<T>* child = children[ix];
			PreorderTraverseRecursive(child, depth + 1);
		}
	}

private:

	// ��Ʈ ���.
	Node<T>* root = nullptr;
};