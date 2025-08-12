#include <iostream>
#include "LinkedList.h"

#include <list>
#include <forward_list>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// ����Ʈ ����.
	LinkedList list;

	// �ݺ��ؼ� �Է� �ޱ�.
	char input[50] = {};

	// ������ �߰� ����.
	while (true)
	{
		std::cout << "�߰��� �����͸� �Է����ּ���(����� q)\n";
		std::cin >> input;

		// q�� �������� Ȯ��.
		if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0)
		{
			break;
		}

		// ����ó��.
		if (!atoi(input))
		{
			std::cout << "���ڸ� �Է� �����մϴ�.\n";
			continue;
		}

		// ������ ����.
		list.Insert(atoi(input));

		// ���.
		list.Print();
	}

	// ������ ���� ����.
	while (true)
	{
		std::cout << "������ �����͸� �Է����ּ���(����� q)\n";
		std::cin >> input;

		// q�� �������� Ȯ��.
		if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0)
		{
			break;
		}

		// ����ó��.
		if (!atoi(input))
		{
			std::cout << "���ڸ� �Է� �����մϴ�.\n";
			continue;
		}

		// ������ ����.
		list.Delete(atoi(input));

		// ���.
		list.Print();
	}
}