#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 *
 * @parent: the parent node
 * @value: the value of the node
 *
 * Return: a pointer to the newly created node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);

	node->n = value;

	if (parent == NULL)
		node->parent = NULL;
	else
		node->parent = parent;

	node->left = NULL;
	node->right = NULL;
	return (node);
}

/**
 * heap_insert - inserts value into a Max Binary Heap
 *
 * @root: root of tree
 * @value: the value of the node
 *
 * Return: a pointer to inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	binary_tree_t *node = NULL;

	node = binary_tree_node(*root, value);

	if (node == NULL)
		return (NULL);

	node->left = NULL;
	node->right = NULL;
	node->parent = *root;

	return (node);
}
