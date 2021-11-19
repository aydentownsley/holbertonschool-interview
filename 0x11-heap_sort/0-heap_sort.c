#include "sort.h"

/**
 * heap - makes heap
 * @array: array
 * @size: size of sub array passed
 * @root: swap point
 * @print_size: total size of array
 * Return: void
 */

void heap(int *array, size_t size, size_t root, size_t print_size)
{
	int tmp;
	size_t big = root;
	size_t left = (2 * root) + 1;
	size_t right = (2 * root) + 2;

	if (left < size && array[left] > array[big])
		big = left;

	if (right < size && array[right] > array[big])
		big = right;

	if (big != root)
	{
		tmp = array[root];
		array[root] = array[big];
		array[big] = tmp;

		print_array(array, print_size);

		heap(array, size, big, print_size);
	}
}

/**
 * heap_sort - sort by binary tree
 * @array: array to sort
 * @size: size of array
 * Return: VOID
 */

void heap_sort(int *array, size_t size)
{
	int idx, tmp;

	for (idx = (size / 2) - 1; idx >= 0; idx--)
		heap(array, size, idx, size);

	for (idx = (size - 1); idx >= 0; idx--)
	{
		tmp = array[0];
		array[0] = array[idx];
		array[idx] = tmp;

		if (idx != 0)
			print_array(array, size);

		heap(array, idx, 0, size);
	}
}
