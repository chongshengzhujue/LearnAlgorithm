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
		for (j = i; j > 0 && temp < arr[j-1]; j--)
			arr[j] = arr[j - 1];
		arr[j] = temp;
	}
}

int main()
{
	int n = 10000;
	int* arr = SortTestHelper::createNearlyIntArr(n, 1000);
	int* arrInsert = SortTestHelper::copyArr(arr, n);

	SortTestHelper::testSort("selection sort", selectSort, arr, n);
	SortTestHelper::testSort("insert sort advance", insertSortAdvance, arrInsert, n);
	//SortTestHelper::printArray(arr, n);


	delete[] arr;

	int a = 0;
	std::cin >> a;
}