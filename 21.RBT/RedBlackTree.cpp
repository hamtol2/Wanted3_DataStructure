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

//Node* RedBlackTree::nil = nullptr;

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
	// ��������� ��� ��带 �����ϴ� �Լ� ȣ��.
	DestroyRecursive(root);
	
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

void RedBlackTree::Print(int depth, int blackCount)
{
	PrintRecursive(root, depth, blackCount);
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
				// ��ȸ��.
				// �θ� �߽����� ȸ�� ó�� (���������� ����� ����).
				newNode = newNode->GetParent();
				RotateToLeft(newNode);
			}

			// Case3: �θ�� ���� ��ġ�� �������� ��.
			// �θ� Black, �Ҿƹ����� Red�� ���� ��, 
			// �Ҿƹ����� �������� ȸ��.
			newNode->GetParent()->SetColor(Color::Black);
			newNode->GetParent()->GetParent()->SetColor(Color::Red);

			// ��ȸ��.
			RotateToRight(newNode->GetParent()->GetParent());
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
				// ��ȸ��.
				// �θ� �߽����� ȸ�� ó�� (���������� ����� ����).
				newNode = newNode->GetParent();
				RotateToRight(newNode);
			}

			// Case3: �θ�� ���� ��ġ�� �������� ��.
			// �θ� Black, �Ҿƹ����� Red�� ���� ��, 
			// �Ҿƹ����� �������� ȸ��.
			newNode->GetParent()->SetColor(Color::Black);
			newNode->GetParent()->GetParent()->SetColor(Color::Red);

			// ��ȸ��.
			RotateToLeft(newNode->GetParent()->GetParent());
		}
	}

	// ��Ʈ ��� ���� ����.
	root->SetColor(Color::Black);
}

// ȸ��: �θ�� �ڼ��� ��ġ�� �ٲٴ� ���.
// ��ȸ�� -> �������� ȸ��. ������ �ڼհ� �θ��� ��ġ�� ��ȯ.
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

// ȸ��: �θ�� �ڼ��� ��ġ�� �ٲٴ� ���.
// ��ȸ�� -> ���������� ȸ��. ���� �ڼհ� �θ��� ��ġ�� ��ȯ.
void RedBlackTree::RotateToRight(Node* node)
{
	// ���� �ڼ� ���.
	Node* left = node->GetLeft();

	// ���� �ڼ��� ������ �ڼ� ��带 �θ��� ���� �ڼ����� ���.
	// ���� Ž�� Ʈ�� Ư¡�� ���� ���� �ڼ��� ��� �ڼ��� �θ𺸴� ����.
	node->SetLeft(left->GetRight());

	// �θ� ����.
	if (left->GetRight() != nil)
	{
		left->GetRight()->SetParent(node);
	}

	// �θ� root�� ���.
	if (left->GetParent() == root)
	{
		// ��Ʈ ����.
		root = left;
		left->SetParent(nullptr);
	}

	// �θ� root�� �ƴ� ���.
	else
	{
		// ���θ� �������� �θ� ��� �־����� Ȯ��.
		if (node == node->GetParent()->GetLeft())
		{
			node->GetParent()->SetLeft(left);
		}
		else
		{
			node->GetParent()->SetRight(left);
		}
	}

	// ���� �ڼ��� ������ �ڼ����� �θ� ��� ���.
	left->SetRight(node);

	// ���� �ڼ��� �θ� ���θ�� ����.
	left->SetParent(node->GetParent());

	// �θ��� �θ� ���� �ڼ����� ����.
	node->SetParent(left);
}

void RedBlackTree::PrintRecursive(Node* node, int depth, int blackCount)
{
	// Ż�� ����.
	if (node == nil)
	{
		return;
	}

	// ��� ������ �����̸� blackCount ����.
	if (node->GetColor() == Color::Black)
	{
		++blackCount;
	}

	// �θ� ǥ�� ���ڿ� ����.
	int parentData = 0;
	const char* position = "Root";

	// �θ� ��尡 �ִ��� Ȯ��.
	if (node->GetParent())
	{
		// �θ� ����� ������ ����.
		parentData = node->GetParent()->GetData();

		// �θ� ���κ��� ���� ����� ��ġ ����.
		if (node == node->GetParent()->GetLeft())
		{
			position = "Left";
		}
		else
		{
			position = "Right";
		}
	}

	// ������ �� ����� ���� ���ڿ�.
	char blackCountString[50] = { };

	// �ڼ��� ������ ��������� ������ ��� �� ����.
	if (node->GetLeft() == nil && node->GetRight() == nil)
	{
		sprintf_s(blackCountString, "------ %d", blackCount);
	}

	// Depth ���.
	for (int ix = 0; ix < depth; ++ix)
	{
		std::cout << "  ";
	}

	// ��� ���� ���� �ܼ� ����.
	if (node->GetColor() == Color::Red)
	{
		SetTextColor(TextColor::Red);
	}
	else
	{
		SetTextColor(TextColor::White);
	}

	// ���� ��� �� ���.
	std::cout
		<< node->GetData() << " "
		<< node->GetColorString() << " ["
		<< position << ", "
		<< parentData << "] "
		<< blackCountString << "\n";

	// ��带 ����� �ڿ��� �ܼ� �������.
	SetTextColor(TextColor::White);

	// ���� ��� ���.
	PrintRecursive(node->GetLeft(), depth + 1, blackCount);
	PrintRecursive(node->GetRight(), depth + 1, blackCount);
}

void RedBlackTree::DestroyRecursive(Node* node)
{
	// ��� Ż�� ����.
	if (node == nil)
	{
		return;
	}

	// �ڽ��� �ִ� ���.
	DestroyRecursive(node->GetLeft());
	DestroyRecursive(node->GetRight());

	// ��� ����.
	SafeDelete(node);
}

void SetTextColor(TextColor color)
{
	// �ܼ� ���� ����.
	static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, static_cast<WORD>(color));
}