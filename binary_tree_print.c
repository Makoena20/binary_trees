#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
    if (tree == NULL)
        return;

    printf("%d\n", tree->n);
    if (tree->left != NULL || tree->right != NULL)
    {
        printf("Left:");
        if (tree->left != NULL)
            printf(" %d", tree->left->n);
        else
            printf(" (nil)");

        printf("\nRight:");
        if (tree->right != NULL)
            printf(" %d", tree->right->n);
        else
            printf(" (nil)");
    }
    printf("\n");

    binary_tree_print(tree->left);
    binary_tree_print(tree->right);
}

