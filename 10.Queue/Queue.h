#pragma once

#include <iostream>

const int maxQueueCount = 100;
class Queue
{
public:
	Queue()
	{
		memset(data, 0, sizeof(int) * maxQueueCount);
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
		return (rear + 1) % maxQueueCount == front;
	}

	// ť�� ������ �߰�.
	bool Enqueue(int newData)
	{
		// ����á���� Ȯ��.
		if (IsFull())
		{
			std::cout << "Error: ť�� ������ �ֽ��ϴ�.\n";
			return false;
		}

		// ��(rear) ���� ��ġ�� ���ο� ������ �߰�.
		rear = (rear + 1) % maxQueueCount;
		data[rear] = newData;
		return true;
	}

	// ť���� ������ ����.
	bool Dequeue(int& outValue)
	{
		// ���� Ȯ��.
		if (IsEmpty())
		{
			std::cout << "Error: ť�� ��� �ֽ��ϴ�.\n";
			return false;
		}

		// �տ� �ִ� ������ ����.
		front = (front + 1) % maxQueueCount;
		outValue = data[front];

		// �ʿ信 ���� ������ ���� ����.
		data[front] = 0;
		return true;
	}

	// ���.
	void Print()
	{
		std::cout << "ť ����: ";
		// [0][1][2][3][4]
		// f:0, r:3
		int max = front < rear ? rear : rear + maxQueueCount;
		for (int ix = front + 1; ix <= max; ++ix)
		{
			std::cout << " " << data[ix % maxQueueCount];
		}

		std::cout << "\n";
	}

private:
	int front = 0;
	int rear = 0;
	int data[maxQueueCount] = { };
};