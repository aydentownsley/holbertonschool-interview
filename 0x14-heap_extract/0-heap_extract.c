#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * heapify - re heaps the heap
 * @root: root of tree
 * Return: void
 */
void heapify(heap_t *root)
{
	int temp;
	heap_t *max;

	if (root->left == NULL && root->right == NULL)
		return;

	max = root->left;

	if (root->right && root->right->n > max->n)
		max = root->right;

	if (max->n > root->n)
	{
		temp = root->n;
		root->n = max->n;
		max->n = temp;
		heapify(max);
	}
}

/**
 * find_height - finds the heighth of the tree
 * @tree: the tree
 *
 * Return: the height
*/
int find_height(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (tree == NULL)
		return (0);

	left = find_height(tree->left);
	right = find_height(tree->right);

	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}

/**
 * last_level - find the last level node of tree
 * @root: root of tree
 *
 * Return: last level node
 */
heap_t *last_level(heap_t *root)
{
	int lheight = 0, rheight = 0;

	if (root->left == NULL && root->right == NULL)
		return (root);
	if (root->left)
		lheight = find_height(root->left);
	if (root->right)
		rheight = find_height(root->right);
	if (lheight == rheight)
		return (last_level(root->right));
	return (last_level(root->left));
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
	heap_t *temp;

	if (*root == NULL || root == NULL)
		return (value);

	value = (*root)->n;

	/* if heap is only one node */
	if ((*root)->left == NULL)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	temp = last_level(*root);
	(*root)->n = temp->n;

	if (temp->parent->right == temp)
		temp->parent->right = NULL;
	else
		temp->parent->left = NULL;

	heapify(*root);
	free(temp);
	return (value);
}
