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
	// 노드 계산을 위한 변수 선언.
	Node* current = head;
	Node* tail = nullptr;

	while (current != nullptr)
	{
		// 다음 노드로 넘어가기 전에 임시 저장.
		tail = current;

		// 다음 노드로 이동.
		current = current->next;

		// 노드 삭제.
		delete tail;
		tail = nullptr;

		// 디버깅 목적.
		--count;
	}
}

void LinkedList::AddToHead(int newData)
{
	// 새로운 노드 생성.
	Node* newNode = new Node(newData);

	// #1: Head가 비어 있는 경우.
	if (head == nullptr)
	{
		head = newNode;
		++count;
		return;
	}

	// #2: Head가 비어 있지 않은 경우.
	// [newNode/head]->[0]->[1]->[2]
	newNode->next = head;		// 주소 복사.
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

// 맨 뒤에 데이터 추가하는 함수.
void LinkedList::Insert(int newData)
{
	// 새 노드 생성.
	Node* newNode = new Node(newData);

	// #1: 리스트가 비어 있는 경우.
	if (head == nullptr)
	{
		head = newNode;
		++count;
		return;
	}

	// [3](newNode).
	// [head]->[1]->[2] [3]->nullptr.
	// 2를 찾아야함. Node->next == nullptr.
	// #2: 리스트가 비어 있지 않은 경우.
	// 1. 마지막 노드 검색.
	Node* current = head;
	Node* trail = nullptr;

	// next 노드가 null일 때까지 검색.
	while (current != nullptr)
	{
		trail = current;
		current = current->next;
	}

	// 마지막 노드 검색 완료된 상태.
	trail->next = newNode;
	++count;
}

void LinkedList::Delete(int data)
{
	// 리스트가 비어 있으면 종료.
	if (head == nullptr)
	{
		// Silent is vilent.
		std::cout << "리스트가 비어 있어서 삭제가 불가능합니다.\n";
		return;
	}

	// 노드 계산을 위한 변수.
	Node* current = head;
	Node* trail = nullptr;

	// 노드가 null이 아닐때까지 반복.
	while (current != nullptr)
	{
		// 종료 조건.

		// 찾으려는 데이터를 가진 노드 검색에 성공한 경우.
		if (current->data == data)
		{
			break;
		}

		// 못찾았으면 검색 이어감.
		trail = current;
		current = current->next;
	}

	// 경우의 수 확인.
	// #1: 리스트에 삭제하려는 데이터가 없음 (못찾음).
	if (current == nullptr)
	{
		//char message[1024] = {};
		//sprintf_s(message, 50, "값: %d 를 찾지 못했습니다\n", data);
		//std::cout << message;

		std::cout << "값: " << data << " 를 찾지 못했습니다.\n";
		return;
	}

	// #2: 검색에 성공한 경우.
	// #2-1: 삭제하려는 노드가 head인 경우.
	if (current == head)
	{
		// head를 삭제해야 하기 때문에 그 다음 노드를 head로 지정.
		head = head->next;
	}
	// #2-2: 삭제하려는 노드가 head가 아닌 경우.
	else
	{
		// [h]->[1]->[2]->[3]->nullptr
		// 예:2를 지워야한다면.
		// trail:1, current:2.
		// [h]->[1]->[3]->nullptr.
		trail->next = current->next;
	}

	// 삭제.
	delete current;
	current = nullptr;
	--count;
}

// 모든 노드 순회하면서 Data 출력.
void LinkedList::Print()
{
	// head 노드부터 순회하면서 출력.
	Node* current = head;

	// 현재 노드가 null일 때까지 반복 (모든 노드 방문).
	while (current != nullptr)
	{
		// 현재 노드 데이터 출력.
		std::cout << *current << "\n";

		// 다음 노드로 이동.
		current = current->next;
	}
}