# include "deck.h"

/**
 * _strncmp - Compares two strings.
 * @str1: The first string to be compared.
 * @str2: The second string to be compared.
 *
 * Return: + if str1 > str2, 0 if str1 == str2, - if str1 < str2
 */
int _strncmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}

/**
 * compare_cards - Comparison function for qsort
 * @a: Pointer to the first deck_node_t pointer
 * @b: Pointer to the second deck_node_t pointer
 *
 * Return: -1 if a < b, 1 if a > b, 0 if they are equal.
 */
int compare_cards(const void *a, const void *b)
{
    const deck_node_t *node_a = *(const deck_node_t **)a;
    const deck_node_t *node_b = *(const deck_node_t **)b;
    
    if (node_a->card->kind < node_b->card->kind)
        return -1;
    
    else if (node_a->card->kind > node_b->card->kind)
        return 1;
    else
    {
        return _strncmp(node_a->card->value, node_b->card->value);
    }
}


/**
 * sort_deck - Sort a deck of cards in ascending order
 * @deck: Double pointer to the head of the deck
 *
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *nodes[52];
    deck_node_t *current = *deck;
    int i;

    for (i = 0; i < 52; i++)
    {
        nodes[i] = current;
        current = current->next;
    }

    for (i = 0; i < 51; i++)
    {
        nodes[i]->next = nodes[i + 1];
        nodes[i + 1]->prev = nodes[i];
    }

    *deck = nodes[0];
    nodes[0]->prev = NULL;
    nodes[51]->next = NULL;
}

