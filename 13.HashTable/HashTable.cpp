#include "HashTable.h"

// �ؽ� �Լ�(Hash Function).
// �Ķ���ͷ� ���޹��� Ű�� Ȱ���ؼ� �ؽ�(����)�� �����ϴ� �Լ�.
int GenerateKey(const std::string& keyString)
{
	// ������ Ű ����.
	int key = 0;
	for (int ix = 0; ix < (int)keyString.length(); ++ix)
	{
		//key += keyString[ix] * (ix + 1);
		key = key * 31 + keyString[ix];
	}

	// ���밪���� ��ȯ.
	// �ؽ����̺� ������ ���ؼ��� Ű ���� �ε����� ��ȯ�Ǿ�� �ϴµ�,
	// ������� ������ �Ǳ� ����.
	// �ֻ��� ��Ʈ�� 1�� �����Ǹ� ������ �Ǵ��ϱ� ����.
	//return key < 0 ? -key : key;
	return std::abs(key);
}

HashTable::HashTable()
{
}

HashTable::~HashTable()
{
}

void HashTable::Add(const std::string& key, const std::string& value)
{
	// Ű ����.
	int keyValue = GenerateKey(key);

	// UI -> �̹����� ���ڸ� ǥ���� ��.
	// 0,1,2,3,4,5,6,7,8,9
	// 3421��
	// 3421 / 1000 -> 3, 3421 % 1000, 421.
	// 421 / 100 -> 4, 21.
	// 21 / 10 -> 2, 1.
	// ���� �긮��.
	
	// ��Ŷ �ε����� ��ȯ.
	int bucketIndex = keyValue % bucketCount;

	// ������ ���� ����Ʈ ��������.
	LinkedList<Entry>& list = table[bucketIndex];

	// Ű�� ���� �� �������? ������� ������?
	// STL�� ��쿡�� ��������� ������ Ű�� ����ϴ� ���� 
	// ������� �ʴ� ����� �ڷᱸ���� �����ؼ� ����.
	for (int ix = 0; ix < (int)list.Count(); ++ix)
	{
		// Ű�� ������ ������� ����.
		if (list[ix]->data.key == key)
		{
			std::cout << "�̹� ������ Ű�� ���� �����Ͱ� ����� �ֽ��ϴ�.\n";
			return;
		}
	}

	// �ؽ����̺� �� �߰�.
	list.PushLast(Entry(key, value));
}

void HashTable::Delete(const std::string& key)
{
	// ���� ������ 2�ܰ��� ���� ����.
	// 1. ã��.
	int keyValue = GenerateKey(key);

	// ��Ŷ�ε���.
	int bucketIndex = keyValue % bucketCount;

	// ����Ʈ ��������.
	LinkedList<Entry>& list = table[bucketIndex];

	// ������ Ű���� ���� ������ �˻�.
	for (int ix = 0; ix < (int)list.Count(); ++ix)
	{
		// 2. ����.
		if (list[ix]->data.key == key)
		{
			list.Delete(list[ix]->data);
			std::cout << "�׸��� �����߽��ϴ�.\n";
			return;
		}
	}

	// ���� ����.
	std::cout << "������ �����͸� ã�� ���߽��ϴ�.\n";
}

bool HashTable::Find(const std::string& key, Entry& outValue)
{
	int keyValue = GenerateKey(key);

	// ��Ŷ�ε���.
	int bucketIndex = keyValue % bucketCount;

	// ����Ʈ ��������.
	LinkedList<Entry>& list = table[bucketIndex];

	// �˻��� �ʿ䰡 �ִ��� Ȯ��.
	if (list.Count() == 0)
	{
		std::cout << "�ش� Ű�� �����͸� �˻����� ���߽��ϴ�.\n";
		return false;
	}

	// �˻�.
	for (int ix = 0; ix < (int)list.Count(); ++ix)
	{
		// ���� Ű�� ���� ����Ʈ�� ã������,
		if (list[ix]->data.key == key)
		{
			// ����� �Ķ���Ϳ� �� ����.
			outValue = list[ix]->data;

			// �˻� ���� ��ȯ.
			return true;
		}
	}

	std::cout << "�ش� Ű�� �����͸� �˻����� ���߽��ϴ�.\n";
	return false;
}

// ���.
void HashTable::Print()
{
	for (int ix = 0; ix < bucketCount; ++ix)
	{
		// �迭�ε����� �ش��ϴ� ���Ḯ��Ʈ�� ������� �������� �ǳʶ�.
		LinkedList<Entry>& list = table[ix];

		//if (table[ix].Count() == 0)
		if (list.Count() == 0)
		{
			continue;
		}

		//for (int jx = 0; jx < (int)table[ix].Count(); ++jx)
		for (int jx = 0; jx < (int)list.Count(); ++jx)
		{
			std::cout
				//<< "Ű: " << table[ix][jx]->data.key
				//<< " ��: " << table[ix][jx]->data.value
				//<< "\n";
				<< "Ű: " << list[jx]->data.key
				<< " ��: " << list[jx]->data.value
				<< "\n";
		}
	}
}

// ������� Ȯ��.
bool HashTable::IsEmpty() const
{
	// ���� ������ ��.
	int totalCount = 0;

	// ���̺� ���� ���� ����Ʈ�� ��ȸ�ϸ鼭 �� ����Ʈ ����� ���� �ջ�.
	for (int ix = 0; ix < bucketCount; ++ix)
	{
		totalCount += (int)table[ix].Count();
	}

	// �ջ��� ����� 0�̸� �� ����.
	return totalCount == 0;
}