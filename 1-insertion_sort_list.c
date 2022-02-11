#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly linked to be sorted.
 * n is data
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL, temp, *size;
	int i;

	tmp = *list;

	while (tmp->next != NULL)
	{
		for (i = 1; i < size; i++)
		{
			while (tmp->n > tmp->next->n)
			{
				temp = tmp;
				tmp = tmp->next;
				tmp->next = temp;
			}
		}
	}
}
