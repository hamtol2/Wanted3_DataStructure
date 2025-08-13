#include <iostream>
#include "Stack.h"

// ��ǥ�� ��Ÿ���� Ŭ����.
class Vector2
{
public:
	Vector2(int x = 0, int y = 0)
		: x(x), y(y)
	{
	}

	// ��� ���Ǹ� ���� ������ �����ε�.
	friend std::ostream& operator<<(
		std::ostream& os,
		const Vector2& position)
	{
		return os << "(" << position.x << "," << position.y << ")";
	}

	int x = 0;
	int y = 0;
};

// ���� ��.
const size_t MAZE_SIZE = 6;

// map[y][x];
// s: ��������.
// g: ��ǥ����.
// 1: �̵��Ұ�.
// 0: �̵�����.
char map[MAZE_SIZE][MAZE_SIZE] =
{
	{'1','1','1','1','1','1'},
	{'s','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','g'},
	{'1','1','1','1','1','1'}
};

// ������ ��ġ�� �̵� �������� Ȯ���ϴ� �Լ�.
// �Է��� ��(y), ��(x) ������.
bool IsValidLocation(int y, int  x)
{
	// ���� ó��.
	if (y < 0 || y >= MAZE_SIZE || x < 0 || x >= MAZE_SIZE)
	{
		return false;
	}

	// Ȯ��.
	return map[y][x] == '0' || map[y][x] == 'g';
}

// ȭ�� ����� �Լ�.

// ��ġ ��� �Լ�.

int main()
{

}