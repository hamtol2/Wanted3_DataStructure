#pragma once

#include <iostream>

// ��������(�����߿�) ũ�Ⱑ ���ϴ� �迭.
template<typename T>
class Vector
{
public:
	Vector()
		: size(0), capacity(2)
	{
		// ���� ���� ���� �Ҵ�.
		data = new T[capacity];
	}

	// RAII.
	~Vector()
	{
		if (data) /* if (data != nullptr) */
		{
			delete[] data;
		}
	}

	// ������ �߰� �Լ�.
	void PushBack(const T& value)
	{
		if (size == capacity)
		{
			ReAllocate(capacity * 2);
		}

		// ����� ������ ��� ���� ��ġ�� ���ο� �� ����.
		data[size] = value;

		// ����� ����� ũ�� ���� ó��.
		++size;
	}

private:
	void ReAllocate(int newCapacity)
	{
		// 1. ���ο� ���� �Ҵ� (ũ�� Ȯ���ؼ�)

		// ���� ũ�⿡ 2�� Ȯ��.
		//int newCapacity = capacity * 2;
		T* newBlock = new T[newCapacity];
		memset(newBlock, 0, sizeof(T) * newCapacity);

		// 2. ���� �� ����/�̵�.
		memcpy(newBlock, data, sizeof(T) * capacity);
		//for (int ix = 0; ix < capacity; ++ix)
		//{
		//	newBlock[ix] = data[ix];
		//}

		// 3. �پ� �޸� ���� ���� �� ������Ʈ.
		delete[] data;
		data = newBlock;
		capacity = newCapacity;
	}

	// Getter.
	T* Data() const { return data; }
	int Size() const { return size; }
	int Capacity() const { return capacity; }

private:
	// �ڷ� ������Ʈ.
	T* data = nullptr;

	// �迭�� ������ ����� ����� ��.
	int size = 0;

	// �̸� Ȯ���ص� ���� ������ ũ��.
	int capacity = 0;
};