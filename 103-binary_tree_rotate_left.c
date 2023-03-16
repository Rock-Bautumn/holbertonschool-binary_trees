
#include "binary_trees.h"


/*
*
* If root right child doesn't exist, do nothing
*
* Root right becomes new root
*/

/**
 * binary_tree_rotate_left - Rotates a binary search tree in a counter
 *  clockwise direction
 * @tree: The binary search tree to rotate
 * Return: The newly rotated binary search tree
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *old_root, *dangler;

	if (tree == NULL)
		return (tree);

	if (tree->right == NULL)
		return (tree);
	old_root = tree;
	new_root = old_root->right;
	dangler = new_root->left;

	new_root->parent = old_root->parent;
	new_root->left = old_root;
	old_root->parent = new_root;
	old_root->right = dangler;

	if (dangler != NULL)
		dangler->parent = old_root;

	return (new_root);
}

