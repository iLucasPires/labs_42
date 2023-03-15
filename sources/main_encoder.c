#include <encoder.h>

t_huffman	craete_huffman(uchar *buffer)
{
	t_huffman	var;

	var.buffer = buffer;
	var.buffer_size = strlen((char *)buffer);
	var.frequency = create_frequency_table(var.buffer);
	var.nodes = create_nodes(var.frequency);
	var.tree = create_tree(var.nodes, get_size_symbols(var.frequency));
	var.dictionary = create_dictionary(var.tree, get_level(var.tree));
	return (var);
}

void	destroy_huffman(t_huffman *var)
{
	destroy_dictionary(var->dictionary);
	destroy_tree(var->tree);
	free(var->nodes);
	free(var->frequency);
}

void	share_memory(t_huffman *var, t_shared *shared)
{
	uchar	*encoded;
	uchar	*compressed;
	uint	encoded_size;

	encoded = encoder(var->dictionary, var->buffer);
	compressed = compress(encoded);
	encoded_size = strlen((char *)encoded);
	shared->compressed = sharelloc(BYTE_LEN(encoded_size), 1);
	memcpy(shared->compressed, compressed, BYTE_LEN(encoded_size));
	shared->frequency = sharelloc(sizeof(uint) * CHAR_MAX, 2);
	memcpy(shared->frequency, var->frequency, sizeof(uint) * CHAR_MAX);
	shared->size = sharelloc(sizeof(uint), 3);
	*shared->size = strlen((char *)encoded);
	free(compressed);
	free(encoded);
}

void	detach_memory(t_shared *shared)
{
	detach_memory_block(shared->compressed);
	detach_memory_block(shared->frequency);
	detach_memory_block(shared->size);
}

int	main(int argc, char **argv)
{
	t_huffman var;
	t_shared shared;

	if (argc < 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}
	else if (argc > 2)
	{
		printf("Not support multiple files\n");
		return (1);
	}
	var.buffer = read_file((uchar *)argv[1]);
	if (var.buffer)
	{
		var = craete_huffman(var.buffer);
		share_memory(&var, &shared);
		detach_memory(&shared);
		destroy_huffman(&var);
		free(var.buffer);
	}
	return (0);
}