#pragma once

#include "Node.h"
#include <iostream>

class RedBlackTree
{
public:
	RedBlackTree();
	~RedBlackTree();

	// �˻�.
	bool Find(int data, Node*& outNode);

	// �߰�.
	bool Insert(int data);

private:

	// ��� ���� �Լ�.
	// ���丮 ����.
	Node* CreateNode(int data, Color color);

	/// <summary>
	/// �˻� ��� �Լ�. 
	/// </summary>
	/// <param name="data">�˻��� ��</param>
	/// <param name="node">���� �˻��ϴ� ���</param>
	/// <param name="outNode">�˻��� ��带 ����� �Ķ����</param>
	bool FindRecursive(int data, Node* node, Node*& outNode);

	// ��� ���� ��� �Լ�.
	void InsertRecursive(Node* node, Node* newNode);

	// ��� ���� �� ������ ó�� �Լ�.
	void RestructureAfterInsert(Node* newNode);

	// ��ȸ�� �Լ�.
	void RotateToLeft(Node* node);

	// ��ȸ�� �Լ�.
	void RotateToRight(Node* node);

private:

	// ��Ʈ ���.
	Node* root = nullptr;

	// Nil ���.
	static Node* nil;
};