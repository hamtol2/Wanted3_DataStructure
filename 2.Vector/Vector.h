#pragma once

#include <iostream>

// 동적으로(실행중에) 크기가 변하는 배열.
template<typename T>
class Vector
{
public:
	Vector()
		: size(0), capacity(2)
	{
		// 내부 저장 공간 할당.
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

	// 데이터 추가 함수.
	void PushBack(const T& value)
	{
		if (size == capacity)
		{
			ReAllocate(capacity * 2);
		}

		// 저장된 마지막 요소 다음 위치에 새로운 값 저장.
		data[size] = value;

		// 저장된 요소의 크기 증가 처리.
		++size;
	}

private:
	void ReAllocate(int newCapacity)
	{
		// 1. 새로운 공간 할당 (크기 확장해서)

		// 기존 크기에 2배 확장.
		//int newCapacity = capacity * 2;
		T* newBlock = new T[newCapacity];
		memset(newBlock, 0, sizeof(T) * newCapacity);

		// 2. 기존 값 복사/이동.
		memcpy(newBlock, data, sizeof(T) * capacity);
		//for (int ix = 0; ix < capacity; ++ix)
		//{
		//	newBlock[ix] = data[ix];
		//}

		// 3. 다쓴 메모리 공간 해제 및 업데이트.
		delete[] data;
		data = newBlock;
		capacity = newCapacity;
	}

	// Getter.
	T* Data() const { return data; }
	int Size() const { return size; }
	int Capacity() const { return capacity; }

private:
	// 자료 컨테이트.
	T* data = nullptr;

	// 배열에 실제로 저장된 요소의 수.
	int size = 0;

	// 미리 확보해둔 저장 공간의 크기.
	int capacity = 0;
};