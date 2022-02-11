#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly linked to be sorted.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL, swap;

	tmp = *list;

	if ((*list) == NULL)
		return;

	while (tmp->next != NULL)
	{
		swap = tmp;
		if (swap->n < tmp->prev->n)
		{
			if (swap->next)
			{
				swap->next->prev = swap->prev;
			}
			if (swap->prev->prev)
			{
				swap->prev->prev->next = swap;
			}

		else
			*list = swap;
		tmp->prev = tmp->next;
		tmp->next = tmp->next->next;

		if (tmp->next)
		{
			tmp->next->prev = tmp;
		}
		tmp = tmp->prev;
		print_list(*list);
	}
}
