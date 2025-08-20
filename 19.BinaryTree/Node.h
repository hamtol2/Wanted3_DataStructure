#pragma once

// ������ ���.
// AOT / JIT.
// AOT: Ahead Of Time. -> �̸�(���� ��ȯ) ������ ����(c/c++/object-c...) -> Mac
// JIT: Just In Time.  -> ������(���� ��ȯ) C# -> MS/Android.

/*
* �ۼ���: �弼�� (2025.08.20).
* ���� Ʈ���� ���� ��� Ŭ����.
*/
template<typename T>
class Node
{
	// friend ����.
	template<typename T>
	friend class BinaryTree;

	// public �Լ�(�޼ҵ�) = �������̽�(��).
public:

	// ������.
	Node()
		: data(), parent(nullptr), left(nullptr), right(nullptr)
	{
	}

	Node(const T& data)
		: data(data), parent(nullptr), left(nullptr), right(nullptr)
	{
	}

	// �⺻ �Ҹ��ڸ� ��������� ����.
	~Node() = default;

	// ------------------ //
	// �ڼ� �߰� �Լ�. AddLeftChild / AddRightChild.
	void AddLeftChild(const T& data)
	{
		// ��带 �����ؼ� �ٸ� �Լ� ȣ��.
		AddLeftChild(new Node<T>(data));
	}

	void AddLeftChild(Node<T>* child)
	{
		// child�� �θ� ���� (����).
		child->SetParent(this);

		// ���� �ڼ� ����.
		left = child;
	}

	// �ڼ� �߰� �Լ�. AddRightChild.
	void AddRightChild(const T& data)
	{
		// ��带 �����ؼ� �ٸ� �Լ� ȣ��.
		AddRightChild(new Node<T>(data));
	}

	void AddRightChild(Node<T>* child)
	{
		// child�� �θ� ���� (����).
		child->SetParent(this);

		// ������ �ڼ� ����.
		right = child;
	}

	// ���� �Լ�.
	void Destroy()
	{
		// �θ� ��� ����.
		if (parent)
		{
			// �� ��尡 �θ� ���� �������� Ȯ��.
			if (parent->GetLeftChild() == this)
			{
				parent->left = nullptr;
			}

			// �� ��尡 �θ� ���� ���������� Ȯ��.
			else if (parent->GetRightChild() == this)
			{
				parent->right = nullptr;
			}
		}
		
		// �ڼձ��� �湮�ؼ� ��� ����.
		DestroyRecursive(this);
	}

	// Getter/Setter.
	T GetData() const { return data; }
	
	Node<T>* GetParent() const { return parent; }
	void SetParent(Node<T>* newParent) { parent = newParent; }

	Node<T>* GetLeftChild() const { return left; }
	Node<T>* GetRightChild() const { return right; }

	// public �޼ҵ� = �޽��� (�������̽�).
	// private �޼ҵ�.
private:

	// ���� ��� �Լ�.
	void DestroyRecursive(Node<T>* node)
	{
		// Ż�� ����.
		if (!node)
		{
			return;
		}

		// �ڼ� ����� ���� Ȯ��.
		Node<T>* leftChild = node->GetLeftChild();
		Node<T>* rightChild = node->GetRightChild();

		// ����� ��1: �ڼ��� ���� ���.
		if (leftChild == nullptr && rightChild == nullptr)
		{
			// ���� ���� �� ����.
			delete node;
			node = nullptr;
			return;
		}

		// ����� ��2: �ڼ��� �ִ� ���.
		// ��������� �ڼ� ��带 ����.
		DestroyRecursive(leftChild);
		DestroyRecursive(rightChild);

		// ���� ����.
		delete node;
		node = nullptr;
	}

private:

	// ������.
	T data;

	// �θ� ��� ������.
	Node<T>* parent = nullptr;

	// ���� �ڼ� ������.
	Node<T>* left = nullptr;

	// ������ �ڼ� ������.
	Node<T>* right = nullptr;
};