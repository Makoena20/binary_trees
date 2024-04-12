#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *new_root, *pivot;

    if (tree == NULL || tree->right == NULL)
        return (NULL);

    pivot = tree->right;
    new_root = pivot;
    tree->right = pivot->left;
    if (pivot->left != NULL)
        pivot->left->parent = tree;
    pivot->left = tree;
    pivot->parent = tree->parent;
    tree->parent = pivot;

    return (new_root);
}

