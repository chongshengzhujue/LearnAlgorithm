#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"

//选择排序
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

//插入排序
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

//插入排序进阶
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

//冒泡排序

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

//希尔排序
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

//归并排序
template<typename T>
void mergeSort(T arr[], int n)
{
	if (n == 1)
		return;
	int num1 = n / 2;
	int num2 = n - num1;
	T* arr0 = new T[num1];
	T* arr1 = new T[num2];

	for (int f = 0; f < n; f++)
	{
		if (f < num1)
			arr0[f] = arr[f];
		else
			arr1[f - num1] = arr[f];
	}



	mergeSort(arr0, num1);
	mergeSort(arr1, num2);

	int k = -1;
	int j = 0;
	int i = 0;
	while (k < n)
	{
		k++;
		if (i == num1)
		{
			arr[k] = arr1[j];
			j++;
			continue;
		}
		if (j == num2)
		{
			arr[k] = arr0[i];
			i++;
			continue;
		}


		if (arr0[i] < arr1[j])
		{
			arr[k] = arr0[i];
			i++;
		}
		else
		{
			arr[k] = arr1[j];
			j++;
		}
	}

	delete[] arr0;
	delete[] arr1;
}

template<typename  T>
void __merge(T arr[], int l, int mid, int r)
{
	T* aux = new T[r - l + 1];
	for (int i = l; i <= r; i++)
	{
		aux[i - l] = arr[i];
	}

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++){

		if (i > mid)   { arr[k] = aux[j - l]; j++; }
		else if (j > r){ arr[k] = aux[i - l]; i++; }
		else if (aux[i - l] < aux[j - l]){ arr[k] = aux[i - l]; i++; }
		else                          { arr[k] = aux[j - l]; j++; }
	}
}

// 递归使用归并排序,对arr[l...r]的范围进行排序

template<typename T>
void __insertSortPrivate(T arr[], int l, int r)
{
	for (int i = l + 1; i <= r; i++)
	{
		int temp = arr[i];
		int j;
		for (j = i; j > l && temp < arr[j - 1]; j--)
			arr[j] = arr[j - 1];
		arr[j] = temp;
	}
}

template<typename T>
void __mergeSort(T arr[], int l, int r)
{
	if (r - l <= 20)
	{
		__insertSortPrivate(arr, l, r);
		return;
	}
	int mid = (l + r) / 2;

	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);
	if (arr[mid] > arr[mid + 1])
		__merge(arr, l, mid, r);
}

template<typename T>
void mergeSortV2(T arr[], int n)
{
	__mergeSort(arr, 0, n - 1);
	//__insertSortPrivate(arr, 0, n - 1);
}

//归并排序不使用递归的实现方法
template<typename T>
void mergeSortUpBottom(T arr[], int n)
{
	// Merge Sort Bottom Up 优化
	for (int i = 0; i < n; i += 16)
		__insertSortPrivate(arr, i, min(i + 15, n - 1));

	for (int sz = 16; sz <= n; sz += sz)
	for (int i = 0; i < n - sz; i += sz + sz)
	if (arr[i + sz - 1] > arr[i + sz])
		__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
}

//快速排序
template<typename T>
void quickSort(T arr[], int n)
{
	__quickSort(arr, 0, n - 1);
}

template<typename T>
void __quickSort(T arr[], int l, int r)
{
	if (l >= r)
		return;

	int p = __partition(arr, l, r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}

template<typename T>
int __partition(T arr[], int l, int r)
{
	T temp = arr[l];

	int j = l;
	for (int i = l + 1; i <= r; i++)
	{
		if (arr[i] < temp)
		{
			j++;
			swap(arr[j], arr[i]);
		}
	}
	swap(arr[l], arr[j]);
	return j;
}

int main()
{
	int n = 500000;
	int* arr = SortTestHelper::createIntArr(n, 10, n);
	int* arrInsert = SortTestHelper::copyArr(arr, n);
	//int* arrBubble = SortTestHelper::copyArr(arr, n);

	//SortTestHelper::testSort("selection sort", selectSort, arr, n);
	//SortTestHelper::testSort("insert sort advance", insertSortAdvance, arrInsert, n);
	//SortTestHelper::testSort("bubble sort", bubbleSort, arrBubble, n);
	//SortTestHelper::testSort("shell sort", ShellSort, arrInsert, n);
	//SortTestHelper::printArray(arr, n);
	//SortTestHelper::testSort("merge sort", mergeSort, arrInsert, n);
	SortTestHelper::testSort("merge sort up bottom", mergeSortUpBottom, arrInsert, n);
	//SortTestHelper::testSort("merge sort v2", mergeSortV2, arr, n);
	SortTestHelper::testSort("quick sort", quickSort, arr, n);
	//SortTestHelper::printArray(arrInsert, n);

	delete[] arr;
	delete[] arrInsert;

	int a = 0;
	std::cin >> a;
}