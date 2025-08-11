#include <iostream>
#include <array>

// �迭 Ŭ����.
template<typename T, int size>
class Array
{
public:
	Array()
	{
		// �޸� 0���� �ʱ�ȭ.
		memset(data, 0, sizeof(T) * size);
	}

	int GetSize() const { return size; }

	// ������ �����ε�.
	T& operator[](int index)
	{
		// ?.
		if (index < 0 || index > size - 1)
		{
			// Silent is violent.
			return data[0];
		}

		return data[index];
	}

private:
	T data[size];
};


// ���⿡ �� �ʿ��ұ�?.
int main()
{
	//int arrayCount = 10;
	//
	//// �迭 (Array).
	//// ���ÿ� �Ҵ�Ǵ� �迭.
	//int array[10]/* = { }*/;
	//memset(array, 0, sizeof(int) * 5);
	//
	//// ���� �迭(Dynamic Array).
	//int* heapArray = new int[arrayCount];
	////memset(heapArray, 0, )
	//
	//delete[] heapArray;

	std::array<int, 10> testArray;
	//testArray.size();

	const int count = 20;
	Array<int, count> array;
	for (int ix = 0; ix < array.GetSize(); ++ix)
	{
		array[ix] = ix + 1;
	}

	std::cin.get();
}