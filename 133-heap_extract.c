#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 *
 * Return: value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    int value;
    heap_t *last_node, *temp;

    if (!root || !*root)
        return (0);

    value = (*root)->n;
    last_node = get_last_node(*root);

    if (*root == last_node) {
        free(*root);
        *root = NULL;
        return (value);
    }

    temp = *root;
    *root = last_node;
    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    else
        last_node->parent->right = NULL;

    last_node->parent = NULL;
    last_node->left = temp->left;
    last_node->right = temp->right;

    if (last_node->left)
        last_node->left->parent = last_node;
    if (last_node->right)
        last_node->right->parent = last_node;

    free(temp);

    heapify_down(*root);

    return (value);
}

/**
 * get_last_node - returns the last node of a binary tree
 * @root: pointer to the root node of the tree
 *
 * Return: pointer to the last node, or NULL if root is NULL
 */
heap_t *get_last_node(heap_t *root)
{
    if (!root)
        return (NULL);

    while (root->left || root->right) {
        if (root->right)
            root = root->right;
        else
            root = root->left;
    }

    return (root);
}

/**
 * heapify_down - restores the max heap property after extracting the root node
 * @root: pointer to the root node of the heap
 */
void heapify_down(heap_t *root)
{
    heap_t *largest, *temp;

    if (!root)
        return;

    largest = root;
    if (root->left && root->left->n > largest->n)
        largest = root->left;
    if (root->right && root->right->n > largest->n)
        largest = root->right;

    if (largest != root) {
        temp = largest->n;
        largest->n = root->n;
        root->n = temp;
        heapify_down(largest);
    }
}

