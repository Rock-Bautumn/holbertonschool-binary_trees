#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Rotates a binary search tree in a
 *  clockwise direction
 * @tree: The binary search tree to rotate
 * Return: The newly rotated binary search tree
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *old_root, *dangler;

	if (tree == NULL)
		return (tree);

	if (tree->left == NULL)
		return (tree);
	old_root = tree;
	new_root = old_root->left;
	dangler = new_root->right;

	new_root->parent = old_root->parent;
	new_root->right = old_root;
	old_root->parent = new_root;
	old_root->left = dangler;

	if (dangler != NULL)
		dangler->parent = old_root;

	return (new_root);
}

