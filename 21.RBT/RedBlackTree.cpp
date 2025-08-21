#include "RedBlackTree.h"

// �޸� ���� �Լ�.
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
	// �ʱ� ����.
	if (nil == nullptr)
	{
		// Nil ��带 ����.
		nil = new Node(0, Color::Black);
	}

	// ��Ʈ ��带 Nil�� ���� (Ʈ�� �� ����).
	root = nil;
}

RedBlackTree::~RedBlackTree()
{
	// Todo: ��������� ��� ��带 �����ϴ� �Լ� �ۼ� �� ȣ��.
	
	// Nil ��� ����.
	SafeDelete(nil);
}

Node* RedBlackTree::CreateNode(int data, Color color)
{
	// ��� ����.
	Node* newNode = new Node(data, color);
	newNode->SetLeft(nil);
	newNode->SetRight(nil);

	return newNode;
}

// �˻�.
bool RedBlackTree::Find(int data, Node*& outNode)
{
	// Ʈ���� ������� Ȯ��.
	if (root == nil)
	{
		return false;
	}

	// ��������� �˻� ����.
	return FindRecursive(data, root, outNode);
}

// �߰�.
bool RedBlackTree::Insert(int data)
{
	// �ߺ� ���� Ȯ��.
	Node* node = nullptr;
	if (Find(data, node))
	{
		std::cout << "Error: �̹� ���� ���� �ֽ��ϴ�.\n";
		return false;
	}

	// ���� ó��.

	// Ʈ���� ������� ��Ʈ�� �߰�.
	if (root == nil)
	{
		// ��Ʈ�� ��.
		root = CreateNode(data, Color::Black);
		return true;
	}

	// ��������� ������ ��ġ �˻� �� ���� ó��.
	Node* newNode = CreateNode(data, Color::Red);
	InsertRecursive(root, newNode);

	// Todo: �Ʒ� ���� �ʿ����� Ȯ���� ��.
	// ���� �� ��� ����.
	newNode->SetColor(Color::Red);
	newNode->SetLeft(nil);
	newNode->SetRight(nil);

	// ���� �� ����.
	RestructureAfterInsert(newNode);
}

bool RedBlackTree::FindRecursive(int data, Node* node, Node*& outNode)
{
	// Ż�� ����.
	if (node == nil)
	{
		outNode = nullptr;
		return false;
	}

	// �� Ȯ�� (�˻� ���� Ȯ��).
	if (node->GetData() == data)
	{
		outNode = node;
		return true;
	}

	// ���� ���.
	if (node->GetData() > data)
	{
		return FindRecursive(data, node->GetLeft(), outNode);
	}

	// ū ���.
	return FindRecursive(data, node->GetRight(), outNode);
}

void RedBlackTree::InsertRecursive(Node* node, Node* newNode)
{
	// ������ ���� ���� Ʈ���� ����.
	if (node->GetData() > newNode->GetData())
	{
		// ���� ���� �ڼ��� ������, ���� �ڼ����� �߰�.
		if (node->GetLeft() == nil)
		{
			// ����� ���� �ڼ����� �� ��� ����.
			node->SetLeft(newNode);

			// �� ����� �θ� ���� ���� ����.
			newNode->SetParent(node);
			return;
		}

		// ��������� �� ����.
		InsertRecursive(node->GetLeft(), newNode);
	}

	// ū ���.
	else
	{
		// ������ ���� �ڼ��� ������, ������ �ڼ����� �߰�.
		if (node->GetRight() == nil)
		{
			// ����� ������ �ڼ����� �� ��� ����.
			node->SetRight(newNode);

			// �� ����� �θ� ���� ���� ����.
			newNode->SetParent(node);
			return;
		}

		// ��������� �� ����.
		InsertRecursive(node->GetRight(), newNode);
	}
}

void RedBlackTree::RestructureAfterInsert(Node* newNode)
{
	// �θ� ��尡 �������� ��� (Red-Red Conflict).
	while (newNode != root
		&& newNode->GetParent()->GetColor() == Color::Red)
	{
		// ���� �������� -> �θ��� ��ġ�� ���� �޶���.
		// �θ� �Ҿƹ��� ���� ���� �ڼ��� �� -> �Ҿƹ����� ������ �ڼ� = ����.
		if (newNode->GetParent()
			== newNode->GetParent()->GetParent()->GetLeft())
		{
			// ����.
			Node* uncle = newNode->GetParent()->GetParent()->GetRight();

			// Case1: ���̵� ����.
			// �ذ�: �θ�� ������ Black, �Ҿƹ����� Red�� ���� ��, 
			// �Ҿƹ��� �������� �ٽ� �˻�.
			if (uncle->GetColor() == Color::Red)
			{
				// �θ�/������ ���������� ����.
				newNode->GetParent()->SetColor(Color::Black);
				uncle->SetColor(Color::Black);

				// �Ҿƹ����� ���������� ����.
				newNode->GetParent()->GetParent()->SetColor(Color::Red);

				// ������ �Ҿƹ����� ����.
				newNode = newNode->GetParent()->GetParent();
				continue;
			}

			// ������ �������� �� (Case2/Case3).
			// �ذ�: �θ� Black, �Ҿƹ����� Red�� ���� ��, 
			// �Ҿƹ����� �������� ȸ��.
			
			// Case2: �������.
			// Case3(������)���� ���� �� ���� �ذ� �õ�.
			if (newNode == newNode->GetParent()->GetRight())
			{
				// Todo: ��ȸ��.
			}

			// Case3: �θ�� ���� ��ġ�� �������� ��.
			newNode->GetParent()->SetColor(Color::Black);
			newNode->GetParent()->GetParent()->SetColor(Color::Red);

			// Todo: ��ȸ��.
		}

		// �θ� �Ҿƹ��� ���� ������ �ڼ��� ��.
		else
		{
			// ����.
			Node* uncle = newNode->GetParent()->GetParent()->GetLeft();

			// Case1: ���̵� ����.
			// �ذ�: �θ�� ������ Black, �Ҿƹ����� Red�� ���� ��, 
			// �Ҿƹ��� �������� �ٽ� �˻�.
			if (uncle->GetColor() == Color::Red)
			{
				// �θ�/������ ���������� ����.
				newNode->GetParent()->SetColor(Color::Black);
				uncle->SetColor(Color::Black);

				// �Ҿƹ����� ���������� ����.
				newNode->GetParent()->GetParent()->SetColor(Color::Red);

				// ������ �Ҿƹ����� ����.
				newNode = newNode->GetParent()->GetParent();
				continue;
			}

			// ������ �������� �� (Case2/Case3).
			// �ذ�: �θ� Black, �Ҿƹ����� Red�� ���� ��, 
			// �Ҿƹ����� �������� ȸ��.

			// Case2: �������.
			// Case3(������)���� ���� �� ���� �ذ� �õ�.
			if (newNode == newNode->GetParent()->GetLeft())
			{
				// Todo: ��ȸ��.
			}

			// Case3: �θ�� ���� ��ġ�� �������� ��.
			newNode->GetParent()->SetColor(Color::Black);
			newNode->GetParent()->GetParent()->SetColor(Color::Red);

			// Todo: ��ȸ��.
		}
	}
}

void RedBlackTree::RotateToLeft(Node* node)
{
	// ������ �ڼ� ���.
	Node* right = node->GetRight();

	// ������ �ڼ��� ���� �ڼ� ��带 �θ��� ������ �ڼ����� ���.
	// ���� Ž�� Ʈ�� Ư¡�� ���� ������ �ڼ��� ��� �ڼ��� �θ𺸴� ŭ.
	node->SetRight(right->GetLeft());

	// �θ� ����.
	if (right->GetLeft() != nil)
	{
		right->GetLeft()->SetParent(node);
	}

	// �θ� root�� ���.
	if (right->GetParent() == root)
	{
		// ��Ʈ ����.
		root = right;
		right->SetParent(nullptr);
	}

	// �θ� root�� �ƴ� ���.
	else
	{
		// ���θ� �������� �θ� ��� �־����� Ȯ��.
		if (node == node->GetParent()->GetLeft())
		{
			node->GetParent()->SetLeft(right);
		}
		else
		{
			node->GetParent()->SetRight(right);
		}
	}

	// ������ �ڼ��� ���� �ڼ����� �θ� ��� ���.
	right->SetLeft(node);

	// ������ �ڼ��� �θ� ���θ�� ����.
	right->SetParent(node->GetParent());

	// �θ��� �θ� ������ �ڼ����� ����.
	node->SetParent(right);
}

void RedBlackTree::RotateToRight(Node* node)
{
}