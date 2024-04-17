#include "binary_tree.h"

/**
 * new_node - creates a new binary tree node
 * @n: value to store in the node
 * @parent: pointer to the parent node
 *
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *new_node(int n, binary_tree_t *parent)
{
    binary_tree_t *node;

    node = malloc(sizeof(binary_tree_t));
    if (!node)
        return (NULL);

    node->n = n;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

/**
 * get_height - calculates the height of a binary tree node
 * @node: pointer to the node to measure the height
 *
 * Return: the height of the node, or 0 if node is NULL
 */
size_t get_height(const binary_tree_t *node)
{
    size_t left_height, right_height;

    if (!node)
        return (0);

    left_height = get_height(node->left);
    right_height = get_height(node->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * get_balance_factor - calculates the balance factor of a binary tree node
 * @node: pointer to the node to measure the balance factor
 *
 * Return: the balance factor of the node, or 0 if node is NULL
 */
int get_balance_factor(const binary_tree_t *node)
{
    if (!node)
        return (0);

    return (get_height(node->left) - get_height(node->right));
}

/**
 * rotate_right - performs a right rotation on a binary tree node
 * @node: pointer to the node to rotate
 *
 * Return: pointer to the new root node after rotation
 */
binary_tree_t *rotate_right(binary_tree_t *node)
{
    binary_tree_t *new_root, *left_node;

    if (!node || !node->left)
        return (NULL);

    new_root = node->left;
    left_node = new_root->right;

    new_root->parent = node->parent;
    new_root->right = node;
    node->parent = new_root;
    node->left = left_node;

    if (left_node)
        left_node->parent = node;

    return (new_root);
}

/**
 * rotate_left - performs a left rotation on a binary tree node
 * @node: pointer to the node to rotate
 *
 * Return: pointer to the new root node after rotation
 */
binary_tree_t *rotate_left(binary_tree_t *node)
{
    binary_tree_t *new_root, *right_node;

    if (!node || !node->right)
        return (NULL);

    new_root = node->right;
    right_node = new_root->left;

    new_root->parent = node->parent;
    new_root->left = node;
    node->parent = new_root;
    node->right = right_node;

    if (right_node)
        right_node->parent = node;

    return (new_root);
}

/**
 * rebalance - rebalances a binary tree node after insertion
 * @node: pointer to the node to rebalance
 *
 * Return: pointer to the rebalanced node, or NULL on failure
 */
binary_tree_t *rebalance(binary_tree_t *node)
{
    int bf;

    bf = get_balance_factor(node);

    if (bf > 1)
    {
        if (get_balance_factor(node->left) < 0)
            node->left = rotate_left(node->left);

        node = rotate_right(node);
    }
    else if (bf < -1)
    {
        if (get_balance_factor(node->right) > 0)
            node->right = rotate_right(node->right);

        node = rotate_left(node);
    }

    return (node);
}

/**
 * avl_insert - inserts a value in an AVL tree
 * @tree: double pointer to the root node of the AVL tree
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *node, *parent;

    if (!tree)
        return (NULL);

    node = new_node(value, NULL);
    if (!node)
        return (NULL);

    if (!*tree)
    {
        *tree = node;
        return (node);
    }

    parent = *tree;
    while (1)
    {
        if (node->n < parent->n)
        {
            if (!parent->left)
            {
                parent->left = node;
                node->parent = parent;
                break;
            }

            parent = parent->left;
        }
        else
        {
            if (!parent->right)
            {
                parent->right = node;
                node->parent = parent;
                break;
            }

            parent = parent->right;
        }
    }

    *tree = rebalance(parent);

    return (node);
}
