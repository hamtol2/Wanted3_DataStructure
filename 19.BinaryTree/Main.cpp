#include <iostream>
#include "BinaryTree.h"
#include "String.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// ������(Entry Point).
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// Ʈ�� ����.
	//       A
	//      / \
	//     B   C
	//    / \
	//   D   E
	BinaryTree<String> tree("A");
	tree.AddLeftChild("A", "B");	// A ���� �ؿ� B �߰�.
	tree.AddRightChild("A", "C");	// A ������ �ؿ� C �߰�.
	tree.AddLeftChild("B", "D");
	tree.AddRightChild("B", "E");

	// ���� ��ȸ.
	std::cout << "���� ��ȸ\n";
	tree.PreorderTraverse();

	// ����.
	std::cout << "\nE��� ����\n";
	tree.DeleteNode("E");

	// ��ȸ.
	std::cout << "\n���� ��ȸ\n";
	tree.PreorderTraverse();

	std::cin.get();
}