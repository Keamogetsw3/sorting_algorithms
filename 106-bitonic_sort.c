#include "sort.h"

/**
 * bitonic_merge - sorts and merges a sequence in 
 * ascending or descending order
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence to sort.
 * @seq_size: The size of the sequence to sort.
 * @sort_dir: The direction to sort in (UP or DOWN).
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq_size,
                   char sort_dir)
{
    size_t index; 
    size_t half_seq;

    half_seq = seq_size / 2;

    if (seq_size > 1)
    {
        for (index = start; index < start + half_seq; index++)
        {
            if ((sort_dir == UP && array[index] > array[index + half_seq]) ||
                (sort_dir == DOWN && array[index] < array[index + half_seq]))
            {
                int_swap(array + index, array + index + half_seq);
            }
        }
        bitonic_merge(array, size, start, half_seq, sort_dir);
        bitonic_merge(array, size, start + half_seq, half_seq, sort_dir);
    }
}

/**
 * bitonic_con - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq_size: The size of a block of the building bitonic sequence.
 * @sort_dir: The direction to sort the bitonic sequence block in (UP or DOWN).
 */
void bitonic_con(int *array, size_t size, size_t start, size_t seq_size,
                 char sort_dir)
{
    size_t half_seq = seq_size / 2;
    char *dir_string = (sort_dir == UP) ? "UP" : "DOWN";

    if (seq_size > 1)
    {
        printf("Merging [%lu/%lu] (%s):\n", seq_size, size, dir_string);
        print_array(array + start, seq_size);

        bitonic_con(array, size, start, half_seq, UP);
        bitonic_con(array, size, start + half_seq, half_seq, DOWN);
        bitonic_merge(array, size, start, seq_size, sort_dir);

        printf("Result [%lu/%lu] (%s):\n", seq_size, size, dir_string);
        print_array(array + start, seq_size);
    }
}

/**
 * bitonic_sort - Sort an array of integers in ascending order.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_con(array, size, 0, size, UP);
}
