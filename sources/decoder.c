#include <encoder.h>

uchar	*decompress(uchar *compacted_data, uint len_bit)
{
	uint	index;
	uchar	*descompressed_data;

	index = 0;
	descompressed_data = calloc(sizeof(uchar), len_bit + 1);
	while (index < len_bit)
	{
		if (compacted_data[index / CHAR_BIT] & MASK(index))
			descompressed_data[index] = '1';
		else
			descompressed_data[index] = '0';
		index++;
	}
	return (descompressed_data);
}

uchar	*decoder(t_node *tree, uchar *encoded_data)
{
	uint index;
	t_node *current_node;
	uchar *decoded_data;
	uchar decoded_symbol;

	index = 0;
	current_node = tree;
	decoded_data = calloc(sizeof(uchar), strlen((char *)encoded_data) + 1);
	while (encoded_data[index] != '\0')
	{
		if (encoded_data[index] == '0')
			current_node = current_node->left;
		else
			current_node = current_node->right;
		if (current_node->left == NULL && current_node->right == NULL)
		{
			decoded_symbol = current_node->data;
			strcat((char *)decoded_data, (char *)&decoded_symbol);
			current_node = tree;
		}
		index++;
	}
	return (decoded_data);
}