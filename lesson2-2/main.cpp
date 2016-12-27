#include <iostream>
#include <algorithm>
#include "Student.h"

template<typename T>
void selectSort(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}

		std::swap(arr[i], arr[minIndex]);
	}
}

int main()
{
	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

	selectSort(arr, 11);

	for (int i = 0; i < 11; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	float floatArr[] = { 10.1f, 9, 8, 7, 6, 5, 4, 3.3f, 2, 1, 0 };

	selectSort(floatArr, 11);

	for (int i = 0; i < 11; i++)
	{
		std::cout << floatArr[i] << " ";
	}

	std::cout << std::endl;
	std::string strArr[] = {"aas", "dsdsd", "awrffa", "ppowow", "wdw"};

	selectSort(strArr, 5);
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << strArr[i].c_str() << " ";
	}

	std::cout << std::endl;

	Students stuArr[] = { { "A", 200 }, { "B", 300 }, { "C", 600 }, {"D", 200} };
	selectSort(stuArr, 4);

	for (size_t i = 0; i < 4; i++)
	{
		std::cout << stuArr[i] << std::endl;
	}

	int a = 0;
	std::cin >> a;
}