#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Pointer to the root of the AVL tree
 * @value: Value to insert in the AVL tree
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (!tree)
        return (NULL);

    if (!*tree)
    {
        *tree = binary_tree_node(NULL, value);
        if (!*tree)
            return (NULL);
        return (*tree);
    }

    if (value < (*tree)->n)
    {
        (*tree)->left = avl_insert(&((*tree)->left), value);
        if (!(*tree)->left)
            return (NULL);
    }
    else if (value > (*tree)->n)
    {
        (*tree)->right = avl_insert(&((*tree)->right), value);
        if (!(*tree)->right)
            return (NULL);
    }
    else
    {
        /* Value already exists, ignore */
        return (*tree);
    }

    return (*tree);
}

