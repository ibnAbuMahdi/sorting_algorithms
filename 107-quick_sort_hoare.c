#include "sort.h"
#include <stdlib.h>


/**
 * quick_sort_hoare - quick sort the array @arr recursively
 *
 * @arr: the array to sort
 * @s: the size of @arr
 */

void quick_sort_hoare(int *arr, size_t s)
{
	if(!arr)
		return;
	if (s < 2)
	{
		print_array(arr, s);
		return;
	}

	quicksort_hoare(arr, 0, (int) (s - 1), (int) s);
}

/**
 * quicksort_hoare - quick sort the array @arr recursively
 *
 * @arr: the array to sort
 * @lo: the lower bound
 * @hi: the higher index
 * @s: the size of the array @arr
 */

void quicksort_hoare(int *arr, int lo, int hi, int s)
{
	int p;

	if (lo >= hi || lo < 0 || hi < 0)
		return;

	p = partition_hoare(arr, lo, hi, s);
	quicksort_hoare(arr, lo, p, s);
	quicksort_hoare(arr, p + 1, hi, s);

}

/**
 * partition_hoare - partitions the array @arr
 *
 * @arr: the array to partition
 * @lo: the lower bound
 * @hi: the higher index
 * @s: the size of the array @arr
 * Return: the index of the pivot of the partition
 */

int partition_hoare(int *arr, int lo, int hi, int s)
{
	int i, j = hi + 1;
	int pivot = arr[hi];

	for (i = lo; i < j;)
	{
		while (arr[i] <= pivot)
			i++;
		while (arr[j] > pivot)
			j--;

		if (i < j)
		{
			swap((arr + i), (arr + j));
			if (i != j)
				print_array(arr, s);
		}
	}
	swap((arr + i), (arr + hi));
	if (i != hi)
		print_array(arr, s);
	return (i);
}

/**
 * swap - swaps two elements in an array
 * @a: first element
 * @b: second element
 */

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

