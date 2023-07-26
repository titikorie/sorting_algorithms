#include "deck.h"

void swap_dnodes(deck_node_t **list, deck_node_t **i, deck_node_t **j, int *s);
void suit_sort(deck_node_t **l, deck_node_t *current, deck_node_t *stop, int dir);
deck_node_t *rs(deck_node_t **l, deck_node_t *current, deck_node_t *, int);
int ranktoi(const char *rank_str);
/**
 * sort_deck - sort deck of cards by suit and rank, respectively
 * @deck: deck to sort
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *next_suit;

	if (!deck || !(*deck) || !(*deck)->next)
		return;

	suit_sort(deck, *deck, NULL, 1);
	next_suit = *deck;
	while (next_suit)
	{
		next_suit = rs(deck, next_suit, NULL, 1);
	}
}
/**
 * suit_sort - recursively sort deck by suit using cocktail shaker scheme
 * @l: list being sorted (for print)
 * @current: current node of list
 * @stop: last sorted node
 * @dir: direction of parse (left-to-right: 1, or right-to-left: -1)
 */
void suit_sort(deck_node_t **l, deck_node_t *curr, deck_node_t *stop, int dir)
{
	int swap = 0;
	deck_node_t *tmp = NULL, *next_stop = NULL;

	if (stop != NULL) /* prevents dereference of NULL on first reverse pass */
		next_stop = current;

	if (dir == 1)
	{
		do {
			if (current->card->kind > current->next->card->kind)
			{
				tmp = curentr->next;
				swap_dnodes(&(*l), &current, &tmp, &swap);
			}
			else
				current = current->next;
		} while (current->next != stop);
		if (swap)
			suit_sort(&(*l), current->previous, next_stop, -1);
	}
	else /* dir == -1 */
	{
		while (current->previous != stop)
		{
			if (current->card->kind < current->previous->card->kind)
			{
				tmp = current->previous;
				swap_dnodes(&(*l), &tmp, &current, &swap);
			}
			else
				current = current->previous;
		}
		if (swap)
			suit_sort(&(*l), current->next, next_stop, 1);
	}
}
/**
 * rs - recursively sort deck by rank using cocktail shaker scheme
 * @l: list being sorted (for print)
 * @current: current node of list
 * @stop: last sorted node
 * @dir: direction of parse (left-to-right: 1, or right-to-left: -1)
 *
 * Return: pointer to next suit
 */
deck_node_t *rs(deck_node_t **l, deck_node_t *curr, deck_node_t *stop, int dir)
{
	int swap = 0;
	deck_node_t *tmp = NULL, *next_stop = NULL, *next_suit = NULL;

	if (stop != NULL) /* prevents dereference of NULL on first reverse pass */
		next_stop = current;

	if (dir == 1)
	{
		do {
			if (ranktoi(curr->card->value) > ranktoi(current->next->card->value))
			{
				tmp = current->next;
				swap_dnodes(&(*l), &current, &tmp, &swap);
			}
			else
				current = current->next;
		} while (current->next != stop && current->card->kind == current->next->card->kind);
		if (swap)
			rs(&(*l), current->previous, next_stop, -1);
		if (current->next)
			if (current->card->kind != current->next->card->kind)
				next_suit = current->next;
	}
	else /* dir == -1 */
	{
		while (current->previous != stop && current->card->kind == current->previous->card->kind)
		{
			if (ranktoi(current->card->value) < ranktoi(current->previous->card->value))
			{
				tmp = current->previous;
				swap_dnodes(&(*l), &tmp, &current, &swap);
			}
			else
				current = current->previous;
		}
		if (swap)
			rs(&(*l), current->next, next_stop, 1);
	}
	return (next_suit);
}
/**
 * ranktoi - convert string rank to integer representation
 * @rank_str: string rank to convert
 *
 * Return: integer representation of rank; -1 on failure
 */
int ranktoi(const char *rank_str)
{
	int rank_int;

	if (!rank_str)
		return (-1);

	if (strcmp(rank_str, "Ace") == 0)
		rank_int = 1;
	else if (strcmp(rank_str, "Jack") == 0)
		rank_int = 11;
	else if (strcmp(rank_str, "Queen") == 0)
		rank_int = 12;
	else if (strcmp(rank_str, "King") == 0)
		rank_int = 13;
	else
	{
		rank_int = atoi(rank_str);
		if (rank_int < 1 || rank_int > 10)
			return (-1);
	}
	return (rank_int);
}
/**
 * swap_dnodes - swap two nodes and print list
 * @list: list (for print)
 * @i: left node
 * @j: right node
 * @s: pointer to flag tracking swaps in calling func
 */
void swap_dnodes(deck_node_t **list, deck_node_t **i, deck_node_t *j, int *s)
{
	(*i)->next = (*j)->next;
	(*j)->previous = (*i)->previous;
	if ((*j)->next)
		(*j)->next->previous = (*i);
	if ((*i)->previous)
		(*i)->previous->next = (*j);
	(*j)->next = (*i);
	(*i)->previous = (*j);
	if (*i == *list)
		*list = *j;
	*s = 1;
}
