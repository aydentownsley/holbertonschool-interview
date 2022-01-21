#include "sort.h"

/**
 * merge - workhorse of merge sort
 * @array: array to merge
 * @newArray: array to merge
 * @size: array size
 */
void merge(int *array, int *newArray, size_t size)
{
	int arrayMiddle = (int)size / 2, i = 0, j = 0, l = 0;

	l = arrayMiddle;

	printf("Merging...\n[left]: ");
	print_array(array, arrayMiddle);
	printf("[right]: ");
	print_array(array + arrayMiddle, size - arrayMiddle);

	for (i = 0; j < (int)size; j++)
	{
		if (i < arrayMiddle && (l == (int)size || array[i] <= array[l]))
		{
			newArray[j] = array[i];
			i++;
		}
		else
		{
			newArray[j] = array[l];
			l++;
		}
	}

	for (i = 0; i < (int)size; i++)
		array[i] = newArray[i];

	printf("[Done]: ");
	print_array(newArray, size);
}

/**
 * split - splitting array to sort and merge
 * @newArray: Array to help merge process
 * @array: array to sort
 * @size: size of array to sort
 */
void split(int *array, int *newArray, size_t size)
{
	int arrayMiddle = (int)size / 2;

	if (size < 2)
		return;

	split(array, newArray, arrayMiddle);
	split(array + arrayMiddle, newArray, size - arrayMiddle);
	merge(array, newArray, size);
}

/**
 * merge_sort - funciton to sort an array using merge sort
 * @array: Array to sort
 * @size:size of array
 */
void merge_sort(int *array, size_t size)
{
	int *newArray = NULL, i = 0;

	newArray = malloc(sizeof(int) * size);

	for (i = 0; i < (int)size; i++)
		newArray[i] = array[i];

	split(array, newArray, size);
	free(newArray);
}
