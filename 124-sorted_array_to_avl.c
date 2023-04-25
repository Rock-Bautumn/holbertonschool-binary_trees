#include "binary_trees.h"

/**
 * create_avl - (recursive) Create an AVL tree from an array
 * @array: The array to create the AVL tree from
 * @start: The position of the array to start creating nodes for
 * @end: The last position of the array to insert into the AVL tree
 * @parent: The parent of the created nodes
 * Return: The parent of the created nodes (the root node when done recursing)
*/

avl_t *create_avl(int *array, int start, int end, avl_t *parent)
{
	avl_t *node = NULL;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	node = malloc(sizeof(avl_t));
	node->n = array[mid];
	node->parent = parent;
	node->left = create_avl(array, start, mid - 1, node);
	node->right = create_avl(array, mid + 1, end, node);

	return (node);
}

/**
 * sorted_array_to_avl - Create an AVL tree from a sorted array of integers
 * @array: The sorted array to create the AVL tree from
 * @size: The size of the array
 * Return: The root node of the crated AVL tree
*/

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *new_tree = NULL;

	new_tree = create_avl(array, 0, size - 1, new_tree);

	return (new_tree);

}
