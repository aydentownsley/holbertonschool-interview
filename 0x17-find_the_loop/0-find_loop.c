#include <stdio.h>
#include "lists.h"

/**
 * find_listint_loop - find a loop, if present, in list.
 *
 * @head: list to check for loop
 *
 * Return: address of loop start
 */
listint_t *find_listint_loop(listint_t *head)
{
	if (head == NULL)
		return (NULL);

	listint_t *slow = head;
	listint_t *skip = head;

	slow = slow->next;
	skip = skip->next->next;

	while (slow && skip && skip->next)
	{
		if (slow == skip)
			break;
		slow = slow->next;
		skip = skip->next->next;
	}

	if (slow != skip)
		return (NULL);

	slow = head;
	while (slow != skip)
	{
		slow = slow->next;
		skip = skip->next;
	}

	return (slow);
}
