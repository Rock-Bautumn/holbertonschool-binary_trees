
#include "binary_trees.h"


/* If root right child doesn't exist, do nothing */

/* Root right becomes new root */

/* We can ignore if the "old" root right child has a left child, that becomes the new right child
of the "old" root */

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
