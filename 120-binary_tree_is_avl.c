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
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left > right)
		return (left + 1);
	else
		return (right + 1);

}


/**
 * is_valid_bst_node - Check if a node disqualifies the tree from being a BST
 * @node: The node to check
 * Return: 1/true if it is a valid node, 0/false if invalid
*/

bool is_valid_bst_node(binary_tree_t *node)
{
	binary_tree_t *t_n;

	if (node == NULL || node->parent == NULL)
		return (true);

	for (t_n = node->parent; t_n != NULL; t_n = t_n->parent)
	{
		if (t_n == NULL)
			return (true);
		if (node->n < t_n->n)
		{
			printf("comparing %d to %d failed\n", node->n, t_n->n);
			return (false);
		}
	}
	return (true);
}

/**
 * binary_tree_is_avl - Check if the binary tree is an AVL tree
 * @tree: The binary tree to check
 * Return: 1/true if it is an AVL tree, 0/false if not
*/

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

	if (!is_valid_bst_node(tree->left))
		return (false);
	if (!is_valid_bst_node(tree->right))
		return (false);

	left = binary_tree_is_avl(tree->left);
	right = binary_tree_is_avl(tree->right);

	if (left && right)
		return (true);
	else
		return (false);
}
