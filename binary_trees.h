#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <limits.h>


/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

#define MAX(X, Y) ((X >= Y) ? X : Y)

typedef struct binary_tree_s binary_tree_t;

/* binary search tree */
typedef struct binary_tree_s bst_t;
/* AVL tree */
typedef struct binary_tree_s avl_t;
/* Max binary heap */
typedef struct binary_tree_s heap_t;

void binary_tree_print(const binary_tree_t *tree);


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
size_t binary_tree_height(const binary_tree_t *tree);

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

int binary_tree_is_avl(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *avl_inserter(avl_t **tree, int value);
void rotate_avl(avl_t **node);
avl_t *array_to_avl(int *array, size_t size);



#endif /* _BINARY_TREES_H_ */
