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

	// 복사 생성자 제거.
	Node(const Node& other) = delete;
//private:
	//Node(const Node& other)
	//{
	//}

	~Node()
	{
		parent = nullptr;
	}

	// 값을 전달해서 자손을 추가하는 함수.
	void AddChild(const T& data)
	{
		AddChild(new Node<T>(data));
	}

	void AddChild(Node<T>* child)
	{
		// 나를 추가될 자손의 부모로 설정.
		child->parent = this;

		// 자손 목록에 추가.
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

	// 노드에 저장할 데이터.
	T data;

	// 부모 참조 변수.
	Node<T>* parent = nullptr;

	// 자손 노드 리스트(동적 배열).
	List<Node<T>*> children;
};