#include <iostream>
#include "LinkedList.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// 리스트 생성.
	LinkedList list;

	// 테스트.
	list.Delete(10);

	// 데이터 추가.
	list.Insert(10);
	list.Insert(50);
	list.Insert(30);
	list.Insert(20);

	// 출력.
	list.Print();

	// 데이터 삭제.
	list.Delete(100);
	list.Delete(30);
	list.Delete(50);

	std::cin.get();
}