#include "binary_trees.h"

int binary_tree_is_avl(const binary_tree_t *tree)
{
	bool left, right;
	size_t left_height, right_height;

	if (tree == NULL)
		return (true);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (labs((long) left_height - (long) right_height) > 1)
		return (false);

	left = binary_tree_is_avl(tree->left);
	right = binary_tree_is_avl(tree->right);

	if (left && right)
		return true;
	else
		return false;
}
