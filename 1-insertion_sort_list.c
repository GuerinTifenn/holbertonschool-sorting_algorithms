#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current;
    listint_t *insertion_prev_point;
     listint_t *insertion_next_point;
    listint_t *key_node;

    if (!list)
        return;

    for (current = *list; current; current = current->next)
    {
        insertion_prev_point = current->prev;
        insertion_next_point = current->next;

       while (insertion_next_point && (insertion_next_point->n < current->n))
        {
            key_node = current->next;
			insertion_next_point = key_node->next;
			key_node->prev = insertion_prev_point;

            if (insertion_prev_point)
                insertion_prev_point->next = key_node;
            
             if (insertion_next_point)
                insertion_prev_point->prev = key_node;

            insertion_prev_point = key_node;
            insertion_next_point =  current;

            if (key_node->prev)
                current = key_node->prev;
             else
                *list = key_node;

            print_list(*list);
        }
    }
}