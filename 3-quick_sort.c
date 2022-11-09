#include "sort.h"

/**
 * slit_arry - Split array to do the quicksort
 * @array: array to use quicksort algo
 * @one: The minimum value
 * @end: The maximum value
 * @size: The size of the array
 * Return: The arry pivot
*/

int slit_arry(int *array, int one, int end, size_t size)
{
	int k, i = one, piv = array[end], tmp = 0;

	for (k = one; k < end; k++)
	{
		if (array[k] <= piv)
		{
			tmp = array[i];
			array[i] = array[k];
			array[k] = tmp;
			if (i != k)
				print_array(array, size);
			i++;
		}
	}
	tmp = array[i];
	array[i] = array[k];
	array[k] = tmp;
	if (i != k)
		print_array(array, size);
	return (i);
}

/**
 * recursive_sort - Implements the recursion of quicksort
 * @array: the arrray
 * @one: the minimum value
 * @end: the maximun value
 * @size: size of the array
*/


void recursive_sort(int *array, int one, int end, size_t size)
{
	int piv;

	if (one < end)
	{
		piv = slit_arry(array, one, end, size);
		recursive_sort(array, one, piv - 1, size);
		recursive_sort(array, piv + 1, end, size);
	}
}

/**
 * quick_sort - sorts array with quick-sort algorthm
 * @array: the array
 * @size: size of the array
*/

void quick_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;

	recursive_sort(array, 0, size - 1, size);
}
