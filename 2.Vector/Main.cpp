#include <iostream>
#include "Vector.h"
#include <vector>

int main()
{
	const int count = 30;
	Vector<int> vector;

	std::vector<int> vector2;
	for (int ix = 0; ix < count; ++ix)
	{
		vector.PushBack(ix + 1);
	}

	//for (auto& item : vector)
	//{
	//
	//}

	std::cin.get();
}