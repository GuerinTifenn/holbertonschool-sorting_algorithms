#include "sort.h"
/**
 * insertion_sort_list - that sorts a doubly linked list of integers
 * description: sorts a doubly linked list in ascending order
 * using the Insertion sort algorithm
 *
 * @list: head of double linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (!list)
		return;

	for (current = *list; current; current = current->next)
	{
		while (current->next && (current->next->n < current->n))
		{
			tmp = current->next;
			current->next = tmp->next;
			tmp->prev = current->prev;

			if (current->prev)
				current->prev->next = tmp;

			if (tmp->next)
				tmp->next->prev = current;

			current->prev = tmp;
			tmp->next = current;

			if (tmp->prev)
				current = tmp->prev;
			else
				*list = tmp;

			print_list(*list);
		}
	}
}
