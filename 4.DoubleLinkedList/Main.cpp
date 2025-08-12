#include "PreCompiledHeader.h"

#include <iostream>
#include "LinkedList.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// 리스트 생성.
	LinkedList<int> list;

	// 데이터 입력 루프.
	char input[50] = {};
	while (true)
	{
		std::cout << "추가할 데이터를 입력해주세요(종료는 q)\n";
		std::cin >> input;

		// 입력 값이 q/Q 인지 확인.
		if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0)
		{
			break;
		}

		// 예외처리(숫자만 입력 하도록 검증).
		if (!atoi(input))
		{
			std::cout << "숫자만 입력 가능합니다.\n";
			continue;
		}

		// 추가.
		list.PushLast(atoi(input));

		// 출력.
		list.Print();
	}
}