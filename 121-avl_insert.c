#include "binary_tree.h"
#include "binary_tree_balance.h"
#include "binary_tree_rotate_left.h"
#include "binary_tree_rotate_right.h"
#include "0-binary_tree_node.h"

/**
 * avl_insert - Inserts a value in an AVL tree
 * @tree: A double pointer to the root node of the AVL tree
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
binary_tree_t *avl_insert(binary_tree_t **tree, int value)
{
    if (tree == NULL)
        return (NULL);

    if (*tree == NULL)
        return (binary_tree_node(NULL, value));

    if ((*tree)->n == value)
        return (NULL);

    if (binary_tree_insert(*tree, value) == NULL)
        return (NULL);

    binary_tree_balance(*tree);

    if ((*tree)->parent != NULL && (*tree)->parent->bf == -2)
    {
        if ((*tree)->n < (*tree)->parent->left->n)
            *tree = binary_tree_rotate_right(*tree);
        else
        {
            (*tree)->parent->left = binary_tree_rotate_left((*tree)->parent->left);
            *tree = binary_tree_rotate_right(*tree);
        }
    }

    if ((*tree)->parent != NULL && (*tree)->parent->bf == 2)
    {
        if ((*tree)->n > (*tree)->parent->right->n)
            *tree = binary_tree_rotate_left(*tree);
        else
        {
            (*tree)->parent->right = binary_tree_rotate_right((*tree)->parent->right);
            *tree = binary_tree_rotate_left(*tree);
        }
    }

    return (*tree);
}
