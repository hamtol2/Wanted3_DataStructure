#pragma once

#include <iostream>
#include <Windows.h>

/*
* �ۼ���: �弼�� (2025.08.13).
* �뵵: ���� Ŭ����.
* ���ø����� ������ ����.
* �ִ� ���� ũ�Ⱑ ������.
*/

// ��ü ����?
// 1. �ʿ��� ���� ��� �� ����.
// 2. �����ؾ��ϴ� ����� �޼ҵ�� �ۼ�.
// �޼ҵ�(�޽���(public)/�޼ҵ�(private/protected)).
// ��ü ���� ������ �޽���(public �޼ҵ�)�θ� ��.
// -> ������ ��� �����.

// �ִ� ���� ��.

#define TEST 0

#if TEST
const int stackCount = 1;
#else
const int stackCount = 100;
#endif

template<typename T>
class Stack
{
public:
	Stack() = default;
	~Stack() = default;

	// ���� �Լ�.
	void Clear()
	{
		// �������.
		// ������ ���� ������ ��������� �����?����?
		memset(data, 0, sizeof(T) * stackCount);
		count = 0;
	}

	// ������ ������� Ȯ��.
	bool IsEmpty() const
	{
		return count == 0;
	}

	// ������ ����á���� Ȯ��.
	bool IsFull() const
	{
		return count == stackCount;
	}

	// ���ÿ� ������ �߰�.
	bool Push(const T& exp)
	{
		// ����á���� ��.
		if (IsFull())
		{
			// �޽��� ���� ����.
			MessageBoxA(
				nullptr,
				"������ �������־� �߰��� �Ұ����մϴ�.",
				"Stack Push Error",
				MB_OK
			);

			std::cout << "������ �������־� �߰��� �Ұ����մϴ�.\n";
			return false;
		}

		// ���޵� ����ġ�� �����Ϳ� ����.
		data[count] = exp;
		++count;

		return true;
	}

	// ���ÿ��� ������ ����.
	T Pop()
	{
		// ������� ��.
		if (IsEmpty())
		{
			// �޽��� ���� ����.
			MessageBoxA(
				nullptr,
				"������ ����־� ������ ������ �Ұ����մϴ�.",
				"Stack Pop Error",
				MB_OK
			);

			std::cout << "������ ����־� ������ ������ �Ұ����մϴ�.\n";
			return -1.0f;
		}

		// ������ ������ �ϳ� ���ҽ�Ų �� �� ��ȯ.
		--count;
		return data[count];
	}

	// ���ÿ� ����� ������ �� ��ȯ �Լ�(Getter).
	int Count() const
	{
		return count;
	}

private:

	// ������ ���� ����.
	T data[stackCount] = { };

	// ���ÿ� ����� �ڷ� ��.
	// count�� head(top)���� Ȱ���� ��.
	int count = 0;
};