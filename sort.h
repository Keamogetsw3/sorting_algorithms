#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>

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

/* Prototypes for print_array and print_list functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Define any other function prototypes*/
void int_swap(int *int_1, int *int_2);
void bubble_sort(int *array, size_t size);
listint_t *left_swap(listint_t *node, listint_t **list);
void insertion_sort_list(listint_t **list);


#endif /* SORT_H */
