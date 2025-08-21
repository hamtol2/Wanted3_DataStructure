#pragma once

/*
* �ۼ���: �弼��.
* ���� Ž�� Ʈ���� ����� ��� Ŭ����.
*/
template<typename T>
class Node
{
public:
	// ������.
	Node(const T& data, Node<T>* parent = nullptr)
		: data(data), parent(parent)
	{
	}

	// ��尡 ������ ������.
	T GetData() const { return data; }
	void SetData(const T& newData) { data = newData; }

	// �θ�.
	Node<T>* GetParent() const { return parent; }
	void SetParent(Node<T>* newParent) { parent = newParent; }

	// ���� �ڼ�.
	Node<T>* GetLeft() const { return left; }
	void SetLeft(Node<T>* newLeft) { left = newLeft; }

	// ������ �ڼ�.
	Node<T>* GetRight() const { return right; }
	void SetRight(Node<T>* newRight) { right = newRight; }

private:
	// ��尡 ������ ������.
	T data;

	// �θ�.
	Node<T>* parent = nullptr;

	// ���� �ڼ�.
	Node<T>* left = nullptr;

	// ������ �ڼ�.
	Node<T>* right = nullptr;
};