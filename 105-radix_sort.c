#include "sort.h"

/**
 * get_max - Find the maximum value in an array of integers.
 * @array: Array of integers
 * @size: Size of the array
 *
 * Returns: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
    int int_max;
    int i;

    int_max = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > int_max)
            int_max = array[i];
    }

    return (int_max);
}

/**
 * radix_counting_sort - Sort the significant digits of an array
 * of integers in ascending order using the counting sort algorithm.
 * @array: Array of integers
 * @size: Size of the array
 * @sig: Significant digit to sort on
 * @buffer: Buffer to store the sorted array
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buffer)
{
    int count[10] = {0};
    size_t i;

    for (i = 0; i < size; i++)
        count[(array[i] / sig) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = size - 1; (int)i >= 0; i--)
    {
        buffer[count[(array[i] / sig) % 10] - 1] = array[i];
        count[(array[i] / sig) % 10]--;
    }
    for (i = 0; i < size; i++)
        array[i] = buffer[i];
}

/**
 * radix_sort - Sort an array of integers in ascending order
 *              using the radix sort algorithm.
 * @array: Array of integers
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    int int_max;
    int sig;
    int *buffer;

    if (array == NULL || size < 2)
        return;

    buffer = malloc(sizeof(int) * size);

    if (buffer == NULL)
        return;

    int_max = get_max(array, size);

    for (sig = 1; int_max / sig > 0; sig *= 10)
    {
        radix_counting_sort(array, size, sig, buffer);
    }
    free(buffer);
}
