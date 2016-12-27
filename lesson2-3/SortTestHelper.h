#ifndef _SORT_TEST_HELPER_H_
#define _SORT_TEST_HELPER_H_

#include <iostream>
#include <assert.h>

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

	template<typename T>
	void printArray(T arr[], int n) {

		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;

		return;
	}
}

#endif