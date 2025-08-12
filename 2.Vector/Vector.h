#pragma once

#include <iostream>

// ��������(�����߿�) ũ�Ⱑ ���ϴ� �迭.
// ���ø��� ���� ���Ͽ� �������� �ؾ���.
// inl(inline).
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

	// RValue Reference.
	void PushBack(T&& value)
	{
		if (size == capacity)
		{
			ReAllocate(capacity * 2);
		}

		// �ٽ�. Move Semantic.
		data[size] = std::move(value);
		++size;
	}

	// ���� �� ������ ���� �ε��� ������ �����ε�.
	T& operator[](int index)
	{
		// ���� ó��(Out of Index/Range).
		if (index < 0 || index >= size)
		{
			// ����� ��忡�� �����ϸ�, �ߴ����� ������.
			__debugbreak();
		}

		return data[index];
	}

	// ���� �� ������ ���� �ε��� ������ �����ε�.
	const T& operator[](int index) const
	{
		// ���� ó��(Out of Index/Range).
		if (index < 0 || index >= size)
		{
			// ����� ��忡�� �����ϸ�, �ߴ����� ������.
			__debugbreak();
		}

		return data[index];
	}

	// ���� �Լ�/���� �Լ�.
	T& At(int index)
	{
		// ���� ó��(Out of Index/Range).
		if (index < 0 || index >= size)
		{
			// ����� ��忡�� �����ϸ�, �ߴ����� ������.
			__debugbreak();
		}

		return data[index];
	}

	void Set(int index, const T& value)
	{
		// ���� ó��(Out of Index/Range).
		if (index < 0 || index >= size)
		{
			// ����� ��忡�� �����ϸ�, �ߴ����� ������.
			__debugbreak();
		}

		data[index] = value;
	}

	T* begin()
	{
		return data;
	}

	T* end()
	{
		return data + size;
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
		//	newBlock[ix] = std::move(data[ix]);
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
	// �ڷ� �����̳�.
	T* data = nullptr;

	// �迭�� ������ ����� ����� ��.
	int size = 0;

	// �̸� Ȯ���ص� ���� ������ ũ��.
	int capacity = 0;
};