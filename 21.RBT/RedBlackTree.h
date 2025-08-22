#pragma once

#include "Node.h"
#include <iostream>
#include <Windows.h>

class RedBlackTree
{
public:
	RedBlackTree();
	~RedBlackTree();

	// �˻�.
	bool Find(int data, Node*& outNode);

	// �߰�.
	bool Insert(int data);

	// ��� �Լ�.
	void Print(int depth = 0, int blackCount = 0);

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

	// ��� ��� �Լ�.
	void PrintRecursive(Node* node, int depth, int blackCount);

	// Ʈ�� �ı� ��� �Լ�.
	void DestroyRecursive(Node* node);

private:

	// ��Ʈ ���.
	Node* root = nullptr;

	// Nil ���.
	/*static */Node* nil = nullptr;
};

enum class TextColor
{
	// �ܼ� ���� ����.
	Red = FOREGROUND_RED,
	Green = FOREGROUND_GREEN,
	Blue = FOREGROUND_BLUE,
	White = Red | Green | Blue,
};

// �ܼ� ���� ���� �Լ�.
void SetTextColor(TextColor color);