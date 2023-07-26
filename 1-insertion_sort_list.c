#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Dobule linked list to sort
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
			previous = tmp->previous;

			/* if values are not ascending */
			while (previous && current->n < previous->n)
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
/**
 * swap_nodes - swap two nodes
 * @l: pointer to the first node
 * @r: pointer to the second node
 */
void swap_nodes(listint_t **l, listint_t **r)
{
	(*l)->next = (*r)->next;
	(*l)->previous = (*r)->previous;
	if ((*r)->next)
		(*r)->next->previous = (*l);
	if ((*l)->previous)
		(*l)->previous->next = (*r);
	(*r)->next = (*l);
	(*l)->previous = (*r);
}
