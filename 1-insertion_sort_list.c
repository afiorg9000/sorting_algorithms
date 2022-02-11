#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly linked to be sorted.
 * n is data
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *nxtNptr, *prevNptr, *traverse;
	/* nxtNptr is a temporary pointer to what list is pointing to*/


	if ((*list)->next == NULL)/*if the list is empty, it will stop*/
		return;

	for (nxtNptr = (*list); nxtNptr != NULL; nxtNptr = traverse)
		/*nxtNptr is the next node pointer to be checked*/
	{
		traverse = nxtNptr->next;
		/*points to the next node in order to move through the list*/
		prevNptr = nxtNptr->prev;
	/*previous node pointer to be checked*/
		while (prevNptr != NULL && nxtNptr->n < prevNptr->n)
		/**
		 * checks if there's a node &&
		 * checks wether the nxt ptr node (ex: 48),
		 * is less than the prev ptr node(ex: 19)
		 */
		{
			swap_nodes(list, &prevNptr, nxtNptr);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @left: A pointer to the first node to swap.
 * @right: the next node pointer to swap.
 */
void swap_nodes(listint_t **head, listint_t **left, listint_t *right)
{
	(*left)->next = right->next;/*prev node ptr is assigned the next pointer*/
	if (right->next != NULL)/*checkes wether the next pointer has data (node)*/
		right->next->prev = *left; 
	/*the next pointer (ex: 71) takes to the nxt pointer(ex: 13)
	 *and the previous node (ex: 13) and assigns it to the previous pointer(ex: 99)*/
	right->prev = (*left)->prev; 
	/*assigns the previous node of the right variable (1st entrance: 71)
	 * the previous node of the left variable (1st entrance: 99) to the sorted node*/
	right->next = *left;/*the right node pointers are assigned to the entirety of left*/
	if ((*left)->prev != NULL)
	/*checkes wether the previous pointer has data(node) when its finishing 13 will head to the else*/
	{
		(*left)->prev->next = right; 
		/*assigns the 71 to the 99; the previus pointer takes the previous pointer and assigns it to the next pointer*/
	}
	else
		*head = right; /*assigns the head 7*/
	(*left)->prev = right;/*assigns the previous node of 7 to 13 */
	*left = right->prev;/*assigns the previous node of 7 to its next ndoe 13 */
}
