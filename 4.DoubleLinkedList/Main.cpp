#include "PreCompiledHeader.h"

#include <iostream>
#include "LinkedList.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//#include <vector>

int main()
{
	//std::vector<int> testVector;
	//testVector.reserve(100);		// �� ������? ���Ҵ� �ּ�ȭ.

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// ����Ʈ ����.
	LinkedList<int> list;

	// �Է� ������ �б�.
	FILE* file = nullptr;
	fopen_s(&file, "Input.txt", "rt");
	if (file == nullptr)
	{
		// input/output/error.
		std::cerr << "������ ���� ���߽��ϴ�.\n";
		return -1;
	}

	fseek(file, 0, SEEK_END);
	int fileSize = ftell(file);
	rewind(file);

	char* buffer = new char[fileSize + 1];
	memset(buffer, 0, sizeof(char) * (fileSize + 1));
	size_t sizeRead = fread(buffer, sizeof(char), fileSize + 1, file);

	char* context = nullptr;
	char* data = strtok_s(buffer, " ", &context);
	while (data)
	{
		if (data && atoi(data))
		{
			list.PushLast(atoi(data));
		}

		data = strtok_s(nullptr, " ", &context);
	}

	delete[] buffer;
	fclose(file);

	// ���� �׽�Ʈ.
	char input[50] = {};
	while (true)
	{
		std::cout << "������ �����͸� �Է����ּ���(����� q)\n";
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

		// ����.
		list.Delete(atoi(input));

		// ���.
		list.Print();
	}

	//list.Print();

	std::cin.get();

	// ������ �Է� ����.
	//char input[50] = {};
	//while (true)
	//{
	//	std::cout << "�߰��� �����͸� �Է����ּ���(����� q)\n";
	//	std::cin >> input;

	//	// �Է� ���� q/Q ���� Ȯ��.
	//	if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0)
	//	{
	//		break;
	//	}

	//	// ����ó��(���ڸ� �Է� �ϵ��� ����).
	//	if (!atoi(input))
	//	{
	//		std::cout << "���ڸ� �Է� �����մϴ�.\n";
	//		continue;
	//	}

	//	// �߰�.
	//	list.PushLast(atoi(input));

	//	// ���.
	//	list.Print();
	//}
}