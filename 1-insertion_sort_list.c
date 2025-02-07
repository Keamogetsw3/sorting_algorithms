#include "sort.h"
/**
* left_swap - Swaps a node with its previous node in a doubly linked list.
* @node: The node to be swapped with its previous node.
* @list: Pointer to the head of the doubly linked list.
*
* Return: Returns a pointer to the node that was moved.
*/
listint_t *left_swap(listint_t *node, listint_t **list)
{
listint_t *prev = node->prev;
listint_t *current = node;
if (!node || !list || !prev)
return (NULL);
prev->next = current->next;
if (current->next)
current->next->prev = prev;
current->next = prev;
current->prev = prev->prev;
prev->prev = current;
prev->prev = prev;
if (current->prev)
current->prev->next = current;
else
*list = current;
return (current);
}
/**
* insertion_sort_list - Sorts a doubly linked list of integers
* in ascending order using the Insertion Sort algorithm.
* @list: Pointer to the head of the doubly linked list to be sorted.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *swap, *prv;

	if (!list || !*list)
		return;

	current = *list;
	while ((current = current->next))
	{
		swap = current;
		while (swap->prev && swap->n < swap->prev->n)
		{
			prv = swap->prev;
			if (swap->next)
				swap->next->prev = prv;
			if (prv->prev)
				prv->prev->next = swap;
			else
				*list = swap;
			prv->next = swap->next;
			swap->prev = prv->prev;
			swap->next = prv;
			prv->prev = swap;

			print_list(*list);
		}
	}
}
