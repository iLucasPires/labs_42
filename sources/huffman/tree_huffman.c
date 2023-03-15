#include "encoder.h"

t_node	*create_tree(t_node **nodes, uint len_symbols)
{
	if (len_symbols == 1)
		return (nodes[0]);
	sort_nodes(nodes, len_symbols);
	while (len_symbols > 1)
	{
		nodes[0] = merge_nodes(nodes[0], nodes[1]);
		update_nodes(nodes);
		len_symbols--;
		sort_nodes(nodes, len_symbols);
	}
	return (nodes[0]);
}

void	destroy_tree(t_node *tree)
{
	if (tree->left)
		destroy_tree(tree->left);
	if (tree->right)
		destroy_tree(tree->right);
	free(tree);
}