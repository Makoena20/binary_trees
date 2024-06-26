#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/* Libraries */
#include <stddef.h>

/* Structures */
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

/* Prototypes */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

void binary_tree_delete(binary_tree_t *tree);

int binary_tree_is_leaf(const binary_tree_t *node);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *);

binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);

binary_tree_t *binary_tree_sibling(binary_tree_t *node);

int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *);

int binary_tree_is_full(const binary_tree_t *tree);

size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);

size_t binary_tree_nodes(const binary_tree_t *tree);

size_t binary_tree_leaves(const binary_tree_t *tree);

/* Function Prototypes */
/* Task 5. Is a root */
int binary_tree_is_root(const binary_tree_t *node);

/* Function Prototypes (provided) */
void binary_tree_print(const binary_tree_t *);

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *);

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *tree);

size_t binary_tree_height(const binary_tree_t *tree);

size_t binary_tree_size(const binary_tree_t *tree);

size_t binary_tree_depth(const binary_tree_t *tree);

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);
int binary_tree_is_ancestor(const binary_tree_t *ancestor, const binary_tree_t *node);

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

int binary_tree_is_complete(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);

int binary_tree_is_complete(const binary_tree_t *tree);

/* Function to print binary tree */
void binary_tree_print(const binary_tree_t *);

/* Function to create a new node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* Function to delete a binary tree */
void binary_tree_delete(binary_tree_t *tree);

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

int binary_tree_is_bst(const binary_tree_t *tree);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *);

/* Binary Search Tree Node Structure */
typedef struct binary_tree_s bst_t;

/* Function Prototypes */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
bst_t *bst_insert(bst_t **tree, int value);
void binary_tree_print(const binary_tree_t *);

bst_t *array_to_bst(int *array, size_t size);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *);

bst_t *bst_search(const bst_t *tree, int value);

bst_t *bst_remove(bst_t *root, int value);

int binary_tree_is_avl(const binary_tree_t *tree);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value); 

/* Libraries */
#include <stddef.h>

/* Structures */
typedef struct binary_tree_s heap_t;

/* Function Prototypes */
int heap_extract(heap_t **root);
heap_t *binary_tree_node(heap_t *parent, int value);
size_t binary_tree_size(const heap_t *tree);
void binary_tree_print(const heap_t *tree);
void binary_tree_delete(heap_t *tree);

binary_tree_t *avl_insert(binary_tree_t **tree, int value);

heap_t *array_to_heap(int *array, size_t size);
void heapify(heap_t *node);
heap_t *heap_insert(heap_t **root, int value);
int heap_extract(heap_t **root);
void binary_tree_print(const binary_tree_t *tree);
void binary_tree_delete(binary_tree_t *tree);

/* AVL Tree Structure */
typedef struct binary_tree_s avl_t;

/* Function Prototypes */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *);

/* AVL Tree Specific Functions */
avl_t *array_to_avl(int *array, size_t size);
avl_t *avl_insert(avl_t **tree, int value);
int binary_tree_balance(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

#endif /* BINARY_TREES_H */

