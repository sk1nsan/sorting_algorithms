#include "sort.h"

/**
 * swap - swap 2 nodes
 *
 * @list1: first node
 * @list2: second node
 *
 * Return: Nothing
*/
void swap(listint_t *list1, listint_t *list2)
{
	listint_t *buf = list1->next;

	list1->next = list2;
	list1->prev = list2->prev;
	if (list2->prev)
		(list2->prev)->next = list1;
	list2->prev = list1;
	list2->next = buf;
	if (buf)
		buf->prev = list2;
}

/**
 * insertion_sort_list - sorting using insertion algo
 *
 * @list: list to be sorted
 *
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *prev, *buf, *buf2;

	if (!list || !(*list))
		return;
	cur = (*list)->next;
	for (; cur; cur = cur->next)
	{
		for (prev = cur->prev, buf = cur; prev; prev = prev->prev, buf = buf->prev)
		{
			if (prev->n > buf->n)
			{
				swap(buf, prev);
				buf2 = buf;
				buf = prev;
				prev = buf2;
				cur = buf;
				if (!(prev->prev))
					*list = prev;
				print_list(*list);
			}
		}
	}
}
