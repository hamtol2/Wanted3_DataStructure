#include "HashTable.h"
#include <iostream>
#include <unordered_map>

int main()
{
	std::unordered_map<int, int> testMap;

	// �ؽ����̺� ��ü ����.
	HashTable table;

	// ������ �ӽ� �߰�.
	table.Add("Ronnie", "010-12345678");
	table.Add("Ronnie", "010-23897498");

	table.Add("Kevin",  "010-29384792");
	table.Add("Baker",  "010-23489798");
	table.Add("Taejun", "010-09234859");
	table.Add("Emily",  "010-09809123");

	// ���.
	table.Print();

	// �˻�.
	TPair<std::string, std::string> find;
	if (table.Find("Baker", find)) // �˻� ����.
	{
		std::cout << "�˻� ���: " << find.key << ", " << find.value << "\n";
	}

	// ����.
	table.Delete("Kevin");
	table.Delete("Ronnie");
	table.Delete("Test");

	table.Print();

	std::cin.get();
}