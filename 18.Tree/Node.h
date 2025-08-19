#pragma once

#include "List.h"

template<typename T>
class Node
{
public:
	Node()
		: data(), parent(nullptr)
	{
	}

	Node(const T& data)
		: data(data), parent(nullptr)
	{
	}

	// ���� ������ ����.
	Node(const Node& other) = delete;
//private:
	//Node(const Node& other)
	//{
	//}

	~Node()
	{
		parent = nullptr;
	}

	// ���� �����ؼ� �ڼ��� �߰��ϴ� �Լ�.
	void AddChild(const T& data)
	{
		AddChild(new Node<T>(data));
	}

	void AddChild(Node<T>* child)
	{
		// ���� �߰��� �ڼ��� �θ�� ����.
		child->parent = this;

		// �ڼ� ��Ͽ� �߰�.
		children.PushBack(child);
	}

	// Getter.
	T GetData() const
	{
		return data;
	}

	const List<Node<T>*>& GetChildren() const
	{
		return children;
	}

	List<Node<T>*>& GetChildren()
	{
		return children;
	}

	Node<T>* GetParent() const
	{
		return parent;
	}

	// Setter.
	void SetParent(const Node<T>* const parent)
	{
		this->parent = parent;
	}

private:

	// ��忡 ������ ������.
	T data;

	// �θ� ���� ����.
	Node<T>* parent = nullptr;

	// �ڼ� ��� ����Ʈ(���� �迭).
	List<Node<T>*> children;
};