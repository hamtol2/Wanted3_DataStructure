#include "Bounds.h"

bool Bounds::Intersects(const Bounds& other) const
{
    // �ٸ� ������ ���� ������ ������ �ٱ����� Ȯ��.
    if (other.GetX() > MaxX())
    {
        return false;
    }

    // �ٸ� ������ ���� ������ ���� �ٱ����� Ȯ��.
    if (other.MaxX() < x)
    {
        return false;
    }

    // �ٸ� ������ ���� ������ �Ʒ��� �ٱ����� Ȯ��.
    if (other.GetY() > MaxY())
    {
        return false;
    }

    // �ٸ� ������ ���� ������ ���� �ٱ����� Ȯ��.
    if (other.MaxY() < y)
    {
        return false;
    }

    return true;
}