#include <iostream>

// ���� Ž��(�˻�).
// Binary Search.
int BinarySearch(int array[], int target, int low, int high)
{
	// [1,2,3,4,5,6,7,8,9]
	// mid = 5 (�߰���).
	// [1,2,3,4] / [6,7,8,9]
	// target > mid ? target < mid ?
	// target == array[mid].

	// ���� ���� (����/����).

	// �˻� ����.
	if (low > high)
	{
		return -1;
	}

	// �߰� ��.
	int mid = (low + high) / 2;

	// Ž�� ���� ���� Ȯ��.
	if (array[mid] == target)
	{
		return mid;
	}

	// ������ �� ���� Ž��.
	else if (array[mid] < target)
	{
		return BinarySearch(array, target, mid + 1, high);
	}

	// ���� �� Ž��.
	return BinarySearch(array, target, low, mid - 1);
}

int main()
{
	// Ž���� �ڷ�.
	// ���� Ž���� �����Ϸ��� ������ �ʼ�.
	int array[] = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };
	int length = sizeof(array) / sizeof(array[0]);
	int target = 91;
	
	// Ž��.
	int result = BinarySearch(array, target, 0, length - 1);

	if (result < 0)
	{
		std::cout << "�˻� ����\n";
	}
	else
	{
		std::cout << target << "�� " << result << "�� �ε������� ã��\n";
	}

	std::cin.get();
}