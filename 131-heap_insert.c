#include "binary_trees.h"

/**
 * heap_insert - Inserts a value in a Max Binary Heap
 * @root: Pointer to the root node of the Heap
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;

    if (!root)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (!*root)
    {
        *root = new_node;
        return (new_node);
    }

    parent = find_parent(*root);
    new_node->parent = parent;

    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;

    heapify_up(new_node);

    return (new_node);
}

