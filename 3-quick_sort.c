#include "sort.h"

/**
 * lomuto_partition - Partitions a subset of an integer array using
 * the Lomuto partition scheme with the last element as the pivot.
 * @array: The integer array.
 * @size: The size of the array.
 * @strt_indx: The starting index of the subset to partition.
 * @end_indx: The ending index of the subset to partition.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int strt_indx, int end_indx)
{
    if (array == NULL || size < 2 || strt_indx < 0 || end_indx < 0 || strt_indx >= size || end_indx >= size)
        return -1;

    int *pivot_element;
    int part_indx;
    int i;

    pivot_element = array + end_indx;
    for (part_indx = i = strt_indx; i < end_indx; i++)
    {
        if (array[i] < *pivot_element)
        {
            if (part_indx < i)
            {
                int_swap(array + i, array + part_indx);
            }
            part_indx++;
        }
    }
    if (array[part_indx] > *pivot_element)
    {
        int_swap(array + part_indx, pivot_element);
        // You should have a print_array function here to print the array
    }
    return (part_indx);
}

/**
 * lomuto_sort - Recursively sorts an integer array using the
 * quicksort algorithm with the Lomuto partition scheme.
 * @array: An integer array to sort.
 * @size: The size of the array.
 * @strt_indx: The starting index of the array partition to order.
 * @end_indx: The ending index of the array partition to order.
 */
void lomuto_sort(int *array, size_t size, int strt_indx, int end_indx)
{
    if (strt_indx < end_indx)
    {
        int part_indx = lomuto_partition(array, size, strt_indx, end_indx);
        lomuto_sort(array, size, strt_indx, part_indx - 1);
        lomuto_sort(array, size, part_indx + 1, end_indx);
    }
}

/**
 * quick_sort - Sorts an integer array in ascending order
 * using the quicksort algorithm with the Lomuto partition scheme.
 * @array: An integer array.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    lomuto_sort(array, size, 0, size - 1);
}
