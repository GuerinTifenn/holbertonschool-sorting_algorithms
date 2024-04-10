#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: Double pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;

    while (current != NULL)
    {
        listint_t *key_node = current;
        listint_t *insertion_point = current->prev;

        while (insertion_point != NULL && insertion_point->n > key_node->n)
        {
            if (insertion_point->prev != NULL)
                insertion_point->prev->next = key_node;
            if (key_node->next != NULL)
                key_node->next->prev = insertion_point;

            insertion_point->next = key_node->next;
            key_node->prev = insertion_point->prev;
            key_node->next = insertion_point;
            insertion_point->prev = key_node;

            if (key_node->prev == NULL)
                *list = key_node;

            insertion_point = key_node->prev;

            print_list(*list);
        }

        current = current->next;
    }
}
