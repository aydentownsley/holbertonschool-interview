#include "search_algos.h"

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

	if (size == 0)
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
	unsigned int high = 0, mid = 0, low = 0;

	if (array == NULL || size == 0)
		return (-1);

	high = size - 1;

	print_array(array, size);

	while (low <= high)
	{
		mid = (high + low) / 2;

		if (array[mid] == value)
		{
			if (array[mid - 1] == value && mid != 1)
				mid = advanced_binary(array, mid + 1, value);
			return (mid);
		}
		else if (array[mid] > value)
		{
			high = mid - 1;
			print_array(&array[high], mid - low);
		}
		else if (array[mid] < value)
		{
			print_array(&array[mid + 1], high - mid);
			low = mid + 1;
		}
	}

	return (-1);
}
