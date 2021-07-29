#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Insert a node into a sorted list.
 * @head: head of list
 * @number: number to insert
 *
 * Return: address of new node
 * OR NULL if failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = (listint_t *)malloc(sizeof(listint_t));
	listint_t *curr = (listint_t *)malloc(sizeof(listint_t));

	new_node->n = number;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	curr = *head;

	if (number < (*head)->n)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	while (number > curr->n)
	{
		if (curr->next == NULL)
		{
			curr->next = new_node;
			return (new_node);
		}
		if (number <= curr->next->n)
		{
			new_node->next = curr->next;
			curr->next = new_node;
		}
		curr = curr->next;
	}
	return (NULL);
}
