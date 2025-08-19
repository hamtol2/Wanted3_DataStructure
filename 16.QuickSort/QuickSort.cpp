#include "QuickSort.h"

int Partition(int* array, int left, int right)
{
    // �ǹ��� �������� �迭�� ����.
    int pivot = array[left];

    // ���ʿ��� ���������� �̵��ϸ鼭
    // �ǹ����� ū ���� �˻�.
    int low = left + 1;

    // �����ʿ��� �������� �̵��ϸ鼭
    // �ǹ����� ���� ���� �˻�.
    int high = right;

    // low�� high�� ������ ������ �ݺ�.
    while (low <= high)
    {
        // ���ʿ��� ���������� �˻�.
        while (array[low] <= pivot)
        {
            if (low < right)
            {
                ++low;
            }
            else
            {
                break;
            }
        }

        // �����ʿ��� �������� �˻�.
        while (array[high] >= pivot)
        {
            if (high > left)
            {
                --high;
            }
            else
            {
                break;
            }
        }

        // ���� ���� Ȯ��.
        // low�� high�� ���� ���������� ���� ����.
        if (low > high)
        {
            break;
        }

        // low�� high�� ��ȯ.
        Swap<int>(array[low], array[high]);
    }

    // �ǹ� ���� ���� ������ ������ ������ ��Ҹ� ��ȯ.
    Swap<int>(array[left], array[high]);

    // ���� ������ ������ �ε����� ��ȯ.
    return high;
}

void QuickSort(int* array, int left, int right)
{
    // ���� ó��.
    // ���� �ε����� ������ �ε����� ��ġ�ų� �����ߴ��� Ȯ��.
    if (left >= right)
    {
        return;
    }

    // �ǹ��� �������� �迭 ����.
    int pivot = Partition(array, left, right);

    // ���� �迭 ���� (���).
    QuickSort(array, left, pivot - 1);

    // ������ �迭 ���� (���).
    QuickSort(array, pivot + 1, right);
}