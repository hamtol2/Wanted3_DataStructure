#pragma once

#include <iostream>

class Node
{
	// 출력을 편하게 처리하기 위해 연산자 오버로딩.
	friend std::ostream& operator<<(std::ostream& os, const Node& node);

	// LinkedList에서만 Node 클래스를 생성 및 접근할 수 있도록 선언.
	friend class LinkedList;

private:
	Node();
	Node(int data);

private:
	// 데이터 필드.
	int data = 0;

	// 링크 필드.
	Node* next = nullptr;
};