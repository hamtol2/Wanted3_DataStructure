#pragma once

/*
* �ۼ���: �弼��.
* ���� Ž�� Ʈ�� Ŭ����.
*/

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

#include <iostream>
#include "Node.h"

template<typename T>
class BinarySearchTree
{
public:
	BinarySearchTree() = default;
	~BinarySearchTree()
	{
		// ���� �Լ� ȣ��.
		Destroy();
	}

	// ����.
	// ��Ģ.
	// 1. �ߺ��� ���� ������� �ʴ´�. (�˻��� �ʿ���).
	// 2. ��Ʈ�������� �� ����.
	// 2-1. ��Ʈ�� null�̸� �� ��带 ��Ʈ�� ����.
	// 3. ���� �߰��ϴ� ���� �� ��庸�� ������ ���� ���� Ʈ���� �� �̾.
	// 4. ���� �߰��ϴ� ���� �� ��庸�� ũ�� ������ ���� Ʈ���� �� �̾.
	bool Insert(const T& data)
	{
		// �߰��Ϸ��� ���� �̹� �ִ��� �˻�.
		// �ߺ� ��� X.
		Node<T>* outNode = nullptr;
		if (Find(data, outNode))
		{
			std::cout << "Error: �ߺ��� ���� �־ ��带 �߰����� ���߽��ϴ�.\n";
			return false;
		}

		// ��Ʈ�� null�̸� ��Ʈ�� ����.
		if (!root)
		{
			root = new Node<T>(data);
			return true;
		}

		// ���� ��� �Լ� ȣ��.
		root = InsertRecursive(data, root, nullptr);
		return true;
	}

	// �˻�.
	bool Find(const T& data, Node<T>*& outNode) const
	{
		// ��������� �˻��ϴ� �Լ� ȣ��. (��Ʈ���� �˻� ����).
		return FindRecursive(data, root, outNode);
	}

	// ����.
	bool Delete(const T& data)
	{
		// �˻� (������ ��� �˻�).
		Node<T>* deleteNode = nullptr;
		if (!Find(data, deleteNode))
		{
			std::cout << "Error: ������ ��带 ã�� ���߽��ϴ�.\n";
			return false;
		}

		// ��������� �����ϴ� �Լ� ȣ��.
		root = DeleteRecursive(data, root);
		return true;
	}

	// ���� ��ȸ (���ĵ� ������� ��� ������).

	// �ּڰ� �˻�.
	Node<T>* FindMinValue(Node<T>* node)
	{
		// ���� ���� ���� �ִ� ��� �˻�.
		while (node->GetLeft())
		{
			node = node->GetLeft();
		}

		return node;
	}

	// �ִ� �˻�.
	Node<T>* FindMaxValue(Node<T>* node)
	{
		// ���� ������ ���� �ִ� ��� �˻�.
		while (node->GetRight())
		{
			node = node->GetRight();
		}

		return node;
	}

private:
	// ��� �˻� �Լ�.
	bool FindRecursive(const T& data, Node<T>* node, Node<T>*& outNode) const
	{
		// ���� ����.
		if (!node)
		{
			outNode = nullptr;
			return false;
		}

		// �˻� �����ߴ��� Ȯ��.
		if (node->GetData() == data)
		{
			outNode = node;
			return true;
		}

		// ã�� �����Ͱ� ���� ���.
		if (node->GetData() > data)
		{
			// ���� ���� Ʈ���� �˻� �� ����.
			return FindRecursive(data, node->GetLeft(), outNode);
		}

		// ������ ���� Ʈ���� �˻� �� ����.
		return FindRecursive(data, node->GetRight(), outNode);
	}

	// ��� ���� �Լ�.
	// �߰��Ϸ��� �����Ͱ� ������ ����, ũ�� ���������� �������鼭 ����.
	// ������ ��ġ: ���̻� �������� ���ϴ� ��� = node�� null�� ���.
	Node<T>* InsertRecursive(const T& data, Node<T>* node, Node<T>* parent)
	{
		// ���� ���� (����).
		if (!node)
		{
			// ����.
			return new Node<T>(data, parent);
		}

		// ���� ��� (���� ���� Ʈ���� ����).
		if (node->GetData() > data)
		{
			node->SetLeft(InsertRecursive(data, node->GetLeft(), node));
		}

		// ū ��� (������ ���� Ʈ���� ����).
		else
		{
			node->SetRight(InsertRecursive(data, node->GetRight(), node));
		}

		// ���������� �˻��ϴ� ��� ��ȯ.
		return node;
	}

	// ��� ���� �Լ�.
	Node<T>* DeleteRecursive(const T& data, Node<T>* node)
	{
		// ���� ����.
		if (!node)
		{
			return nullptr;
		}

		// ���� ���.
		if (node->GetData() > data)
		{
			node->SetLeft(DeleteRecursive(data, node->GetLeft()));
		}

		// ū ���.
		else if (node->GetData() < data)
		{
			node->SetRight(DeleteRecursive(data, node->GetRight()));
		}

		// ������ ��� ã��.
		else
		{
			// ���� ó��.
			//        10
			//        /\
			//       5 15
			//      / \
			//     1   7
			//         /\
			//        6  8

			// ����� ��1 (�ڽ��� �� �� ���� ���).
			if (!node->GetLeft() && !node->GetRight())
			{
				delete node;
				return nullptr;
			}

			// ����� ��2 (�ڽ��� �� �� �ִ� ���).
			if (node->GetLeft() && node->GetRight())
			{
				// ����� ��1.
				// 1. ���� �������� ���� ū ������ ��ü.
				// 2. ������ �������� ���� ���� ������ ��ü.

				// ������ ��ġ�� ��� ���� ��ü ������ �Ҵ�.
				node->SetData(
					FindMinValue(node->GetRight())->GetData()
				);

				// ��ü ���ϴ� ��带 ����.
				node->SetRight(
					DeleteRecursive(node->GetData(), node->GetRight())
				);
			}

			// ����� ��3 (�ڽ��� �ϳ��� �ִ� ���).
			else
			{
				// ���ʸ� �ִ� ���.
				if (node->GetLeft())
				{
					// ���� �ڼ��� ��ȯ�ϱ� ���� �ӽ� ����.
					Node<T>* left = node->GetLeft();

					// ��� ����.
					delete node;

					// ���� �ڼ� ��ȯ.
					return left;
				}

				// �����ʸ� �ִ� ���.
				else if (node->GetRight())
				{
					// ������ �ڼ��� ��ȯ�ϱ� ���� �ӽ� ����.
					Node<T>* right = node->GetRight();

					// ��� ����.
					delete node;

					// ������ �ڼ� ��ȯ.
					return right;
				}
			}
		}

		return node;
	}

	void Destroy()
	{
		// ��Ʈ�� ������� ����.
		if (!root)
		{
			return;
		}

		// �ڼյ� ��� �����ϰ� ��Ʈ �����ϵ��� ó��.
		DestroyRecursive(root);
	}

	// �ı� ��� �Լ�.
	void DestroyRecursive(Node<T>* node)
	{
		// ���� ����.
		if (!node)
		{
			return;
		}

		// �ڼ� ���� ��������.
		Node<T>* left = node->GetLeft();
		Node<T>* right = node->GetRight();

		// �ڼ��� ������.
		if (!left && !right)
		{
			delete node;
			node = nullptr;
			return;
		}

		// �ڼ��� ������ ��������� �ѹ� �� ����.
		DestroyRecursive(left);
		DestroyRecursive(right);

		// �ڼ� ��� ���� �� ��� ����.
		delete node;
		node = nullptr;
	}

private:

	// ��Ʈ ���.
	Node<T>* root = nullptr;
};