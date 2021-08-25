#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 *
 * @head: head of list
 *
 * Return: 0 if not a palindrome
 * OR 1 if is a palindrome
 */

int is_palindrome(listint_t **head)
{
	listint_t *cursor = *head, *tailcheck = *head;
	int i = 0, idx = 0, itr = 0;

	while (cursor->next)
	{
		cursor = cursor->next;
		i++;
	}

	if (i == 0 || head == NULL)
		return (1);

	cursor = *head;
	for (idx = 0; idx < i; idx++)
	{
		tailcheck = *head;
		itr = 0;
		while (itr < (i - idx))
		{
			tailcheck = tailcheck->next;
			itr++;
		}
		if (tailcheck->n == cursor->n)
			cursor = cursor->next;
		else
			return (0);
	}

	return (1);
}
