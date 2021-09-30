#include <stdio.h>
#include <stdlib.h>
#include "slide_line.h"

/**
 * slide_line - slide array values in array and add when
 * appropriate
 *
 * @line: Pointer to the array
 * @size: Number of elements in @line
 * @direction: direction to slide elementes in @line
 */

int slide_line(int *line, size_t size, int direction)
{
	size_t i;
	int k, l = size;
	int temp = 0, pos = 0;
	int new_line[LINE_SIZE];

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (line == NULL)
		return (0);

	if (size < 2)
		return (0);

	if (direction == SLIDE_LEFT)
	{
		/* combines compatible values of new_line */
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

		/** copies values from line to new_line while shifting them
		 * to the leftmost position possible
		 */
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

		/* fills remaining spaces of new_line with 0 */
		while (k <= l)
		{
			new_line[k] = 0;
			k++;
		}

		/* copies values from new_line to line */
		for (i = 0; i < size; i++)
			line[i] = new_line[i];
	}

	if (direction == SLIDE_RIGHT)
	{
		/* combines compatible values of new_line */
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

		/** copies values from line to new_line while shifting them
		 * to the rightmost position possible
		 */
		for (i = size, k = size; i > 0; i--)
		{
			if (line[i] == 0)
				continue;
			else
			{
				new_line[k] = line[i];
				k--;
			}
		}

		/* fills remaining spaces of new_line with 0 */
		while (k >= 0)
		{
			new_line[k] = 0;
			k--;
		}

		/* copies values from new_line to line */
		for (i = 0; i < size; i++)
			line[i] = new_line[i];
	}

	return (1);
}
