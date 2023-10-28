#include "sort.h"

void swapping(listint_t **list, listint_t **mover, listint_t **partner);

/**
 * cocktail_sort_list - function for sorting an integer
 * linked list with cocktail sort in ascending order
 * @list: pointer to head of listint_t doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	int size = 0, count = 0;
	listint_t *partner = NULL, *mover = NULL, *start = NULL, *end = NULL;

	if (list == NULL)
		return;
	if ((*list) == NULL)
		return;
	mover = (*list);
	start = mover;
	while (mover)
	{
		size++;
		mover = mover->next;
	}
	mover = start;
	while (1)
	{
		while (mover && mover->next != end)
		{
			if (mover == start)
			{
				mover = mover->next;
				continue;
			}
			partner = mover->prev;
			if (partner->n > mover->n)
			{
				swapping(list, &mover, &partner);
				mover = mover->next->next;
			}
			else
				mover = mover->next;
		}
		while (mover->prev != NULL)
			mover = mover->prev;
		start = mover;
		while (mover->next != NULL)
			mover = mover->next;
		end = mover;
		while (mover)
		{
			if (mover->prev == NULL)
				break;
			partner = mover->prev;
			if (partner->n > mover->n)
				swapping(list, &mover, &partner);
			else
				mover = mover->prev;
		}
		mover = end;
		while (mover->next != NULL)
			mover = mover->next;
		end = mover;
		while (mover->prev != NULL)
			mover = mover->prev;
		start = mover;
		count++;
		if (count >= size / 2)
			break;
	}

}

/**
 * swapping - swaps two nodes in doubly linked list
 * @list: pointer to head of full list
 * @mover: pointer to mover node to switch with partner
 * @partner: pointer to partner node to switch with mover
 *
 */

void swapping(listint_t **list, listint_t **mover, listint_t **partner)
{
	(*partner)->next = (*mover)->next;
	(*mover)->prev = (*partner)->prev;
	if ((*mover)->next)
		(*mover)->next->prev = (*partner);
	if ((*partner)->prev)
		(*partner)->prev->next = (*mover);
	else
		(*list) = (*mover);
	(*mover)->next = (*partner);
	(*partner)->prev = (*mover);
	print_list(*list);
}
