#include <iostream>
#include "Tree.h"
#include "String.h"

int main()
{
	//String testString("Ronnie");
	//testString = testString + " Jang";
	//
	//std::cout << testString << "\n";

	// Ʈ�� ����.
	Tree<String> tree("A");
	tree.AddChild("A", "B");	// A�� �ڼ����� B �߰�.
	tree.AddChild("A", "C");	// A�� �ڼ����� C �߰�.
	tree.AddChild("B", "D");	// B�� �ڼ����� D �߰�.
	tree.AddChild("B", "E");	// B�� �ڼ����� E �߰�.
	tree.AddChild("C", "F");	// C�� �ڼ����� F �߰�.

	std::cin.get();
}