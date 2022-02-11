#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly linked to be sorted.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL;

	tmp = *list;

	while (tmp->next != NULL)
	{
		if (tmp->n > tmp->next->n)
		{
			tmp->next->prev = tmp->prev;
		}
		if (tmp->next->prev != NULL)
		{
			tmp->prev->next = tmp->next;
		}
		else
			*list = tmp->next;
		tmp->prev = tmp->next;
		tmp->next = tmp->next->next;

		if (tmp->next)
		{
			tmp->next->prev = tmp;
		}
		tmp = tmp->prev;
		print_list(*list);
	}
	if ((*list) == NULL)
		return;
}
