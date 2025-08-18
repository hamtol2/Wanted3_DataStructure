#include <iostream>

// �迭 ���� ���ϴ� �Լ�.
#define ArraySize(array) sizeof(array) / sizeof(array[0])

// �� ��Ҹ� ��ȯ�ϴ� �Լ�.
template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

// ���� ����.
void InsertionSort(int* array, int length)
{
	// ���� ó��.
	if (length <= 1)
	{
		return;
	}

	// [8][5][6][2][4]
	// 1: key:[5] [8]  [6][2][4]
	// [5][8][6][2][4]
	// 2: key:[6] [5][8] [2][4]
	// [5][6][8][2][4]
	// 3: key:[2] [5][6][8] [4]
	// [2][5][6][8][4]
	// 4: key:[4] [2][5][6][8]   
	// [2][4][5][6][8]

	// ����.
	for (int ix = 1; ix < length; ++ix)
	{
		// Ű ����.
		int keyValue = array[ix];
		int jx = ix - 1;

		// �� �ڸ� ã��.
		while (jx >= 0 && array[jx] > keyValue)
		{
			// �� �б�.
			array[jx + 1] = array[jx];
			--jx;
		}

		// Ű ����.
		array[jx + 1] = keyValue;
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

int main()
{
	// �ڷ� ����.
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	// �迭 ����.
	int length = ArraySize(array);

	std::cout << "���� �� �迭: ";
	PrintArray(array, length);

	// ����.
	InsertionSort(array, length);

	std::cout << "���� �� �迭: ";
	PrintArray(array, length);

	std::cin.get();
}