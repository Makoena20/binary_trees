#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the tree, 0 if @tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size.
 *
 * Return: Size of the tree, 0 if @tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t height, size, index = 0;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	size = binary_tree_size(tree);

	return (is_complete_helper(tree, index, size, height));
}

/**
 * is_complete_helper - Recursive helper function for binary_tree_is_complete
 * @tree: Pointer to the current node in the tree.
 * @index: Index of the current node.
 * @size: Size of the tree.
 * @height: Height of the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int is_complete_helper(const binary_tree_t *tree, size_t index, size_t size, size_t height)
{
	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete_helper(tree->left, 2 * index + 1, size, height - 1) &&
	        is_complete_helper(tree->right, 2 * index + 2, size, height - 1));
}

