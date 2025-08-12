#pragma once

#include <iostream>

class Node
{
	// ����� ���ϰ� ó���ϱ� ���� ������ �����ε�.
	friend std::ostream& operator<<(std::ostream& os, const Node& node);

	// LinkedList������ Node Ŭ������ ���� �� ������ �� �ֵ��� ����.
	friend class LinkedList;

private:
	Node();
	Node(int data);

private:
	// ������ �ʵ�.
	int data = 0;

	// ��ũ �ʵ�.
	Node* next = nullptr;
};