#include "sort.h"

/**
 * partition_hoare - Hoare partition scheme for Quick Sort.
 * @array: The array to partition.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 *
 * Return: The index of the partition pivot.
 */
int partition_hoare(int *array, int low, int high)
{
    int pivot = array[high];
    int temp = array[left];
    int left = low - 1;
    int right = high + 1;

    while (1)
    {
        do
        {
            left++;
        } while (array[left] < pivot);
        do
        {
            right--;
        } while (array[right] > pivot);
        if (left >= right)
            return right;

        array[left] = array[right];
        array[right] = temp;

        print_array(array, (size_t)right + 1);
    }
}

/**
 * quick_sort_recursive - Recursive function to perform Quick Sort.
 * @array: The array to sort.
 * @low: The starting index of the subarray.
 * @high: The ending index of the subarray.
 */
void quick_sort_recursive(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot_index;
        
        pivot_index = hoare_partition(array, low, high);
        quick_sort_recursive(array, low, pivot_index);
        quick_sort_recursive(array, pivot_index + 1, high);
    }
}

/**
 * quick_sort_hoare - Sorts an array using the
 * Quick Sort algorithm with the Hoare partition scheme.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 *
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (!array || size < 2)
        return;
    quick_sort_recursive(array, 0, (int)size - 1);
}
