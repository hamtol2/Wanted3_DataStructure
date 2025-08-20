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

	// �ڼ� ���� �Լ�.
	// child: ������ �ڼ� ���.
	void RemoveChild(Node<T>* child)
	{
		// ��������� �ڼ��� �ڼձ��� �����ϴ� �Լ� ȣ��.
		RemoveChildRecursive(child);
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
	void SetParent(Node<T>* const parent)
	{
		this->parent = parent;
	}

private:

	// �ڼ� ��带 ������ �� �ڼ��� �ڼձ��� ��������� �����ϴ� �Լ�.
	void RemoveChildRecursive(Node<T>* child)
	{
		// ��� �Լ� ���� ����.
		if (!child)
		{
			return;
		}

		// �ڼ� ��� ��������.
		List<Node<T>*>& children = child->GetChildren();

		// ����� ��1: �ڼ��� ���� ���.
		if (children.Size() == 0)
		{
			// �θ��� �ڼ� ��Ͽ��� ���� ����.
			child->GetParent()->GetChildren().Remove(child);

			// �޸� ����.
			delete child;
			child = nullptr;	// �������ִ� �� ��ü�� ����.
			return;
		}

		// ����� ��2: �ڼ��� �ִ� ���.
		while (children.Size() > 0)
		{
			// �ڼ��� ��ȸ�ϸ鼭 ��������� �ڼ� ����.
			RemoveChildRecursive(children[0]);
		}

		// �ڼ��� ��� ������ �Ŀ��� �θ� ��Ͽ��� ���� ����.
		child->GetParent()->GetChildren().Remove(child);

		// �޸� ����.
		delete child;
		child = nullptr;	// �������ִ� �� ��ü�� ����.
	}

private:

	// ��忡 ������ ������.
	T data;

	// �θ� ���� ����.
	Node<T>* parent = nullptr;

	// �ڼ� ��� ����Ʈ(���� �迭).
	List<Node<T>*> children;
};