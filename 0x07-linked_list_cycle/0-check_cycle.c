#include "lists.h"
#include <stdio.h>

/**
 * check_cycle - checks for cycle in a linked list
 *
 * @list: head of linked list
 *
 * Return: 0 if no cycle
 * OR 1 if cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *single = list, *dble = list;

	while (single != NULL && dble != NULL && dble->next != NULL)
	{
		single = single->next;
		dble = dble->next->next;

		if (single == dble)
			return (1);
	}
	return (0);
}
