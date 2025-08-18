#include <iostream>

// �迭 ���� ���� ���ϴ� �Լ�.
#define ArraySize(array) sizeof(array) / sizeof(array[0])

// �� ���� ��ȯ�ϴ� �Լ�.
template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

// ���� ���� �Լ�.
void SelectionSort(int* array, int length)
{
	// ���� ó��.
	if (length <= 1)
	{
		return;
	}

	// �ܺ� ������ n-1�� �ݺ�.
	for (int ix = 0; ix < length - 1; ++ix)
	{
		// ���� ��ȸ���� ���� ���� �� ã��.
		// ����.
		int minIndex = ix;

		// ���� ������ ix���� ������ �ݺ�.
		for (int jx = ix + 1; jx < length; ++jx)
		{
			// minIndex ���ϱ�.
			if (array[jx] < array[minIndex])
			{
				minIndex = jx;
			}
		}

		// ��ȯ.
		if (minIndex != ix)
		{
			Swap(array[ix], array[minIndex]);
		}
	}
}

// �迭 ��� �Լ�.
void PrintArray(int array[], int length)
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

// Entry Point.
int main()
{
	// �ڷ� ����.
	int array[] = { 0, 21, 22, 25, 5, 2, 3, 8, 9, 4, 11, 1,19, 20, 23, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	// �迭 ����.
	int length = ArraySize(array);

	// ���� �� ���.
	std::cout << "���� �� �迭: ";
	PrintArray(array, length);

	// ����.
	SelectionSort(array, length);

	// ���� �� ���.
	std::cout << "���� �� �迭: ";
	PrintArray(array, length);

	std::cin.get();
}