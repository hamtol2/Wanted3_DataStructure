#include <iostream>
#include "Queue.h"

int main()
{
	// ť ��ü ����.
	Queue queue;

	// ������ �߰�.
	for (int ix = 0; ix < 10; ++ix)
	{
		queue.Enqueue(ix + 1);
	}

	// ť ���.
	queue.Print();

	int value = 0;
	queue.Dequeue(value);
	queue.Dequeue(value);
	queue.Dequeue(value);

	queue.Print();

	std::cin.get();
}