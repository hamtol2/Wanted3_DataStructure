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

	// 첫 노드에 데이터 추가.
	// 노드가 비어 있으면 Head 생성.
	// 노드가 있으면 Head 교체.
	void AddToHead(int newData);

	// 맨 뒤에 노드 추가.
	void Insert(int newData);

	// 노드 삭제.
	void Delete(int data);

	// 출력.
	void Print();

	int Count() const { return count; }

private:
	// Head 노드.
	Node* head = nullptr;

	// 연결 리스트에 저장된 요소의 수.
	int count = 0;
};