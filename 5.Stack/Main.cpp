#include <iostream>
#include "Stack.h"
#include <stack>

// ������̱� ������ �ʿ���.
int main()
{
	//std::stack<float> expStack;
	//expStack.emplace(10.0f);

	// ���� ��ü ����.
	Stack<float> stack;

	// ����ġ �߰�.
	stack.Push(15.0f);
	stack.Push(30.0f);

	// ����ġ ����.
	while (!stack.IsEmpty())
	{
		std::cout << "����ġ: " << stack.Pop() << "\n";
	}

	//float exp = stack.Pop();
	//exp = stack.Pop();

	std::cin.get();
}