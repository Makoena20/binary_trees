#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_extract - Extracts the root value of a Max Binary Heap
 * @heap: Pointer to the root node of the heap
 * @size: Pointer to store the size of the array
 * Return: Pointer to the sorted array
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *sorted_array;
    size_t i;

    if (!heap || !size)
        return (NULL);

    *size = binary_tree_size(heap);
    sorted_array = malloc(*size * sizeof(int));
    if (!sorted_array)
        return (NULL);

    for (i = 0; i < *size; i++)
        sorted_array[i] = heap_extract(&heap);

    return (sorted_array);
}

