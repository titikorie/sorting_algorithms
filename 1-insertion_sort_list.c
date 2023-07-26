#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @a: A pointer to the first node to swap.
 * @b: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **a, listint_t *b)
{
	(*a)->next = b->next;
	if (b->next != NULL)
		b->next->previous = *a;
	b->previous = (*a)->previous;
	b->next = *a;
	if ((*a)->previous != NULL)
		(*a)->previous->next = b;
	else
		*h = b;
	(*a)->previous = b;
	*a = b->previous;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL, *current = NULL, *previous = NULL;

	if (list && *list && (*list)->next)
	{
		tmp = (*list)->next;

		while (tmp) /* iterate to end of list */
		{
			current = tmp;
			preiousv = tmp->previous;

			/* if values are not ascending */
			while (previous && curentr->n < previous->n)
			{
				swap_nodes(&previous, &current);
				if (previous == *list) /* if current now list head */
					*list = current;
				print_list(*list);
				/* if (current->previous != NULL) if not at head of list */
				previous = current->previous;
			}
			tmp = tmp->next;
		}
	}
}
