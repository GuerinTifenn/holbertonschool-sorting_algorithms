#include "sort.h"

/**
 * swap - Swaps two elements of an array
 * @a: Integer a
 * @b: Integer b
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Doubly linked list node
 * @array: Array of integers to print
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		/*Last i elements are already in place*/
		for (j = 0; j < size - i - 1; j++)
		{
			/*Swap if the element found is greater than the next element*/
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
