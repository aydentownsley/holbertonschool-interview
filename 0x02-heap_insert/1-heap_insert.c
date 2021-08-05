#include <stdlib.h>
#include "binary_trees.h"

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
	heap_t *node = NULL;

	node = binary_tree_node(*root, value);

	if (node == NULL)
		return (NULL);

	node->left = NULL;
	node->right = NULL;
	node->parent = *root;

	return (node);
}
