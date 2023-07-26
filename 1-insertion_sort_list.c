#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order
 * using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	sorted = *list;
	/* Initially, the sorted part of the list contains only the first node */
	current = sorted->next; /* Start sorting from the second node */

	while (current != NULL)
	{
		temp = current;
		current = current->next;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			/* Swap the nodes to sort the list */
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;

			/* Update the head of the list if needed */
			if (temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;

			/* Print the list after each swap */
			print_list(*list);
		}
	}
}
