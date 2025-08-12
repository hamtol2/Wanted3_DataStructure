#pragma once

#include "Node.h"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	// ù ��忡 ������ �߰�.
	// ��尡 ��� ������ Head ����.
	// ��尡 ������ Head ��ü.
	void AddToHead(int newData);

	// �� �ڿ� ��� �߰�.
	void Insert(int newData);

	// ��� ����.
	void Delete(int data);

	// ���.
	void Print();

	int Count() const { return count; }

private:
	// Head ���.
	Node* head = nullptr;

	// ���� ����Ʈ�� ����� ����� ��.
	int count = 0;
};