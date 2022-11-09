#include "sort.h"

/**
 * swap - swap the values
 * @a: value a
 * @b: value b
 */
void swap(int *a, int *b)
{
	int temp = *b;

	*b = *a;
	*a = temp;
}
/**
 * bubble_sort -> sort the arrays using bubble algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t n, m, k;

	if (size >= 2)
	{
		for (n = 0; n < size - 1; n++)
		{
			for (m = 0; m < size - 1 - n; m++)
			{
				if (array[m] > array[m + 1])
				{
					swap(&array[m], &array[m + 1]);
					for (k = 0; k < size; k++)
					{
					printf("%d", array[k]);
					if (k != size - 1)
					{
						putchar(',');
						putchar(' ');
					}
					}
					putchar('\n');
				}
			}
		}
	}
}
