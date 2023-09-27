#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;


void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void int_swap(int *int_1, int *int_2);
void bubble_sort(int *array, size_t size);
listint_t *left_swap(listint_t *node, listint_t **list);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
int lomuto_partition(int *array, size_t size, int strt_indx, int end_indx);
void lomuto_sort(int *array, size_t size, int strt_indx, int end_indx);
void quick_sort(int *array, size_t size);

#endif /* SORT_H */
