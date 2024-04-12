#include "binary_trees.h"

/**
 * heap_extract - Extracts the root value of a Max Binary Heap
 * @heap: Pointer to the root node of the heap
 * Return: Value of the extracted node
 */
int heap_extract(heap_t **heap)
{
    int value;

    if (!heap || !*heap)
        return (0);

    value = (*heap)->n;
    /* swap root with the last node */
    if ((*heap)->left)
        heap_extract(&(*heap)->left);
    if ((*heap)->right)
        heap_extract(&(*heap)->right);
    free(*heap);
    *heap = NULL;
    return (value);
}

