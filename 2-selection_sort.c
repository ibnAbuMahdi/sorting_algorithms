#include "sort.h"

/**
 * selection_sort - selection sort
 *
 * @arr: the integer array
 * @s: size of @arr
 */

void selection_sort(int *arr, size_t s)
{
	size_t i, j;
	int temp;

	if (!arr)
		return;

	if (s == 1)
	{
		print_array(arr, s);
		return;
	}

	for (i = 0; i < s; i++)
	{
		int min, pos = i;

		temp = arr[i];
		min = arr[pos];
		for (j = i ; j < s; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				pos = j;
			}
		}
		if (min < temp)
		{
			arr[i] = min;
			arr[pos] = temp;
			print_array(arr, s);
		}

	}
}
