#include "MergeSort.h"
#include <iostream>

void Merge(
	int* array, 
	int* leftArray, int leftArrayLength, 
	int* rightArray, int rightArrayLength)
{
	// �ε��� �ʱ�ȭ.
	int leftIndex = 0;
	int rightIndex = 0;
	int mergedIndex = 0;

	// ����/������ �迭�� ��Ҹ� ���� �� ���� �迭�� ��Ҹ� array�� ����.
	while (leftIndex < leftArrayLength && rightIndex < rightArrayLength)
	{
		// ũ�� ��.
		// ������ ���õǴ� ��� (���� ��츦 ���ʿ� ����).
		if (leftArray[leftIndex] <= rightArray[rightIndex])
		{
			array[mergedIndex] = leftArray[leftIndex];
			++leftIndex;
		}

		// �������� ���õǴ� ���.
		else
		{
			array[mergedIndex] = rightArray[rightIndex];
			++rightIndex;
		}

		// ���� �迭�� �ε��� ���� ó��.
		++mergedIndex;
	}

	// ���� �ִ� ��� ����.
	while (leftIndex < leftArrayLength)
	{
		array[mergedIndex] = leftArray[leftIndex];
		++leftIndex;
		++mergedIndex;
	}

	while (rightIndex < rightArrayLength)
	{
		array[mergedIndex] = rightArray[rightIndex];
		++rightIndex;
		++mergedIndex;
	}
}

void MergeSort(int* array, int length)
{
	// ���� ó��(��� �Լ� ���� ����).
	if (length <= 1)
	{
		return;
	}

	// �迭 ����.
	// 3 / 2= 1.5->1.
	// mid = 1.
	// lefArray[1] / rightArray[3 - 1 = 2]
	int mid = length / 2;

	// ���ҵ� �� �迭�� ���� Ȯ��.
	// �ʱ�ȭ�ϸ� �� ����.
	int* leftArray = new int[mid];
	memset(leftArray, 0, sizeof(int) * mid);

	int* rightArray = new int[length - mid];
	memset(rightArray, 0, sizeof(int) * (length - mid));

	// �� ����.
	//for (int ix = 0; ix < mid; ++ix)
	//{
	//	leftArray[ix] = array[ix];
	//}

	// ���� �迭�� �� ����, 0���� mid �ε������� ����.
	memcpy(leftArray, array, sizeof(int) * mid);

	// ������ �迭�� �� ����, mid���� length - mid �ε������� ����.
	memcpy(rightArray, array + mid, sizeof(int) * (length - mid));

	// ���� �迭�� ���� ���� ���� (���).
	MergeSort(leftArray, mid);

	// ������ �迭�� ���� ���� ���� (���).
	MergeSort(rightArray, length - mid);

	// ����.
	Merge(array, leftArray, mid, rightArray, length - mid);

	// �޸� ����.
	delete[] leftArray;
	delete[] rightArray;
}