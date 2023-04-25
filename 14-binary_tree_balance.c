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
 * binary_tree_balance - Finds the height difference between two sides of
 * a binary tree
 * @tree: The tree or subtree to find the balance of
 * Return: The difference between the left and right sides of the binary tree
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_side = 0, right_side = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_side = 1 + binary_tree_height(tree->left);

	if (tree->right)
		right_side = 1 + binary_tree_height(tree->right);

	return (left_side - right_side);
}
