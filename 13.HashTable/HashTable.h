#pragma once

#include <iostream>
#include <string>
#include "Pair.h"
#include "LinkedList.h"

/*
* �ۼ���: �弼��.
* �ؽ����̺� Ŭ����.
* Ű-���� ������ �����ϴ� �ڷᱸ��.
*/

class HashTable
{
	// Type Alias(Ÿ�� ������).
private:
	using Entry = TPair<std::string, std::string>;

public:
	HashTable();
	~HashTable();

	// �߰�.
	void Add(const std::string& key, const std::string& value);

	// ����.
	void Delete(const std::string& key);

	// �˻�.
	bool Find(const std::string& key, Entry& outValue);

	// ���.
	void Print();

	// ������� Ȯ��.
	bool IsEmpty() const;

private:

	// ��Ŷ(Bucket) ����.
	static const int bucketCount = 19;

	// 2�� �ڷᱸ�� Ȱ�� (ü�̴�).
	LinkedList<Entry> table[bucketCount] = { };
};