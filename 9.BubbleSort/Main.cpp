#include <iostream>

// �� ���� ���� ��ȯ�ϴ� �Լ�.
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

/*
* �ۼ���: �弼��(2025.08.13).
* ���� ���� �Լ�.
*/
void Sort(int* array, int length)
{
	// ���� ���� (���� ����).
	for (int ix = 0; ix < length - 1; ++ix)
	{
		for (int jx = 0; jx < length - 1 - ix; ++jx)
		{
			// �� �� ��.
			if (array[jx] > array[jx + 1])
			{
				// ��ȯ.
				Swap(array[jx], array[jx + 1]);
			}
		}
	}
}

// ��� �Լ�.
void PrintArray(int* array, int length)
{
	for (int ix = 0; ix < length; ++ix)
	{
		std::cout << array[ix];

		// �������� �޸� �ȳֱ�.
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
	int array[] = { 5, 2, 8, 4, 1 };

	// �迭 ����.
	int length = sizeof(array) / sizeof(array[0]);

	std::cout << "���� ��: ";
	PrintArray(array, length);

	// ����.
	Sort(array, length);

	std::cout << "���� ��: ";
	PrintArray(array, length);

	std::cin.get();
}