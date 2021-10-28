#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * create_node - creates a new node
 *
 * @data: data to be stored in the new node
 * @root: root node of avl
 * Return: pointer to the new node
 */
avl_t *create_node(avl_t *root, int data)
{
	avl_t *new_node = malloc(sizeof(avl_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = data;
	new_node->left = NULL;
	new_node->right = NULL;

	if (root == NULL)
	{
		new_node->parent = NULL;
		root = new_node;
	}
	else
		new_node->parent = root;

	return (new_node);
}

/**
 * smart_insert - inserts node from sorted array in order
 *
 * @array: array of to be inserted
 * @begin: start of sorted array [section]
 * @end: end of sorted array [section]
 * @root: root node of avl
 *
 * Return: root of tree
 */
avl_t *smart_insert(int *array, int begin, int end, avl_t *root)
{
	int mid;

	if (begin > end)
		return (NULL);

	mid = (begin + end) / 2;
	root = create_node(root, array[mid]);

	root->left = smart_insert(array, begin, mid - 1, root);
	root->right = smart_insert(array, mid + 1, end, root);

	return (root);
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
	if (array == NULL || size == 0)
		return (NULL);

	return (smart_insert(array, 0, size - 1, NULL));
}
