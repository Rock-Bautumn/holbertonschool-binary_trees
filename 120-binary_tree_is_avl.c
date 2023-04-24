#include "binary_trees.h"


/**
 * binary_tree_height - Calculates the height of child nodes from the given
 * tree
 * @tree: The tree to calculate the height of
 * Return: The height of the tree
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (false);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}

/**
 * is_balanced - Check if the binary tree is balanced (not more than a
 * difference of 1 in height)
 * @tree: The tree or subtree to check
 * Return: true if balanced, false if unbalanced
*/
int is_balanced(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (true);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	if (abs(left_height - right_height) > 1)
		return (false);

	return (is_balanced(tree->left) && is_balanced(tree->right));
}

/**
 * is_avl - Check if a binary tree is a valid avl tree (!!! not necessarily
 *  valid binary search tree)
 * @tree: The tree or subtree to check
 * Return: true if avl tree, false if not (!!! not necessarily a valid binary
 * search tree)
*/
int is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (true);

	if (abs((int)(binary_tree_height(
		tree->left) - binary_tree_height(tree->right))) > 1)
		return (false);

	return (is_avl(tree->left) && is_avl(tree->right) && is_balanced(tree));
}

/**
 * is_bst - Check if the binary tree is a valid binary search tree. This
 * function works recursively and has no entry function. When this is used as
 * the initial call, you must use INT_MIN for the min and INT_MAX for the max.
 * @tree: The tree or subtree to check
 * @min: The initial call should use INT_MIN
 * @max: The initial call should use INT_MAX
 * Return: true if valid binary search tree, false if invalid
*/

int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (true);

	if (tree->n < min || tree->n > max)
	return (false);

	return (is_bst(tree->left, min, tree->n - 1) &&
		is_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - Checks whether a binary tree is a valid AVL binary
 * search tree
 * @tree: The tree or subtree to do the check on
 * Return: true if valid, false if invalid
*/

int binary_tree_is_avl(const binary_tree_t *tree)
{
	return (is_avl(tree) && is_bst(tree, INT_MIN, INT_MAX));
}
