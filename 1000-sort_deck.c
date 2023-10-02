/**
 * custom_strncmp - Compare two strings.
 * @str1: First string.
 * @str2: Second string.
 * Return: Positive byte if str1 > str2, 0 if str1 == str2, Negative byte if str1 < str2.
 */
int custom_strncmp(const char *str1, const char *str2)
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
 * get_value - Get the value of a card.
 * @card: Pointer to a card in a linked list.
 * Return: The corresponding value as a character.
 */
char get_value(deck_node_t *card)
{
    if (custom_strncmp(card->card->value, "Ace") == 0)
        return (0);
    if (custom_strncmp(card->card->value, "1") == 0)
        return (1);
    if (custom_strncmp(card->card->value, "2") == 0)
        return (2);
    if (custom_strncmp(card->card->value, "3") == 0)
        return (3);
    if (custom_strncmp(card->card->value, "4") == 0)
        return (4);
    if (custom_strncmp(card->card->value, "5") == 0)
        return (5);
    if (custom_strncmp(card->card->value, "6") == 0)
        return (6);
    if (custom_strncmp(card->card->value, "7") == 0)
        return (7);
    if (custom_strncmp(card->card->value, "8") == 0)
        return (8);
    if (custom_strncmp(card->card->value, "9") == 0)
        return (9);
    if (custom_strncmp(card->card->value, "10") == 0)
        return (10);
    if (custom_strncmp(card->card->value, "Jack") == 0)
        return (11);
    if (custom_strncmp(card->card->value, "Queen") == 0)
        return (12);
    return (13);
}

/**
 * sort_kind - Sort a deck of cards by kind.
 * @deck: Pointer to the head of a double-linked list.
 * Return: void
 */
void sort_kind(deck_node_t **deck)
{
    deck_node_t *current;
    deck_node_t *insertion;
    deck_node_t *temp;

    for (current = (*deck)->next; current != NULL; current = temp)
    {
        temp = current->next;
        insertion = current->prev;

        while (insertion != NULL && insertion->card->kind > current->card->kind)
        {
            insertion->next = current->next;
            if (current->next != NULL)
                current->next->prev = insertion;
            current->prev = insertion->prev;
            current->next = insertion;

            if (insertion->prev != NULL)
                insertion->prev->next = current;
            else
                *deck = current;

            insertion->prev = current;
            insertion = current->prev;
        }
    }
}

/**
 * value_sort - Sort a deck of cards by value.
 * @deck: Pointer to the head of a double-linked list.
 * Return: void
 */
void value_sort(deck_node_t **deck)
{
    deck_node_t *current;
    deck_node_t *insertion;
    deck_node_t *temp;

    for (current = (*deck)->next; current != NULL; current = temp)
    {
        temp = current->next;
        insertion = current->prev;

        while (insertion != NULL &&
               insertion->card->kind == current->card->kind &&
               get_value(insertion) > get_value(current))
        {
            insertion->next = current->next;
            if (current->next != NULL)
                current->next->prev = insertion;
            current->prev = insertion->prev;
            current->next = insertion;

            if (insertion->prev != NULL)
                insertion->prev->next = current;
            else
                *deck = current;

            insertion->prev = current;
            insertion = current->prev;
        }
    }
}

/**
 * sort_deck - Sort a deck of cards from Ace to King and from Spades to Diamonds.
 * @deck: Pointer to the head of a double-linked list.
 * 
 * Return: Nothing
 */
void sort_deck(deck_node_t **deck)
{
    if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
        return;

    sort_kind(deck);
    value_sort(deck);
}
