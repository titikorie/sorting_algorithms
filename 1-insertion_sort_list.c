#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Dobule linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *curr = NULL, *prev = NULL;

	if (list && *list && (*list)->next)
	{
		temp = (*list)->next;

		while (temp) /* iterate to end of list */
		{
			curr = temp;
			prev = temp->prev;

			/* if values are not ascending */
			while (prev && curr->n < prev->n)
			{
				swap_nodes(&prev, &curr);
				if (prev == *list) /* if curr now list head */
					*list = curr;
				print_list(*list);
				/* if (curr->prev != NULL) if not at head of list */
				prev = curr->prev;
			}
			temp = temp->next;
		}
	}
}
/**
 *swap_node - swap two nodes
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	back->next = curr->next;
	if (curr->next)
		curr->next->prev = back;
	curr->next = back;
	curr->prev = back->prev;
	back->prev = curr;
	if (curr->prev)
		curr->prev->next = curr;
	else
		*list = curr;
	return (curr);
}
