#include "sort.h"

/**
 * swap - swaps positions of two numbers
 * @a: pointer to first number to be swapped
 * @b: pointer to second number to be swapped
*/
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sort an array of integers in an ascending order
 * @array: array of integers to be sorted
 * @size: size of the array to be sorted
 * Description: prints the array after every swap
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		if (min_idx != i)
		{
			swap(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}
