#include "binary_trees.h"

/**
 * array_to_avl - Create an AVL tree from an array of integers
 * @array: The array to create the AVL tree from
 * @size: The size of the array
 * Return: The root node of the crated AVL tree
*/

avl_t *array_to_avl(int *array, size_t size)
{
	size_t index = 0;
	avl_t *tree = NULL;

	for (; index < size; index++)
		avl_insert(&tree, array[index]);

	return (tree);
}
