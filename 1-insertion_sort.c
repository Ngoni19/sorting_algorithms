#include "sort.h"


/**
 * swap_nodes -> swap nodes
 * @current: current pointer to the list
 * @list: The list
 */

void swap_nodes(listint_t *current, listint_t **list)
{
	listint_t *_frst, *next_f, *prev_f, *_two, *next_two, *prev_two = NULL;

	_frst = current;
	_two = current->next;
	next_f = _frst->next;
	if (_frst->prev)
		prev_f = _frst->prev;
	else
		prev_f = NULL;
	if (_two->next)
		next_two = _two->next;
	else
		next_two = NULL;
	prev_two = _two->prev;
	if (prev_f)
		prev_f->next = next_f;
	else
		*list = _two;
	if (next_two)
		next_two->prev = prev_two;
	_frst->next = next_two;
	_frst->prev = _two;
	_two->next = _frst;
	_two->prev = prev_f;
}

/**
 * insertion_sort_list - uses the insertion sort algorithm
 * @list: The list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *pr_now, *current;
	int tmp1 = 0, tmp2 = 0;

	if (!list)
		return;
	pr_now = *list;
	while (pr_now->next)
	{
		if (pr_now->n > pr_now->next->n)
		{
			swap_nodes(pr_now, list);
			print_list(*list);
			tmp1 = 1;
			current = pr_now->prev;

			while (current->prev)
			{
				if (current->prev->n > current->n)
				{
					swap_nodes(current->prev, list);
					print_list(*list);
					tmp2 = 1;
				}
				else
					break;
				if (!tmp2)
					current = current->prev;
				tmp2 = 0;
			}
		}
		if (!tmp1)
		pr_now = pr_now->next;
		tmp1 = 0;
	}
}
