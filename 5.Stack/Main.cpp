#include <iostream>
#include "Stack.h"
#include <stack>

// 실행용이기 때문에 필요함.
int main()
{
	//std::stack<float> expStack;
	//expStack.emplace(10.0f);

	// 스택 객체 생성.
	Stack<float> stack;

	// 경험치 추가.
	stack.Push(15.0f);
	stack.Push(30.0f);

	// 경험치 추출.
	while (!stack.IsEmpty())
	{
		std::cout << "경험치: " << stack.Pop() << "\n";
	}

	//float exp = stack.Pop();
	//exp = stack.Pop();

	std::cin.get();
}