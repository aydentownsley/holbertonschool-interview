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

void print_array(int *array, size_t low, size_t size)
{
	unsigned int i;

	if (size <= 0)
		return;

	printf("Searching in array: ");
	for (i = low; i <= size; i++)
	{
		if (i < size)
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
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
int adv_bin_help(int *array, size_t low, size_t size, int value)
{
	size_t mid = 0;

	mid = (size + low) / 2;

	if (low <= size)
	{
		if (array[mid] == value)
		{
			/*printf("==\n");*/
			print_array(array, low, size);
			if (array[mid - 1] == value && mid != 0)
				adv_bin_help(array, low, mid, value);
			return (mid - 1);
		}
		if (array[mid] > value)
		{
			/*printf(">\n");*/
			print_array(array, low, size);
			return (adv_bin_help(array, low, mid, value));
		}
		if (array[mid] < value)
		{
			/*printf("<\n");*/
			print_array(array, low, size);
			return (adv_bin_help(array, mid + 1, size, value));
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

	return (adv_bin_help(array, low, size - 1, value));
}
