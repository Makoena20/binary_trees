#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree for inserting the value
 * @value: The value to store in the node to be inserted
 * Return: A pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (!tree)
        return NULL;

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        if (!*tree)
            return NULL;
        return *tree;
    }

    if (value < (*tree)->n)
    {
        (*tree)->left = avl_insert(&((*tree)->left), value);
        if (!(*tree)->left)
            return NULL;
    }
    else if (value > (*tree)->n)
    {
        (*tree)->right = avl_insert(&((*tree)->right), value);
        if (!(*tree)->right)
            return NULL;
    }
    else
    {
        // Value already exists, do not insert
        return NULL;
    }

    // Update height of current node
    (*tree)->height = 1 + MAX(avl_height((*tree)->left), avl_height((*tree)->right));

    // Check balance factor and perform rotations if needed
    int balance = avl_balance_factor(*tree);

    // Left Left Case
    if (balance > 1 && value < (*tree)->left->n)
        return avl_rotate_right(*tree);

    // Right Right Case
    if (balance < -1 && value > (*tree)->right->n)
        return avl_rotate_left(*tree);

    // Left Right Case
    if (balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = avl_rotate_left((*tree)->left);
        return avl_rotate_right(*tree);
    }

    // Right Left Case
    if (balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = avl_rotate_right((*tree)->right);
        return avl_rotate_left(*tree);
    }

    return *tree;
}

