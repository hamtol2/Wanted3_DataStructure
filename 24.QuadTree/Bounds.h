#pragma once

/*
* �ۼ���: �弼�� (2025.8.25).
* 2�������� �簢�� ������ ǥ���ϴ� Ŭ����.
*/

class Bounds
{
public:
	Bounds(float x, float y, float width = 1.0f, float height = 1.0f)
		: x(x), y(y), width(width), height(height)
	{
	}

	// ��ħ ���� �Լ�.
	bool Intersects(const Bounds& other) const;

	// Getter/Setter (����/����).
	float GetX() const { return x; }
	float GetY() const { return y; }
	float GetWidth() const { return width; }
	float GetHeight() const { return height; }

	float MaxX() const { return x + width; }
	float MaxY() const { return y + height; }

private:
	// ��ġ ������ ���� ���.
	float x = 0.0f;
	float y = 0.0f;
	float width = 1.0f;
	float height = 1.0f;
};