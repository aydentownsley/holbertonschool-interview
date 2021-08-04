#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_t - creates a binary tree node
 *
 * @parent: the parent node
 * @value: the value of the node
 *
 * Returns a pointer to the newly created node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
	{
		free (node);
		return NULL;
	}
	node->parent = parent;
	node->n = value;
	return (node);
}
