#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *asorted, *current_node, *temp_ptr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	asorted = *list;
	/* Initially, the sorted part of the list contains only the first node */
	current_node = asorted->next;
	/* Start sorting from the second node */

	while (current_node != NULL)
	{
		temp_ptr = current_node;
		current_node = current_node->next;

		while (temp_ptr->prev != NULL && temp_ptr->n < temp_ptr->prev->n)
		{
			/* Swap the nodes to sort the list */
			if (temp_ptr->next != NULL)
				temp_ptr->next->prev = temp_ptr->prev;

			temp_ptr->prev->next = temp_ptr->next;
			temp_ptr->next = temp_ptr->prev;
			temp_ptr->prev = temp_ptr->prev->prev;
			temp_ptr->next->prev = temp_ptr;

			/* Update the head of the list if needed */
			if (temp_ptr->prev == NULL)
				*list = temp_ptr;
			else
				temp_ptr->prev->next = temp_ptr;

			/* Print the list after each swap */
			print_list(*list);
		}
	}
}
