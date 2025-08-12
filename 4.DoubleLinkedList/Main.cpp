#include "PreCompiledHeader.h"

#include <iostream>
#include "LinkedList.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// ����Ʈ ����.
	LinkedList<int> list;

	// ������ �Է� ����.
	char input[50] = {};
	while (true)
	{
		std::cout << "�߰��� �����͸� �Է����ּ���(����� q)\n";
		std::cin >> input;

		// �Է� ���� q/Q ���� Ȯ��.
		if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0)
		{
			break;
		}

		// ����ó��(���ڸ� �Է� �ϵ��� ����).
		if (!atoi(input))
		{
			std::cout << "���ڸ� �Է� �����մϴ�.\n";
			continue;
		}

		// �߰�.
		list.PushLast(atoi(input));

		// ���.
		list.Print();
	}
}