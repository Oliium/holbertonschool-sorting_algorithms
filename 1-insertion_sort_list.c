#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Pointer to the head pointer of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *prev_node, *prev_prev, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		next = current->next;
		while (current->prev && current->n < current->prev->n)
		{
			prev_node = current->prev;
			prev_prev = prev_node->prev;
			next_node = current->next;

			if (prev_prev)
				prev_prev->next = current;
			else
				*list = current;

			current->prev = prev_prev;
			current->next = prev_node;
			prev_node->prev = current;
			prev_node->next = next_node;

			if (next_node)
				next_node->prev = prev_node;

			print_list(*list);
		}
		current = next;
	}
}
