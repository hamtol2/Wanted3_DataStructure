#include <iostream>
#include "QuickSort.h"

// �迭 ũ�� ���ϴ� �Լ�.
#define ArraySize(array) sizeof(array) / sizeof(array[0])

// �迭 ��� �Լ�.
void PrintArray(int* array, int length)
{
	for (int ix = 0; ix < length; ++ix)
	{
		std::cout << array[ix];
		if (ix < length - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "\n";
}

int main()
{
	// �ڷ� ����.
	//int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };
	//int array[] = { 10, 7, 8, 9, 1, 5 };
	// �ڷ� ���� 2.
	int array[] =
	{
		1, 58, 10, 20, 56, 63, 73, 5, 28, 37,
		80, 61, 82, 45, 11, 66, 83, 59, 22, 64,
		52, 89, 94, 76, 44, 40, 75, 2, 23, 57,
		92, 8, 41, 96, 15, 84, 35, 69, 54, 47,
		90, 24, 43, 74, 34, 85, 72, 95, 18, 17,
		98, 9, 29, 53, 27, 79, 39, 51, 31, 16,
		6, 97, 26, 100, 21, 48, 33, 60, 91, 19,
		30, 13, 71, 78, 87, 25, 81, 4, 42, 93,
		49, 12, 14, 7, 62, 77, 38, 99, 88, 50,
		32, 46, 70, 3, 86, 68, 36, 67, 55, 65
	};

	// �迭 ũ��.
	int length = (int)ArraySize(array);

	// ���� �� ���.
	std::cout << "���� �� ���: ";
	PrintArray(array, length);

	// ����.
	QuickSort(array, 0, length - 1);

	// ���� �� ���.
	std::cout << "\n���� �� ���: ";
	PrintArray(array, length);

	std::cin.get();
}