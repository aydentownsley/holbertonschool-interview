#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * smart_insert - inserts node from sorted array in order
 *
 * @array: array of to be inserted
 * @begin: start of sorted array [section]
 * @end: end of sorted array [section]
 *
 * Return: root of tree
 */
avl_t *smart_insert(int *array, int begin, int end)
{
	int mid;
	avl_t *root;
	avl_t *new_node = (avl_t *)malloc(sizeof(avl_t));

	if (new_node == NULL)
		return (NULL);

	if (begin > end)
		return (NULL);

	mid = (begin + end) / 2;
	root = new_node;
	root->n = array[mid];

	root->left = smart_insert(array, begin, mid - 1);
	root->right = smart_insert(array, mid + 1, end);

	return root;
}

/**
 * sorted_array_to_avl - creates an AVL tree from a sorted array
 * @array: array of integers
 * @size: size of array
 *
 * Return: pointer to the root node of the created AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	size_t begin = 0, end = size - 1;
	avl_t *root;

	root = smart_insert(array, begin, end);

	return (root);
}
