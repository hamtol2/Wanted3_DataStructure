#include "RedBlackTree.h"
#include "RedBlackTree.h"
#include "RedBlackTree.h"
#include "RedBlackTree.h"
#include "RedBlackTree.h"
#include "RedBlackTree.h"
#include "RedBlackTree.h"
#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList()
	: head(nullptr), count(0)
{
}

LinkedList::~LinkedList()
{
	// ��� ����� ���� ���� ����.
	Node* current = head;
	Node* tail = nullptr;

	while (current != nullptr)
	{
		// ���� ���� �Ѿ�� ���� �ӽ� ����.
		tail = current;

		// ���� ���� �̵�.
		current = current->next;

		// ��� ����.
		delete tail;
		tail = nullptr;

		// ����� ����.
		--count;
	}
}

void LinkedList::AddToHead(int newData)
{
	// ���ο� ��� ����.
	Node* newNode = new Node(newData);

	// #1: Head�� ��� �ִ� ���.
	if (head == nullptr)
	{
		head = newNode;
		++count;
		return;
	}

	// #2: Head�� ��� ���� ���� ���.
	// [newNode/head]->[0]->[1]->[2]
	newNode->next = head;		// �ּ� ����.
	head = newNode;
	++count;
}

RedBlackTree::RedBlackTree()
{
}

RedBlackTree::~RedBlackTree()
{
}

bool RedBlackTree::Find(int data, Node*& outNode)
{
	return false;
}

// �� �ڿ� ������ �߰��ϴ� �Լ�.
void LinkedList::Insert(int newData)
{
	// �� ��� ����.
	Node* newNode = new Node(newData);

	// #1: ����Ʈ�� ��� �ִ� ���.
	if (head == nullptr)
	{
		head = newNode;
		++count;
		return;
	}

	// [3](newNode).
	// [head]->[1]->[2] [3]->nullptr.
	// 2�� ã�ƾ���. Node->next == nullptr.
	// #2: ����Ʈ�� ��� ���� ���� ���.
	// 1. ������ ��� �˻�.
	Node* current = head;
	Node* trail = nullptr;

	// next ��尡 null�� ������ �˻�.
	while (current != nullptr)
	{
		trail = current;
		current = current->next;
	}

	// ������ ��� �˻� �Ϸ�� ����.
	trail->next = newNode;
	++count;
}

void LinkedList::Delete(int data)
{
	// ����Ʈ�� ��� ������ ����.
	if (head == nullptr)
	{
		// Silent is vilent.
		std::cout << "����Ʈ�� ��� �־ ������ �Ұ����մϴ�.\n";
		return;
	}

	// ��� ����� ���� ����.
	Node* current = head;
	Node* trail = nullptr;

	// ��尡 null�� �ƴҶ����� �ݺ�.
	while (current != nullptr)
	{
		// ���� ����.

		// ã������ �����͸� ���� ��� �˻��� ������ ���.
		if (current->data == data)
		{
			break;
		}

		// ��ã������ �˻� �̾.
		trail = current;
		current = current->next;
	}

	// ����� �� Ȯ��.
	// #1: ����Ʈ�� �����Ϸ��� �����Ͱ� ���� (��ã��).
	if (current == nullptr)
	{
		//char message[1024] = {};
		//sprintf_s(message, 50, "��: %d �� ã�� ���߽��ϴ�\n", data);
		//std::cout << message;

		std::cout << "��: " << data << " �� ã�� ���߽��ϴ�.\n";
		return;
	}

	// #2: �˻��� ������ ���.
	// #2-1: �����Ϸ��� ��尡 head�� ���.
	if (current == head)
	{
		// head�� �����ؾ� �ϱ� ������ �� ���� ��带 head�� ����.
		head = head->next;
	}
	// #2-2: �����Ϸ��� ��尡 head�� �ƴ� ���.
	else
	{
		// [h]->[1]->[2]->[3]->nullptr
		// ��:2�� �������Ѵٸ�.
		// trail:1, current:2.
		// [h]->[1]->[3]->nullptr.
		trail->next = current->next;
	}

	// ����.
	delete current;
	current = nullptr;
	--count;
}

// ��� ��� ��ȸ�ϸ鼭 Data ���.
void LinkedList::Print()
{
	// head ������ ��ȸ�ϸ鼭 ���.
	Node* current = head;

	// ���� ��尡 null�� ������ �ݺ� (��� ��� �湮).
	while (current != nullptr)
	{
		// ���� ��� ������ ���.
		std::cout << *current << "\n";

		// ���� ���� �̵�.
		current = current->next;
	}
}