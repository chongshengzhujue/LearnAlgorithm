#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"

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
	int n = 10000;
	int* arr = SortTestHelper::createIntArr(n, 20, 20000);

	selectSort(arr, 11);
	SortTestHelper::printArray(arr, n);


	delete[] arr;

	int a = 0;
	std::cin >> a;
}