#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Dobule linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
		listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
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
