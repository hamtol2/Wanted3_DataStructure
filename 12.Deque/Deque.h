#pragma once

#include <iostream>

template<typename T, int Size = 10>
class Deque
{
public:
	Deque()
		: size(Size + 1)
	{
		memset(data, 0, sizeof(int) * size);
	}

	// ������� Ȯ��.
	bool IsEmpty() const
	{
		// �հ� �ڸ� ����Ű�� ��ġ ���� ������ �� ����.
		return front == rear;
	}

	// ����á���� Ȯ��.
	bool IsFull() const
	{
		// rear�� ���� ��ġ(1ĭ ����)�� front�� ������,
		// ���� �� ���·� ��.
		return (rear + 1) % size == front;
	}

	// ť�� ������ �߰�.
	bool AddRear(const T& newData)
	{
		// ����á���� Ȯ��.
		if (IsFull())
		{
			std::cout << "Error: ť�� ������ �ֽ��ϴ�.\n";
			return false;
		}

		// ��(rear) ���� ��ġ�� ���ο� ������ �߰�.
		rear = (rear + 1) % size;
		data[rear] = newData;
		return true;
	}

	// ť���� ������ ����.
	bool DeleteFront(T& outValue)
	{
		// ���� Ȯ��.
		if (IsEmpty())
		{
			std::cout << "Error: ť�� ��� �ֽ��ϴ�.\n";
			return false;
		}

		// �տ� �ִ� ������ ����.
		front = (front + 1) % size;
		outValue = data[front];

		// ������ ����.
		memset(data + front, 0, sizeof(T));
		return true;
	}

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// 
	//

	// ť�� ������ �߰�.
	bool AddFront(const T& newData)
	{
		// ����á���� Ȯ��.
		if (IsFull())
		{
			std::cout << "Error: ť�� ������ �ֽ��ϴ�.\n";
			return false;
		}

		// ��(front) ���� ��ġ�� ���ο� ������ �߰�.
		// [0][1][2][3][4]
		data[front] = newData;
		front = (front - 1 + size) % size;
		return true;
	}

	// ť���� ������ ����.
	bool DeleteRear(T& outValue)
	{
		// ���� Ȯ��.
		if (IsEmpty())
		{
			std::cout << "Error: ť�� ��� �ֽ��ϴ�.\n";
			return false;
		}

		// �ڿ� �ִ� ������ ����.
		// [0][1][2][3][4]
		rear = (rear - 1 + size) % size;
		outValue = data[rear];

		// ������ ����.
		memset(data + rear, 0, sizeof(T));
		return true;
	}

	// ���.
	void Print()
	{
		std::cout << "ť ����: ";
		// [0][1][2][3][4]
		// f:0, r:3
		int max = front < rear ? rear : rear + size;
		for (int ix = front + 1; ix <= max; ++ix)
		{
			std::cout << " " << data[ix % size];
		}

		std::cout << "\n";
	}

private:
	int front = 0;
	int rear = 0;
	int size = 0;
	T data[Size + 1] = { };
};