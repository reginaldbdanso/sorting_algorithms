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
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly linked list
 * Description: prints the array after every swap
 */
void insertion_sort_list(listint_t **list)
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

/**
 * NB :
 * Whenever a swappable pair is encountered, make the swap,
 * and go back to the beginning
 * 
 * Since this is a linked list the swap and has to swap nodes
 * instead of array indexes
 * 
 * How do we go back to the beginning?
 * We set the temp pointer with which we are traversing the list
 * to point to the head node
 */
