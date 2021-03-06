#ifndef _SORT_TEST_HELPER_H_
#define _SORT_TEST_HELPER_H_

#include <iostream>
#include <assert.h>
#include <ctime>
#include <algorithm>

using namespace std;

namespace SortTestHelper {
	int* createIntArr(int n, int rangeL, int rangeR)
	{
		assert(rangeL <= rangeR);

		int* arr = new int[n];
		srand(NULL);
		for (size_t i = 0; i < n; i++)
		{
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}

		return arr;
	}

	int* createNearlyIntArr(int n, int swapNum)
	{
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = i;

		for (int i = 0; i < swapNum; i++)
		{
			int posX = rand() % n;
			int posY = rand() % n;

			swap(arr[posX], arr[posY]);
		}

		return arr;
	}

	template<typename T>
	void printArray(T arr[], int n) {

		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;

		return;
	}

	template<typename T>
	bool isSorted(T arr[], int n) {

		for (int i = 0; i < n - 1; i++)
		if (arr[i] > arr[i + 1])
			return false;

		return true;
	}

	template<typename T>
	void testSort(const string &sortName, void(*sort)(T[], int), T arr[], int n)
	{
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();

		assert(isSorted(arr, n));
		std::cout << sortName.c_str() << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << std::endl;

		return;
	}

	template<typename T>
	T* copyArr(T* arr, int n)
	{
		T* newArr = new T[n];
		for (int i = 0; i < n; i++)
		{
			newArr[i] = arr[i];
		}
		return newArr;
	}
}

#endif