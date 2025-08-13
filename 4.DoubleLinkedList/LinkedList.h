#pragma once

#include <iostream>
#include "Node.h"

// ��� ���� �Լ�.
template<typename T>
void SafeDelete(T*& target)
{
	if (target)
	{
		delete target;
		target = nullptr;
	}
}

template<typename T>
class LinkedList
{
public:
	LinkedList()
		: first(new Node<T>()), last(new Node<T>()), count(0)
	{
		// ���� ��� ���� ����.
		first->next = last;
		last->previous = first;
	}

	~LinkedList()
	{
		// ��� ���� ����.
		Clear();

		// �⺻ ��� ����.
		SafeDelete(first);
		SafeDelete(last);
	}

	// ��� ��ü ���� �Լ�.
	void Clear()
	{
		// ���� ��� ����.
		Node<T>* current = first->next;

		// ������ �ݺ��ϸ鼭 ����.
		while (current != nullptr && current != last)
		{
			// ���� ��� �ӽ� ����.
			Node<T>* next = current->next;

			// ���� ��� ����.
			SafeDelete(current);

			// ���� ���� �̵�.
			current = next;
		}

		// ����.
		count = 0;

		first->next = last;
		last->previous = first;
	}

	// ������ ��ġ�� ��� �߰��ϴ� �Լ�.
	void PushLast(const T& newData)
	{
		// �� ��� ����.
		Node<T>* newNode = new Node<T>();
		newNode->data = newData;

		// newNode:5.
		// [f]<-[1]<-[2]<-[3] <-[5] <-[l]

		// ������ ������ ��� �ӽ� ����.
		// ���� ��� ���� ������ ����.
		Node<T>* previous = last->previous;
		previous->next = newNode;
		newNode->previous = previous;

		// ���ο� ��� ���� ������ ����.
		newNode->next = last;
		last->previous = newNode;

		++count;
	}

	// ù ��ġ�� ���ο� ��� �߰��ϴ� �Լ�.
	void PushFirst(const T& newData)
	{
		// �߰��� ��� ����.
		Node<T>* newNode = new Node<T>();
		newNode->data = newData;

		// [f]->next <- newNode
		// [f]->newNode->[f->next]
		// [f]<-newNode
		Node<T>* next = first->next;
		newNode->next = next;
		first->next = newNode;
		newNode->previous = first;
		next->previous = newNode;

		// ���� ���� ���� ó��.
		++count;
	}

	// ���� �Լ�.
	void Delete(const T& deleteData)
	{
		// ��� �ִ� ����.
		if (first->next == nullptr)
		{
			std::cout << "����Ʈ�� ��� �־� ��带 ������ �� �����ϴ�.\n";
			return;
		}

		// �˻� ����.
		Node<T>* deleteNode = first->next;

		// �������� #2.
		while (deleteNode && deleteNode != last)
		{
			// ������ ��带 ã�� ���.
			// ���� ���� #1.
			if (deleteNode->data == deleteData)
			{
				break;
			}

			// ��ã������ ���� ��带 �̾ �˻� ����.
			deleteNode = deleteNode->next;
		}

		// ����.
		// ã�Ҵ��� Ȯ��.
		if (!deleteNode || deleteNode == last)
		{
			std::cout << "������ ��带 ã�� ���߽��ϴ�.\n";
			return;
		}

		// ���� ����.
		// 2���� ����ٰ� ����.
		// ..[0]->[1]->[2]->[3]->[l]->nullptr.
		// ..[0]->[1]->[3]->[l]->nullptr.

		// �յ��� ������ ����.
		deleteNode->previous->next = deleteNode->next;
		deleteNode->next->previous = deleteNode->previous;

		// ��� ����.
		SafeDelete(deleteNode);

		// ���� �� ���� ó��.
		--count;
	}

	// ���.
	void Print()
	{
		// ���� ������.
		Node<T>* current = first->next;

		while (current && current != last)
		{
			std::cout << "������: " << current->data << "\n";
			current = current->next;
		}
	}

private:
	// ó���� �������� ����Ű�� ���.
	Node<T>* first = nullptr;
	Node<T>* last = nullptr;

	// ����Ʈ�� ����� ��� ��.
	int count = 0;
};