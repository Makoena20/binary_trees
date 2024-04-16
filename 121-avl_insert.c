#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL tree
 * @tree: A double pointer to the root node of the AVL tree for inserting the value
 * @value: The value to store in the node to be inserted
 * Return: A pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (!tree)
        return NULL;

    if (!*tree)
    {
        *tree = binary_tree_node(NULL, value);
        if (!*tree)
            return NULL;
        return *tree;
    }

    if (value < (*tree)->n)
    {
        (*tree)->left = avl_insert(&((*tree)->left), value);
    }
    else if (value > (*tree)->n)
    {
        (*tree)->right = avl_insert(&((*tree)->right), value);
    }
    else
    {
        // Value already exists
        return NULL;
    }

    // Update height
    (*tree)->height = 1 + max(avl_height((*tree)->left), avl_height((*tree)->right));

    // Get balance factor
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

/**
 * avl_height - Measures the height of an AVL tree
 * @tree: A pointer to the root node of the AVL tree
 * Return: The height of the AVL tree
 */
int avl_height(const avl_t *tree)
{
    if (!tree)
        return 0;
    return tree->height;
}

/**
 * avl_balance_factor - Calculates the balance factor of an AVL tree
 * @tree: A pointer to the root node of the AVL tree
 * Return: The balance factor of the AVL tree
 */
int avl_balance_factor(const avl_t *tree)
{
    if (!tree)
        return 0;
    return avl_height(tree->left) - avl_height(tree->right);
}

/**
 * avl_rotate_right - Performs a right rotation on an AVL tree
 * @y: A pointer to the root node of the AVL tree
 * Return: A pointer to the new root node of the rotated tree
 */
avl_t *avl_rotate_right(avl_t *y)
{
    avl_t *x = y->left;
    avl_t *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(avl_height(y->left), avl_height(y->right)) + 1;
    x->height = max(avl_height(x->left), avl_height(x->right)) + 1;

    // Return new root
    return x;
}

/**
 * avl_rotate_left - Performs a left rotation on an AVL tree
 * @x: A pointer to the root node of the AVL tree
 * Return: A pointer to the new root node of the rotated tree
 */
avl_t *avl_rotate_left(avl_t *x)
{
    avl_t *y = x->right;
    avl_t *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(avl_height(x->left), avl_height(x->right)) + 1;
    y->height = max(avl_height(y->left), avl_height(y->right)) + 1;

    // Return new root
    return y;
}

/**
 * max - Returns the maximum of two integers
 * @a: First integer
 * @b: Second integer
 * Return: The maximum of the two integers
 */
int max(int a, int b)
{
    return (a > b) ? a : b;
}

