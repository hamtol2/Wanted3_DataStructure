#include "RedBlackTree.h"

// 메모리 해제 함수.
template<typename T>
void SafeDelete(T*& resource)
{
	if (resource)
	{
		delete resource;
		resource = nullptr;
	}
}

Node* RedBlackTree::nil = nullptr;

RedBlackTree::RedBlackTree()
{
	// 초기 설정.
	if (nil == nullptr)
	{
		// Nil 노드를 생성.
		nil = new Node(0, Color::Black);
	}

	// 루트 노드를 Nil로 설정 (트리 빈 상태).
	root = nil;
}

RedBlackTree::~RedBlackTree()
{
	// Todo: 재귀적으로 모든 노드를 삭제하는 함수 작성 후 호출.
	
	// Nil 노드 삭제.
	SafeDelete(nil);
}

Node* RedBlackTree::CreateNode(int data, Color color)
{
	// 노드 생성.
	Node* newNode = new Node(data, color);
	newNode->SetLeft(nil);
	newNode->SetRight(nil);

	return newNode;
}

// 검색.
bool RedBlackTree::Find(int data, Node*& outNode)
{
	// 트리가 비었는지 확인.
	if (root == nil)
	{
		return false;
	}

	// 재귀적으로 검색 진행.
	return FindRecursive(data, root, outNode);
}

// 추가.
bool RedBlackTree::Insert(int data)
{
	// 중복 여부 확인.
	Node* node = nullptr;
	if (Find(data, node))
	{
		std::cout << "Error: 이미 같은 값이 있습니다.\n";
		return false;
	}

	// 삽입 처리.

	// 트리가 비었으면 루트에 추가.
	if (root == nil)
	{
		// 루트는 블랙.
		root = CreateNode(data, Color::Black);
		return true;
	}

	// 재귀적으로 삽입할 위치 검색 후 삽입 처리.
	Node* newNode = CreateNode(data, Color::Red);
	InsertRecursive(root, newNode);

	// Todo: 아래 로직 필요한지 확인할 것.
	// 삽입 후 노드 정리.
	newNode->SetColor(Color::Red);
	newNode->SetLeft(nil);
	newNode->SetRight(nil);

	// 삽입 후 정리.
	RestructureAfterInsert(newNode);
}

bool RedBlackTree::FindRecursive(int data, Node* node, Node*& outNode)
{
	// 탈출 조건.
	if (node == nil)
	{
		outNode = nullptr;
		return false;
	}

	// 값 확인 (검색 성공 확인).
	if (node->GetData() == data)
	{
		outNode = node;
		return true;
	}

	// 작은 경우.
	if (node->GetData() > data)
	{
		return FindRecursive(data, node->GetLeft(), outNode);
	}

	// 큰 경우.
	return FindRecursive(data, node->GetRight(), outNode);
}

void RedBlackTree::InsertRecursive(Node* node, Node* newNode)
{
	// 작으면 왼쪽 하위 트리에 삽입.
	if (node->GetData() > newNode->GetData())
	{
		// 왼쪽 하위 자손이 없으면, 왼쪽 자손으로 추가.
		if (node->GetLeft() == nil)
		{
			// 노드의 왼쪽 자손으로 새 노드 설정.
			node->SetLeft(newNode);

			// 새 노드의 부모를 현재 노드로 지정.
			newNode->SetParent(node);
			return;
		}

		// 재귀적으로 더 진행.
		InsertRecursive(node->GetLeft(), newNode);
	}

	// 큰 경우.
	else
	{
		// 오른쪽 하위 자손이 없으면, 오른쪽 자손으로 추가.
		if (node->GetRight() == nil)
		{
			// 노드의 오른쪽 자손으로 새 노드 설정.
			node->SetRight(newNode);

			// 새 노드의 부모를 현재 노드로 지정.
			newNode->SetParent(node);
			return;
		}

		// 재귀적으로 더 진행.
		InsertRecursive(node->GetRight(), newNode);
	}
}

void RedBlackTree::RestructureAfterInsert(Node* newNode)
{
	// 부모 노드가 빨간색인 경우 (Red-Red Conflict).
	while (newNode != root
		&& newNode->GetParent()->GetColor() == Color::Red)
	{
		// 삼촌 가져오기 -> 부모의 위치에 따라 달라짐.
		// 부모가 할아버지 기준 왼쪽 자손일 때 -> 할아버지의 오른쪽 자손 = 삼촌.
		if (newNode->GetParent()
			== newNode->GetParent()->GetParent()->GetLeft())
		{
			// 삼촌.
			Node* uncle = newNode->GetParent()->GetParent()->GetRight();

			// Case1: 삼촌도 빨강.
			// 해결: 부모와 삼촌을 Black, 할아버지를 Red로 변경 후, 
			// 할아버지 기준으로 다시 검사.
			if (uncle->GetColor() == Color::Red)
			{
				// 부모/삼촌을 빨간색으로 변경.
				newNode->GetParent()->SetColor(Color::Black);
				uncle->SetColor(Color::Black);

				// 할아버지를 빨간색으로 변경.
				newNode->GetParent()->GetParent()->SetColor(Color::Red);

				// 기준을 할아버지로 변경.
				newNode = newNode->GetParent()->GetParent();
				continue;
			}

			// 삼촌이 검정색일 때 (Case2/Case3).
			// 해결: 부모를 Black, 할아버지를 Red로 변경 후, 
			// 할아버지를 기준으로 회전.
			
			// Case2: 지그재그.
			// Case3(일직선)으로 변경 후 문제 해결 시도.
			if (newNode == newNode->GetParent()->GetRight())
			{
				// Todo: 좌회전.
			}

			// Case3: 부모와 나의 위치가 일직선일 때.
			newNode->GetParent()->SetColor(Color::Black);
			newNode->GetParent()->GetParent()->SetColor(Color::Red);

			// Todo: 우회전.
		}

		// 부모가 할아버지 기준 오른쪽 자손일 때.
		else
		{
			// 삼촌.
			Node* uncle = newNode->GetParent()->GetParent()->GetLeft();

			// Case1: 삼촌도 빨강.
			// 해결: 부모와 삼촌을 Black, 할아버지를 Red로 변경 후, 
			// 할아버지 기준으로 다시 검사.
			if (uncle->GetColor() == Color::Red)
			{
				// 부모/삼촌을 빨간색으로 변경.
				newNode->GetParent()->SetColor(Color::Black);
				uncle->SetColor(Color::Black);

				// 할아버지를 빨간색으로 변경.
				newNode->GetParent()->GetParent()->SetColor(Color::Red);

				// 기준을 할아버지로 변경.
				newNode = newNode->GetParent()->GetParent();
				continue;
			}

			// 삼촌이 검정색일 때 (Case2/Case3).
			// 해결: 부모를 Black, 할아버지를 Red로 변경 후, 
			// 할아버지를 기준으로 회전.

			// Case2: 지그재그.
			// Case3(일직선)으로 변경 후 문제 해결 시도.
			if (newNode == newNode->GetParent()->GetLeft())
			{
				// Todo: 우회전.
			}

			// Case3: 부모와 나의 위치가 일직선일 때.
			newNode->GetParent()->SetColor(Color::Black);
			newNode->GetParent()->GetParent()->SetColor(Color::Red);

			// Todo: 좌회전.
		}
	}
}

void RedBlackTree::RotateToLeft(Node* node)
{
	// 오른쪽 자손 노드.
	Node* right = node->GetRight();

	// 오른쪽 자손의 왼쪽 자손 노드를 부모의 오른쪽 자손으로 등록.
	// 이진 탐색 트리 특징의 의해 오른쪽 자손의 모든 자손은 부모보다 큼.
	node->SetRight(right->GetLeft());

	// 부모 정리.
	if (right->GetLeft() != nil)
	{
		right->GetLeft()->SetParent(node);
	}

	// 부모가 root인 경우.
	if (right->GetParent() == root)
	{
		// 루트 변경.
		root = right;
		right->SetParent(nullptr);
	}

	// 부모가 root가 아닌 경우.
	else
	{
		// 조부모 기준으로 부모가 어디에 있었는지 확인.
		if (node == node->GetParent()->GetLeft())
		{
			node->GetParent()->SetLeft(right);
		}
		else
		{
			node->GetParent()->SetRight(right);
		}
	}

	// 오른쪽 자손의 왼쪽 자손으로 부모 노드 등록.
	right->SetLeft(node);

	// 오른쪽 자손의 부모를 조부모로 설정.
	right->SetParent(node->GetParent());

	// 부모의 부모를 오른쪽 자손으로 설정.
	node->SetParent(right);
}

void RedBlackTree::RotateToRight(Node* node)
{
}