#include "binary_trees.h"

/**
 * heapify_down - Heapify down
 * @root: Pointer to the root of the heap
 */
void heapify_down(heap_t *root);

/**
 * get_tree_height - Get the height of the tree
 * @root: Pointer to the root of the tree
 * Return: Height of the tree
 */
size_t get_tree_height(const heap_t *root);

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of heap
 * Return: The value stored in the root node
 */
int heap_extract(heap_t **root)
{
    int value;
    heap_t *temp, *last;

    if (!root || !*root)
        return 0;

    value = (*root)->n;
    temp = *root;

    /* Find the last node */
    last = *root;
    while (last->left || last->right)
    {
        if (!last->right || last->left->n > last->right->n)
            last = last->left;
        else
            last = last->right;
    }

    /* Replace root with last node */
    if (last == *root)
        *root = NULL;
    else if (last->parent->left == last)
        last->parent->left = NULL;
    else
        last->parent->right = NULL;

    /* Free the last node */
    free(temp);

    if (*root)
    {
        (*root)->n = last->n;
        heapify_down(*root);
    }

    return value;
}

/**
 * heapify_down - Heapify down
 * @root: Pointer to the root of the heap
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

    if (largest != root)
    {
        temp = root->n;
        root->n = largest->n;
        largest->n = temp;
        heapify_down(largest);
    }
}

/**
 * get_tree_height - Get the height of the tree
 * @root: Pointer to the root of the tree
 * Return: Height of the tree
 */
size_t get_tree_height(const heap_t *root)
{
    size_t left_height, right_height;

    if (!root)
        return 0;

    left_height = get_tree_height(root->left);
    right_height = get_tree_height(root->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

