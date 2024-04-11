#include "sort.h"
/**
 * conquer - partition and sort the partitions
 * @array: the array to sort
 * @size: the size of the array
 * @lower_bound: the lower bound of the partition (inclusive)
 * @upper_bound: the upper bound of the partition (inclusive)
 *
 * Return: the index of the new partition
 */
size_t conquer(int *array, size_t size, ssize_t lower_bound,
		ssize_t upper_bound)
{
	ssize_t current_index = lower_bound;

	while (current_index < upper_bound)
	{
		if (array[current_index] < array[upper_bound])
		{
			if (lower_bound != current_index)
			{
				array[lower_bound] ^= array[current_index];
				array[current_index] ^= array[lower_bound];
				array[lower_bound] ^= array[current_index];
				print_array(array, size);
			}
			lower_bound += 1;
		}
		current_index += 1;
	}
	if (array[lower_bound] != array[upper_bound])
	{
		array[lower_bound] ^= array[upper_bound];
		array[upper_bound] ^= array[lower_bound];
		array[lower_bound] ^= array[upper_bound];
		print_array(array, size);
	}
	return (lower_bound);
}

/**
 * divide - recursively partition the array
 * @array: the array to sort
 * @size: the size of the array
 * @lower_bound: the lower bound of the partition (inclusive)
 * @upper_bound: the upper bound of the partition (inclusive)
 */
void divide(int *array, size_t size, ssize_t lower_bound, ssize_t upper_bound)
{
	ssize_t partition_index;

	if (lower_bound < upper_bound)
	{
		partition_index = conquer(array, size, lower_bound, upper_bound);
		divide(array, size, lower_bound, partition_index - 1);
		divide(array, size, partition_index + 1, upper_bound);
	}
}

/**
 * quick_sort - perform the quick sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array && size)
		divide(array, size, 0, size - 1);
}