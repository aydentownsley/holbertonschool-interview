#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * max - finds max node value
 *
 * @root: root of heap
 *
 * Return: node with max value
 */
heap_t *max(heap_t *root)
{
	heap_t *curr_max, *left_max, *right_max;

		if (!root->left)
			return (root);
		left_max = max(root->left);
		if (left_max->n > root->n)
			curr_max = left_max;
		else
			curr_max = root;
		if (root->right)
		{
			right_max = max(root->right);
			if (right_max->n > curr_max->n)
				curr_max = right_max;
			else
				curr_max = root;
		}
		return (curr_max);
}

/**
 * extract - heavy lifting function. actually
 * removes the node from heap
 *
 * @root: root of heap
 *
 * Return: void
 */
void extract(heap_t *root)
{
	heap_t *left_max, *right_max = NULL;

	if (!root->left)
		return;
	left_max = max(root->left);
	if (root->right)
		right_max = max(root->right);
	if (right_max && right_max->n > left_max->n)
		left_max = right_max;
	root->n = left_max->n;
	if (!left_max->left)
	{
		if (left_max->parent && left_max->parent->left == left_max)
			left_max->parent->left = NULL;
		if (left_max->parent && left_max->parent->right == left_max)
			left_max->parent->right = NULL;
		free(left_max);
	}
	else
		extract(left_max);
}

/**
 * heap_extract - Extracts root node of a Max Heap
 * and replaces it with last level node. Rebuilding
 * the heap if neccessary.
 *
 * @root: root node of the Heap
 *
 * Return: return the value of the node extracted
 */
int heap_extract(heap_t **root)
{
	int value = 0;

	if (!*root)
		return (value);

	value = (*root)->n;

	/* if heap is only one node */
	if (!(*root)->left)
	{
		value = (*root)->n;
		free(*root);
		*root = NULL;
		return (value);
	}

	extract(*root);
	return (value);
}
