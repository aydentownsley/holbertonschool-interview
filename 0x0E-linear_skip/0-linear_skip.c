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
	skiplist_t *save, *sz;
	size_t size = 0;

	if (list == NULL)
		return (NULL);

	for (sz = list; sz != NULL; sz = sz->next)
		size++;

	for (save = list; list != NULL; list = list->next)
	{
		while (list->express)
		{
			if (list->express->n <= value)
			{
				list = list->express;
				save = list;
				printf("Value checked at index [%lu] = [%d]\n", save->index, save->n);
			}
			else
			{
				printf("Value checked at index [%lu] = [%d]\n", list->express->index, list->express->n);
				break;
			}
		}
		if (list->express)
			printf("Value found between indexes [%lu] and [%lu]\n", list->index, list->express->index);
		else
			printf("Value found between indexes [%lu] and [%lu]\n", list->index, size - 1);
		for (save = list; list != NULL; list = list->next)
		{
			printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
			if (list->n == value)
			{
				return (list);
			}
		}
		return (NULL);
	}

	return (NULL);
}
