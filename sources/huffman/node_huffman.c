#include <encoder.h>

t_node	*create_node(uchar  data, uint frequency)
{
	t_node	*node;

	node = calloc(sizeof(t_node), 1);
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->frequency = frequency;
	return (node);
}

t_node	**create_nodes(uint *frequency)
{
	uint	index;
	uint	index_nodes;
	t_node	**nodes;

	index = 0;
	index_nodes = 0;
	nodes = calloc(sizeof(t_node *), MAX_CHAR);
	while (index < MAX_CHAR)
	{
		if (frequency[index] != 0)
		{
			nodes[index_nodes] = create_node((uchar )index, frequency[index]);
			index_nodes++;
		}
		index++;
	}
	return (nodes);
}

void	swap_nodes(t_node **nodes, uint index)
{
	t_node	*swap_node;

	swap_node = nodes[index];
	nodes[index] = nodes[index + 1];
	nodes[index + 1] = swap_node;
}

void	update_nodes(t_node **nodes)
{
	uint	index;

	index = 1;
	while (nodes[index + 1] != NULL)
	{
		nodes[index] = nodes[index + 1];
		index++;
	}
	nodes[index] = NULL;
}

t_node	*merge_nodes(t_node *f_node, t_node *s_node)
{
	t_node	*node;
	uint	frequency_sum;

	frequency_sum = f_node->frequency + s_node->frequency;
	node = create_node(0, frequency_sum);
	node->left = f_node;
	node->right = s_node;
	return (node);
}
