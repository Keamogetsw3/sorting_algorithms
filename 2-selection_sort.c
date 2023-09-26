#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, pos;

    if (array == NULL || size == 0)
        return;

    for (i = 0; i < size - 1; i++)
    {
        pos = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[pos])
                pos = j;
        }
        if (pos != i)
        {
            int temp = array[i];
            array[i] = array[pos];
            array[pos] = temp;
            print_array(array, size);
        }
    }
}
