#include <iostream>
#include <array>

// 배열 클래스.
template<typename T, int size>
class Array
{
public:
	Array()
	{
		// 메모리 0으로 초기화.
		memset(data, 0, sizeof(T) * size);
	}

	int GetSize() const { return size; }

	// 연산자 오버로딩.
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


// 여기에 왜 필요할까?.
int main()
{
	//int arrayCount = 10;
	//
	//// 배열 (Array).
	//// 스택에 할당되는 배열.
	//int array[10]/* = { }*/;
	//memset(array, 0, sizeof(int) * 5);
	//
	//// 동적 배열(Dynamic Array).
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