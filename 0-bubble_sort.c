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
 * bubble_sort - sort an array of integers in an ascending order
 * @array: array of integers to be sorted
 * @size: size of the array to be sorted
 * Description: prints the array after every swap
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
