#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
 * linear_skip - searches for an int in a skip list
 *
 * @list: list to search through
 * @value: value to search for
 *
 * Return: Pointer to value when found
 * OR NULL if list does not exist or value is not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *save, *sz, *l = list;
	size_t size = 0;

	if (list == NULL)
		return (NULL);
	for (sz = list; sz != NULL; sz = sz->next)
		size++;
	for (save = l; l != NULL; l = l->next)
	{
		while (l->express)
		{
			if (l->express->n < value)
			{
				l = l->express;
				save = l;
				printf("Value checked at index [%lu] = [%d]\n", save->index, save->n);
			}
			else
			{
				printf("Value checked at index [%lu] = [%d]\n", l->express->index, l->express->n);
				break;
			}
		}
		if (l->express)
			printf("Value found between indexes [%lu] and [%lu]\n", l->index, l->express->index);
		else
			printf("Value found between indexes [%lu] and [%lu]\n", l->index, size - 1);
		for (save = l; l != NULL; l = l->next)
		{
			printf("Value checked at index [%lu] = [%d]\n", l->index, l->n);
			if (l->n == value)
			{
				return (l);
			}
		}
		return (NULL);
	}

	return (NULL);
}
