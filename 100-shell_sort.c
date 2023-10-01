#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm with the Knuth sequence
 * @array: The array of integers to be sorted.
 * @size: The number of elements in the array.
 */
void shell_sort(int *array, size_t size)
{
    size_t gap;
    size_t inner;
    size_t outer;
    int current_element;

    if (!array || size < 2)
        return;

    gap = 1;
    while (gap < size / 3)
    {
        gap = gap * 3 + 1;
    }

    while (gap > 0)
    {
        for (outer = gap; outer < size; outer++)
        {
            current_element = array[outer];
            inner = outer;

            while (inner > gap - 1 && array[inner - gap] >= current_element)
            {
                array[inner] = array[inner - gap];
                inner = inner - gap;
            }
            array[inner] = current_element;
        }

        gap = (gap - 1) / 3;
        print_array(array, size);
    }
}
