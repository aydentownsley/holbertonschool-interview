#include <stdlib.h>
#include "binary_trees.h"

/**
 * fix_heap: fixes order of heap
 *
 * @node: node to move
 * Return: node
 */
heap_t *fix_heap(heap_t *node)
{
	heap_t *tmp;
	int tmp_n = 0;

	while (node != NULL && node->parent != NULL)
	{
		while (node->n > node->parent->n)
		{
			tmp = node;
			tmp_n = node->n;
			node = node->parent;
			tmp->n = node->n;
			node->n = tmp_n;
		}
	}
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
	heap_t *node, *curr = *root;

	/* start tree if empty */
	if (*root == NULL)
	{
		node = binary_tree_node(*root, value);
		*root = node;
		return (*root);
	}

	/* traverse to first null pos in heap */
	while (curr != NULL)
	{
		node = curr;

		if (curr->n == value)
			return (fix_heap(curr));

		if (curr->n < value)
			curr = curr->left;
		else
			curr = curr->right;

	}

	if (node->n > value)
	{
		node->right = binary_tree_node(node, value);
		return (node->right);
	}
	else
	{
		node->left = binary_tree_node(node, value);
		return (node->left);
	}
}
