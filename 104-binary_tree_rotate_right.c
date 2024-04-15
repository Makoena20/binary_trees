#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: A pointer to the root node of the tree to rotate
 *
 * Return: A pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    binary_tree_t *new_root, *temp;

    if (tree == NULL || tree->left == NULL)
        return (NULL);

    new_root = tree->left;
    temp = new_root->right;

    new_root->parent = tree->parent;
    if (new_root->parent != NULL)
    {
        if (new_root->parent->left == tree)
            new_root->parent->left = new_root;
        else
            new_root->parent->right = new_root;
    }

    new_root->right = tree;
    tree->parent = new_root;

    tree->left = temp;
    if (temp != NULL)
        temp->parent = tree;

    return (new_root);
}

