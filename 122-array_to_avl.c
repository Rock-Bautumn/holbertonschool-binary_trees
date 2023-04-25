#include "binary_trees.h"

avl_t *array_to_avl(int *array, size_t size)
{
	size_t index = 0;
	avl_t *tree;

	for (; index < size; index++)
		avl_insert(&tree, array[index]);

	return (tree);
}
