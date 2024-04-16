#include "binary_trees.h"

/* Function prototypes */
int avl_height(const avl_t *tree);
int avl_balance_factor(const avl_t *tree);
avl_t *avl_rotate_right(avl_t *y);
avl_t *avl_rotate_left(avl_t *x);

/**
 * avl_height - Measure the height of an AVL tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree, or 0 if @tree is NULL
 */
int avl_height(const avl_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = avl_height(tree->left);
    right_height = avl_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * avl_balance_factor - Calculate the balance factor of an AVL tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Balance factor of the tree, or 0 if @tree is NULL
 */
int avl_balance_factor(const avl_t *tree)
{
    if (tree == NULL)
        return (0);

    return (avl_height(tree->left) - avl_height(tree->right));
}

/**
 * avl_rotate_right - Perform a right rotation on an AVL tree
 * @y: Pointer to the node to rotate around
 *
 * Return: Pointer to the new root of the subtree
 */
avl_t *avl_rotate_right(avl_t *y)
{
    avl_t *x = y->left;
    avl_t *T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

/**
 * avl_rotate_left - Perform a left rotation on an AVL tree
 * @x: Pointer to the node to rotate around
 *
 * Return: Pointer to the new root of the subtree
 */
avl_t *avl_rotate_left(avl_t *x)
{
    avl_t *y = x->right;
    avl_t *T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

/**
 * avl_insert - Insert a value into an AVL tree
 * @tree: Double pointer to the root node of the tree
 * @value: Value to insert
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return *tree;
    }

    if (value < (*tree)->n)
    {
        (*tree)->left = avl_insert(&(*tree)->left, value);
    }
    else if (value > (*tree)->n)
    {
        (*tree)->right = avl_insert(&(*tree)->right, value);
    }
    else
    {
        return NULL; /* Duplicates are not allowed in AVL trees */
    }

    /* Update height of this ancestor node */
    (*tree)->height = 1 + (avl_height((*tree)->left) > avl_height((*tree)->right) ? avl_height((*tree)->left) : avl_height((*tree)->right));

    /* Get the balance factor to check whether this node became unbalanced */
    int balance = avl_balance_factor(*tree);

    /* If this node becomes unbalanced, then there are 4 cases */

    /* Left Left Case */
    if (balance > 1 && value < (*tree)->left->n)
    {
        return avl_rotate_right(*tree);
    }

    /* Right Right Case */
    if (balance < -1 && value > (*tree)->right->n)
    {
        return avl_rotate_left(*tree);
    }

    /* Left Right Case */
    if (balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = avl_rotate_left((*tree)->left);
        return avl_rotate_right(*tree);
    }

    /* Right Left Case */
    if (balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = avl_rotate_right((*tree)->right);
        return avl_rotate_left(*tree);
    }

    /* Tree is still balanced */
    return *tree;
}

