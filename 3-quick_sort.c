#include "sort.h"

/**
 * swap_print - Swaps two integer values.
 * @array: The integer array to be sorted.
 * @size: The size of the array.
 * @a: Pointer to the first value to be swapped.
 * @b: Pointer to the second value to be swapped.
 *
 * Description:
 * This function swaps the values pointed to by 'a' and 'b' in the 'array'.
 * It also prints the array after the swap.
 */
void swap_print(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_partition - Partitions the array using the Lomuto partition scheme.
 * @array: The integer array to sort.
 * @size: The size of the array.
 * @low: The low index of the sorting range.
 * @high: The high index of the sorting range.
 *
 * Description:
 * This function partitions the 'array' using the Lomuto partitioning scheme
 * with the 'pivot' as the last element. It rearranges elements so that
 * elements less than the pivot come before it, and elements greater than
 * the pivot come after it.
 *
 * Return: The index of the pivot after partitioning.
 */
size_t lomuto_partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int i, k, pivot;

	pivot = array[high];
	for (i = k = low; k < high; k++)
	{
		if (array[k] < pivot)
			swap_print(array, size, &array[k], &array[i++]);
	}
	swap_print(array, size, &array[i], &array[high]);

	return (i);
}

/**
 * lomuto_sort - Sorts an integer array using the quicksort algorithm.
 * @array: The integer array to sort.
 * @size: The size of the array.
 * @low: The low index of the sorting range.
 * @high: The high index of the sorting range.
 */
void lomuto_sort(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t pivot_index;

		pivot_index = lomuto_partition(array, size, low, high);
		lomuto_sort(array, size, low, pivot_index - 1);
		lomuto_sort(array, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort - Initiates the quicksort algorithm.
 * @array: The integer array to sort.
 * @size: The size of the array.
 *
 * Description:
 * This function initiates the quicksort algorithm by calling the
 * 'lomuto_sort' function with the appropriate parameters.
 * It performs a check for NULL array or zero size.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
