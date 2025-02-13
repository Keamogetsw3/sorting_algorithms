#include "sort.h"
/**
* int_swap - Swap two integers in an array.
* @int1: The first integer to swap.
* @int2: The second integer to swap.
*
*/
void int_swap(int *int1, int *int2)
{
int temp;
temp = *int1;
*int1 = *int2;
*int2 = temp;
}
/**
* bubble_sort - Sorts an array of integers in ascending order
* using the Bubble sort algorithm.
* @array: Pointer to the array to be sorted.
* @size: Size of the array.
*
*/
void bubble_sort(int *array, size_t size)
{
size_t i;
size_t j;
bool swapped;
i = 0;
j = 0;
if (array == NULL || size < 2)
return;
for (i = 0; i < (size - 1); i++)
{
swapped = false;
for (j = 0; j < (size - i - 1); j++)
{
if (array[j] > array[j + 1])
{
int_swap(&array[j], &array[j + 1]);
swapped = true;
print_array(array, size);
}
}
if (swapped == false)
break;
}
}
