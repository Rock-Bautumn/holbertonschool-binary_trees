#include "binary_trees.h"

/**
 * rotate_avl - Rotate the AVL tree so that it is balanced again
 * @node: The address of the pointer to the node to rotate around
 * Return: void
 */
void rotate_avl(avl_t **node, int value)
{
	int balance;

	balance = binary_tree_balance(*node);

	if (balance > 1 && value < (*node)->left->n)
	{
		*node = binary_tree_rotate_right(*node);
		return;
	}

	if (balance < -1 && value > (*node)->right->n)
	{
		*node = binary_tree_rotate_left(*node);
		return;
	}

	if (balance > 1 && value > (*node)->left->n)
	{
		(*node)->left = binary_tree_rotate_left((*node)->left);
		*node = binary_tree_rotate_right(*node);
		return;
	}

	if (balance < -1 && value < (*node)->right->n)
	{
		(*node)->right = binary_tree_rotate_right((*node)->right);
		*node = binary_tree_rotate_left(*node);
		return;
	}
}

/**
 * avl_inserter - Inserts the value into the AVL tree
 * @tree: The address of the pointer of the root node
 * @value: The value to store inside of the AVL tree
 * Return: The address of the newly created node
 */
avl_t *avl_inserter(avl_t **tree, int value)
{

	avl_t *new_node;

	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}

		new_node = avl_inserter(&((*tree)->left), value);
		if (new_node)
			rotate_avl(tree, value);
		return (new_node);
	}

	if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}

		new_node = avl_inserter(&((*tree)->right), value);
		if (new_node)
			rotate_avl(tree, value);
		return (new_node);
	}
	return (NULL);
}

/**
 * avl_insert - Add a value to an AVL tree
 * @tree: The address of the pointer to the root node of the AVL tree
 * @value: The value to add to the AVL tree
 * Return: The address of the newly created node, NULL if failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	new_node = avl_inserter(tree, value);

	return (new_node);
}
