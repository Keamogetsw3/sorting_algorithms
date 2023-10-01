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

/* functions prototype */
void print_array(const int *array, size_t size);

void print_list(const listint_t *list);

void int_swap(int *int1, int *int2);

void bubble_sort(int *array, size_t size);

listint_t *left_swap(listint_t *node, listint_t **list);

void insertion_sort_list(listint_t **list);

void selection_sort(int *array, size_t size);

void quick_sort(int *array, size_t size);

int partition_hoare(int *array, int low, int high);

void quick_sort_recursive(int *array, int low, int high);

void quick_sort_hoare(int *array, size_t size);

void bitonic_merge(int *array, size_t size, size_t start, size_t seq_size,
                   char sort_dir);

void bitonic_con(int *array, size_t size, size_t start, size_t seq_size,
                 char sort_dir);

void bitonic_sort(int *array, size_t size);

int get_max(int *array, int size);

void radix_counting_sort(int *array, size_t size, int sig, int *buffer);

void radix_sort(int *array, size_t size);

void lomuto_sort(int *array, size_t size, ssize_t low, ssize_t high);

size_t lomuto_partition(int *array, size_t size, ssize_t low, ssize_t high);

#endif /* SORT_H */
