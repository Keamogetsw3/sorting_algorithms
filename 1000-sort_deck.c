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

/*
 * get_value - Calculate the numeric value of a playing card.
 * @node: Pointer to a card node in a deck.
 *
 * Return: An integer between 1 and 52,
 * representing the card's value in the deck.
 */
int get_value(deck_node_t *node)
{
    char *card_values[13] = {"Ace", "2", "3", "4", "5", "6",
        "7", "8", "9", "10", "Jack", "Queen", "King"};

    char *card_kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
    int kind_offset = 0;
    int val = 0;
    int i = 0;
    int card_value;


    for (i = 0; i < 13; i++)
    {
        if (_strncmp(node->card->value, card_values[i]) == 0)
            val = i + 1;
    }

    for (i = 0; i < 4; i++)
    {
        if (_strncmp(card_kinds[node->card->kind], card_kinds[i]) == 0)
            kind_offset += (13 * (i + 1));
    }
    
    card_value = val + kind_offset;

    return (card_value);
}
