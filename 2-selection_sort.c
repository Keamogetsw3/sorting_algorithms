# include "sort.h"/*** selection_sort - Sorts an array of integers in ascending order*                  using the selection sort algorithm.* @ array: The array to be sorted.* @ size: The number of elements in the array.*/void selection_sort(int * array, size_t size){size_t i, j, posif (array == NULL | | size == 0)returnfor (i=0i < size - 1i++){pos = ifor (j=i + 1j < sizej++){if (array[j] < array[pos])pos = j}if (pos != i){int temp = array[i]array[i] = array[pos]array[pos] = tempprint_array(array, size)}}}