#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    /* Compute the height of the left subtree */
    left_height = binary_tree_height(tree->left);

    /* Compute the height of the right subtree */
    right_height = binary_tree_height(tree->right);

    /* Return the maximum height of left or right subtree + 1 (current node) */
    if (left_height > right_height)
        return (left_height + 1);
    else
        return (right_height + 1);
}

