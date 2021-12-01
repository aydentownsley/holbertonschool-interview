#include "search_algos.h"
#include <unistd.h>

/**
 * print_array - prints array (or section of) being searched
 *
 * @size: size of array
 * @array: array
 *
 * Return: None
 */

void print_array(int *array, size_t size)
{
	unsigned int i;

	if (size <= 0)
		return;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		if (i == size - 1)
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
	}
}

/**
 * adv_bin_help - add extra passable variable to help
 * keep track of elements are recusrion happens
 *
 * @array: array to search
 * @low: low value
 * @size: size of array
 * @value: value to look for
 *
 * Return: VALUE if found
 * -1 if not
 */
int adv_bin_help(int *array, unsigned int low, size_t size, int value)
{
	unsigned int mid = 0;

	mid = (size + low) / 2;

	if (low <= size)
	{
		if (array[mid] == value)
		{
			/*printf("==\n");*/
			if (array[mid - 1] == value && mid != 1)
			{
				print_array(&array[low], size - mid + 1);
				adv_bin_help(array, low, mid - 1, value);
				return (mid - 1);
			}
			return (mid);
		}
		if (array[mid] > value)
		{
			/*printf(">\n");*/
			print_array(&array[low], size - mid + 1);
			return (adv_bin_help(array, low, mid + 1, value));
		}
		if (array[mid] < value)
		{
			/*printf("<\n");*/
			print_array(&array[mid + 1], size - mid);
			return (adv_bin_help(array, mid + 1, size - 1, value));
		}
	}

	return (-1);
}

/**
 * advanced_binary - find item in array
 * if duplicates, return FIRST occurence
 *
 * @array: array to search
 * @size: size of array
 * @value: value to search for
 *
 * Return: index of VALUE if present
 */
int advanced_binary(int *array, size_t size, int value)
{
	unsigned int low = 0;

	if (array == NULL || size == 0)
		return (-1);

	print_array(array, size);
	return (adv_bin_help(array, low, size - 1, value));
}
