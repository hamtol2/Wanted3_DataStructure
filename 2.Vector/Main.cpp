#include <iostream>
#include "Vector.h"
#include <vector>

int main()
{
	const int count = 30;
	Vector<int> vector;

	std::vector<int> vector2;
	std::vector<int>::iterator vector2Interator;
	for (int ix = 0; ix < count; ++ix)
	{
		vector.PushBack(ix + 1);
	}

	for (const auto& item : vector)
	{
		std::cout << item << " ";
	}

	std::cout << "\n";

	std::cin.get();
}