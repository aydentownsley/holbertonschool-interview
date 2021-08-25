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
	int count, j, i = 0;
	listint_t *cursor;
	int array[5000];

	if (*head == NULL || head == NULL)
		return (0);

	cursor = *head;

	while (cursor != NULL)
	{
		array[count] = cursor->n;
		count++;
		cursor = cursor->next;
	}

	j = count - 1;
	for (i = 0; i <= count / 2; i++, j--)
	{
		if (array[i] != array[j])
			return (0);
	}

	return (1);
}
