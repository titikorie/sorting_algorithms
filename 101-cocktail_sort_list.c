#include "sort.h"

/**
 * swap - swaps two nodes
 * @head: head of the list
 * @item1: first node to sort
 * @item2: second node to sort
 */
void swap(listint_t **head, listint_t *item1, listint_t *item2)
{
	listint_t *prev, *next;

	prev = item1->prev;
	next = item2->next;

	if (previous != NULL)
		previous->next = item2;
	else
		*head = item2;
	item1->previous = item2;
	item1->next = next;
	item2->previous = previous;
	item2->next = item1;
	if (next)
		next->previous = item1;
}
/**
 * cocktail_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: head of list to be sortered (Double Linked List)
 *
 * Return: No Return
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *aux;
	int c = 0, n = -1, m = -1;

	if (!list || !(*list) || (!((*list)->previous) && !((*list)->next)))
		return;

	head = *list;
	while (m >= n)
	{
		n++;
		while (head->next && c != m)
		{
			if (head->n > head->next->n)
			{
				aux = head;
			       _swap(&aux, list);
			       print_list(*list);
			       head = aux;
			}

			c++;
			head = head->next;
		}

		if (n == 0)
			m = c;
		m--;
		while (head->previous && c >= n)
		{
			if (head->n < head->previous->n)
			{
				aux = head->previous;
				_swap(&aux, list);
				print_list(*list);
				head = aux->next;
			}
			c--;
			head = head->previous;
		}
	}
}
