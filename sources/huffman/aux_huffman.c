#include <encoder.h>

void	sort_nodes(t_node **nodes, uint len)
{
	bool	swapped;

	swapped = true;
	if (len == 1)
		return ;
	for (uint i = 0; i < len - 1; i++)
	{
		swapped = false;
		for (uint j = 0; j < len - i - 1; j++)
		{
			if (nodes[j]->frequency > nodes[j + 1]->frequency)
			{
				swap_nodes(nodes, j);
				swapped = true;
			}
		}
		if (swapped == false)
			return ;
	}
}

uint	get_level(t_node *tree)
{
	uint	left_height;
	uint	right_height;

	if (!tree)
		return (-1);
	left_height = get_level(tree->left) + 1;
	right_height = get_level(tree->right) + 1;
	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}

uint	get_size_symbols(uint *frequency)
{
	uint index;
	uint len_symbols;

	index = 0;
	len_symbols = 0;
	while (index < MAX_CHAR)
	{
		if (frequency[index] != 0)
			len_symbols++;
		index++;
	}
	return (len_symbols);
}