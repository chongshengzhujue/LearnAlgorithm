#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"

//—°‘Ò≈≈–Ú
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

//≤Â»Î≈≈–Ú
template<typename T>
void insertSort(T arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
			else
				break;
		}
	}
}

//≤Â»Î≈≈–ÚΩ¯Ω◊
template<typename T>
void insertSortAdvance(T arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		T temp = arr[i];
		int j;
		for (j = i; j > 0 && temp < arr[j - 1]; j--)
			arr[j] = arr[j - 1];
		arr[j] = temp;
	}
}

//√∞≈›≈≈–Ú

template<typename T>
void bubbleSort(T arr[], int n)
{
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}

		}
	}
}

//œ£∂˚≈≈–Ú
template<typename T>
void ShellSort(T arr[], int n)
{
	int gap = n / 2;

	while (gap > 0)
	{
		for (int i = gap; i < n; i += gap)
		{
			int temp = arr[i];
			int j;
			for (j = i; j > 0 && temp < arr[j - gap]; j -= gap)
				arr[j - gap] = arr[j];
			arr[j] = temp;
		}
		gap /= 2;
	}
	
}

int main()
{
	int n = 10000;
	int* arr = SortTestHelper::createIntArr(n, 10, n);
	int* arrInsert = SortTestHelper::copyArr(arr, n);
	//int* arrBubble = SortTestHelper::copyArr(arr, n);

	SortTestHelper::testSort("selection sort", selectSort, arr, n);
	//SortTestHelper::testSort("insert sort advance", insertSortAdvance, arrInsert, n);
	//SortTestHelper::testSort("bubble sort", bubbleSort, arrBubble, n);
	SortTestHelper::testSort("shell sort", ShellSort, arrInsert, n);
	//SortTestHelper::printArray(arr, n);


	delete[] arr;

	int a = 0;
	std::cin >> a;
}