#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size.
 *
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is complete - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    size_t size, index = 0;

    if (tree == NULL)
        return (0);

    size = binary_tree_size(tree);

    return (binary_tree_is_complete_util(tree, index, size));
}

/**
 * binary_tree_is_complete_util - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 * @index: The index of the current node.
 * @size: The size of the tree.
 *
 * Return: If the tree is complete - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_complete_util(const binary_tree_t *tree, size_t index, size_t size)
{
    if (tree == NULL)
        return (1);

    if (index >= size)
        return (0);

    return (binary_tree_is_complete_util(tree->left, 2 * index + 1, size) &&
            binary_tree_is_complete_util(tree->right, 2 * index + 2, size));
}

