#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge_sort - wrapper function for merge sort function
 * @arr: the array
 * @s: the size of @arr
 */

void merge_sort(int *arr, size_t s)
{
	if (arr && s > 1)
		mergesort(arr, 0, (int) (s - 1));
	else if (arr && s == 1)
		printf("[Done]: %d\n", arr[0]);

}

/**
 * mergesort - actual merge sort function
 * @arr: the array to sort
 * @l: the lower bound
 * @r: the upper bound
 */

void mergesort(int *arr, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		if ((r - l) % 2 == 0)
		{
			mergesort(arr, l, m - 1);
			mergesort(arr, m, r);
			merge(arr, l, m - 1, r);
		}
		else
		{
			mergesort(arr, l, m);
			mergesort(arr, m + 1, r);
			merge(arr, l, m, r);
		}
	}
}

/**
 * merge - merges two sub arrays
 * @l: the left bound
 * @r: the right bound
 * @m: the middle point
 * @array: the array to sort
 */

void merge(int *array, int l, int m, int r)
{
	int i = l, j = m + 1, k = 0;
	int *sub_arr, *arr = array;

	sub_arr = malloc(sizeof(int) * (r - l + 1));
	if (!sub_arr)
		return;
	printf("Merging...\n[Left]: ");
	print_sub_array(arr, l, m);
	printf("[Right]: ");
	print_sub_array(arr, m + 1, r);
	while (i <= m && j <= r)
	{
		if (*(arr + i) <= *(arr + j))
		{
			sub_arr[k] = arr[i];
			i++;
		}
		else
		{
			sub_arr[k] = arr[j];
			j++;
		}
		k++;
	}
	while (i <= m)
	{
		sub_arr[k] = arr[i];
		i++;
		k++;
	}
	while (j <= r)
	{
		sub_arr[k] = arr[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	print_array(sub_arr, k);
	rearrange(arr, sub_arr, k, l);
	free(sub_arr);
}

/**
 * rearrange - transfer @sub_arr into @arr
 * @arr: the array to sort
 * @sub_arr: the sub array
 * @k: size of the sub array
 * @l: the offset in  @arr
 */

void rearrange(int *arr, int *sub_arr, int k, int l)
{
	int i = 0;

	while (i < k)
	{
		arr[l] = sub_arr[i];
		l++;
		i++;
	}
}
/**
 * print_sub_array - Prints a sub array of integers
 *
 * @array: The array to be printed
 * @l: left index in @array
 * @r: right index in @array
 */

void print_sub_array(const int *array, int l, int r)
{
	int i = 0;

	while (array && l <= r)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[l]);
		l++;
		++i;
	}
	printf("\n");
}
