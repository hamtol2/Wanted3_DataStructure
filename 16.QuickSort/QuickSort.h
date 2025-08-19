#pragma once

// �� ���� ���� ��ȯ�ϴ� �Լ�.
template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

// �迭�� ������ �� �ε����� ��ȯ�ϴ� �Լ�.
int Partition(int* array, int left, int right);

// �� ���� �Լ�.
void QuickSort(int* array, int left, int right);