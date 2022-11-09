#include "sort.h"

/**
 * selection_sort - uses the selection sort algorithm on an array
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: None
*/

void selection_sort(int *array, size_t size)
{

	size_t n = 0, m = 0, v = 0;
	int key = 0, tmp = 0;

	if (!array || size <= 1)
		return;

	for (n = 0; n < size - 1; n++)
	{
		key = array[n];
		v = n;
		for (m = n + 1; m < size; m++)
		{
			if (array[m] < key)
			{
				key = array[m];
				v = m;
			}
		}
		if (n != v)
		{
			tmp = array[n];
			array[n] = key;
			array[v] = tmp;
			print_array(array, size);
		}
	}
}
