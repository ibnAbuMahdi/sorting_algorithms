#include "sort.h"
#include <stdlib.h>


/**
 * quick_sort - quick sort the array @arr recursively
 *
 * @arr: the array to sort
 * @s: the size of @arr
 */

void quick_sort(int *arr, size_t s)
{

	if (!arr || s == 1 || s == 0)
	{
		print_array(arr, s);
		return;
	}

	quicksort(arr, 0, (int) (s - 1), (int) s);
}

/**
 * quicksort - quick sort the array @arr recursively
 *
 * @arr: the array to sort
 * @lo: the lower bound
 * @hi: the higher index
 * @s: the size of the array @arr
 */

void quicksort(int *arr, int lo, int hi, int s)
{
	int p;

	if (lo >= hi || lo < 0)
		return;

	p = partition(arr, lo, hi, s);
	quicksort(arr, lo, p - 1, s);
	quicksort(arr, p + 1, hi, s);

}

/**
 * partition - partitions the array @arr
 *
 * @arr: the array to partition
 * @lo: the lower bound
 * @hi: the higher index
 * @s: the size of the array @arr
 * Return: the index of the pivot of the partition
 */

int partition(int *arr, int lo, int hi, int s)
{
	int i, j;
	int pivot = arr[hi];

	i = lo - 1;
	for (j = lo; j < hi; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap((arr + i), (arr + j));
			if (i != j)
				print_array(arr, s);
		}
	}
	i++;
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

