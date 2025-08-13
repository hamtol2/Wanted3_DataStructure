#include <iostream>
#include "Stack.h"

// 좌표를 나타내는 클래스.
class Vector2
{
public:
	Vector2(int x = 0, int y = 0)
		: x(x), y(y)
	{
	}

	// 출력 편의를 위해 연산자 오버로딩.
	friend std::ostream& operator<<(
		std::ostream& os,
		const Vector2& position)
	{
		return os << "(" << position.x << "," << position.y << ")";
	}

	int x = 0;
	int y = 0;
};

// 작은 맵.
const size_t MAZE_SIZE = 6;

// map[y][x];
// s: 시작지점.
// g: 목표지점.
// 1: 이동불가.
// 0: 이동가능.
char map[MAZE_SIZE][MAZE_SIZE] =
{
	{'1','1','1','1','1','1'},
	{'s','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','g'},
	{'1','1','1','1','1','1'}
};

// 가려는 위치가 이동 가능한지 확인하는 함수.
// 입력은 행(y), 열(x) 순서로.
bool IsValidLocation(int y, int  x)
{
	// 예외 처리.
	if (y < 0 || y >= MAZE_SIZE || x < 0 || x >= MAZE_SIZE)
	{
		return false;
	}

	// 확인.
	return map[y][x] == '0' || map[y][x] == 'g';
}

// 화면 지우기 함수.

// 위치 출력 함수.

int main()
{

}