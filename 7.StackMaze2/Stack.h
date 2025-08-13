#pragma once

#include <iostream>
#include <Windows.h>

/*
* 작성자: 장세윤 (2025.08.13).
* 용도: 스택 클래스.
* 템플릿으로 구현된 스택.
* 최대 저장 크기가 설정됨.
*/

const int stackCount = 100;

template<typename T>
class Stack
{
public:
	Stack() = default;
	~Stack() = default;

	// 정리 함수.
	void Clear()
	{
		// 고려사항.
		// 데이터 저장 공간을 명시적으로 비울지?말지?
		memset(data, 0, sizeof(T) * stackCount);
		count = 0;
	}

	// 스택이 비었는지 확인.
	bool IsEmpty() const
	{
		return count == 0;
	}

	// 스택이 가득찼는지 확인.
	bool IsFull() const
	{
		return count == stackCount;
	}

	// 스택에 데이터 추가.
	bool Push(const T& exp)
	{
		// 가득찼는지 비교.
		if (IsFull())
		{
			// 메시지 상자 띄우기.
			MessageBoxA(
				nullptr,
				"스택이 가득차있어 추가가 불가능합니다.",
				"Stack Push Error",
				MB_OK
			);

			std::cout << "스택이 가득차있어 추가가 불가능합니다.\n";
			return false;
		}

		// 전달된 경험치를 데이터에 저장.
		data[count] = exp;
		++count;

		return true;
	}

	// 스택에서 데이터 추출.
	T Pop()
	{
		// 비었는지 비교.
		if (IsEmpty())
		{
			// 메시지 상자 띄우기.
			MessageBoxA(
				nullptr,
				"스택이 비어있어 데이터 추출이 불가능합니다.",
				"Stack Pop Error",
				MB_OK
			);

			std::cout << "스택이 비어있어 데이터 추출이 불가능합니다.\n";
			return 0;
		}

		// 데이터 개수를 하나 감소시킨 뒤 값 반환.
		--count;
		return data[count];
	}

	// 스택에 저장된 데이터 수 반환 함수(Getter).
	int Count() const
	{
		return count;
	}

private:

	// 데이터 저장 공간.
	T data[stackCount] = { };

	// 스택에 저장된 자료 수.
	// count를 head(top)으로 활용할 것.
	int count = 0;
};