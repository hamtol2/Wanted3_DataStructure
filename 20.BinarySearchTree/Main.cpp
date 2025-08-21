#include "BinarySearchTree.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// Ʈ�� ��ü ����.
	BinarySearchTree<int> tree;

	// ����.
	tree.Insert(10);
	tree.Insert(20);
	tree.Insert(30);
	tree.Insert(5);
	tree.Insert(1);
	tree.Insert(15);

	// ����.
	tree.Delete(5);
	tree.Delete(15);

	// �˻�.
	Node<int>* result = nullptr;
	if (tree.Find(20, result))
	{
		std::cout << "20�� ã�ҽ��ϴ�.\n";
	}
	else
	{
		std::cout << "20�� ��ã�ҽ��ϴ�.\n";
	}

	std::cin.get();
}