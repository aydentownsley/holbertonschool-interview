#include <stdio.h>
#include <stdlib.h>
#include "slide_line.h"

/**
 * slide_left - slide line left and combine
 * @line: line to slide
 * @new_line: new line
 * @size: size of line
 */
void slide_left(int *line, int *new_line, size_t size)
{
	size_t i = 0;
	int k = 0, l = size, temp = 0, pos = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (temp == line[i])
			{
				line[pos] = temp + line[i];
				line[i] = 0;
				temp = 0;
				pos = 0;
			}
			else
			{
				pos = i;
				temp = line[i];
			}
		}
		else
			continue;
	}
	for (i = 0, k = 0; i < size; i++)
	{
		if (line[i] == 0)
			continue;
		else
		{
			new_line[k] = line[i];
			k++;
		}
	}
	while (k <= l)
	{
		new_line[k] = 0;
		k++;
	}
	for (i = 0; i < size; i++)
		line[i] = new_line[i];
}

/**
 * slide_right - slide line right and combine
 * @line: line to slide
 * @new_line: new line
 * @size: size of line
 */
void slide_right(int *line, int *new_line, size_t size)
{
	size_t i = 0;
	int k = 0, l = 0, temp = 0, pos = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (temp == line[i])
			{
				line[pos] = temp + line[i];
				line[i] = 0;
				temp = 0;
				pos = 0;
			}
			else
			{
				pos = i;
				temp = line[i];
			}
		}
		else
			continue;
	}
	for (l = size - 1, k = size - 1; l >= 0; l--)
	{
		if (line[l] == 0)
			continue;
		else
		{
			new_line[k] = line[l];
			k--;
		}
	}
	while (k >= 0)
	{
		new_line[k] = 0;
		k--;
	}
	for (i = 0; i < size; i++)
		line[i] = new_line[i];
}

/**
 * slide_line - slide array values in array and add when
 * appropriate
 *
 * @line: Pointer to the array
 * @size: Number of elements in @line
 * @direction: direction to slide elementes in @line
 *
 * Return: 1 on success, or 0 on failure
 */

int slide_line(int *line, size_t size, int direction)
{
	int new_line[LINE_SIZE];

	if (size == 1)
		return (1);

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (line == NULL)
		return (0);

	if (size < 2)
		return (0);

	if (direction == SLIDE_LEFT)
		slide_left(line, new_line, size);

	if (direction == SLIDE_RIGHT)
		slide_right(line, new_line, size);

	return (1);
}
