#include <stdlib.h>
#include <stdio.h>
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
