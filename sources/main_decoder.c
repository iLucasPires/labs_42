#include <encoder.h>

t_huffman	craete_huffman(uint *frequency)
{
	t_huffman	var;

	var.frequency = frequency;
	var.nodes = create_nodes(var.frequency);
	var.tree = create_tree(var.nodes, get_size_symbols(var.frequency));
	var.dictionary = create_dictionary(var.tree, get_level(var.tree));
	return (var);
}

void	share_memory(t_shared *shared)
{
	shared->compressed = sharelloc(0, 1);
	shared->frequency = sharelloc(0, 2);
	shared->size = sharelloc(0, 3);
}

void	detach_memory(t_shared *shared)
{
	detach_memory_block(shared->compressed);
	detach_memory_block(shared->frequency);
	detach_memory_block(shared->size);
}

void	destroy_memory(void)
{
	destroy_memory_block("./memory", 1);
	destroy_memory_block("./memory", 2);
	destroy_memory_block("./memory", 3);
}

void	destroy_huffman(t_huffman *var)
{
	destroy_dictionary(var->dictionary);
	destroy_tree(var->tree);
	free(var->nodes);
}

int	main(void)
{
	t_huffman var;
	t_shared shared;
	uchar *decoded_data;
	uchar *descompressed_data;

	share_memory(&shared);
	if (shared.compressed == NULL)
	{
		printf("Error: shared memory not created \n");
		return (0);
	}
	var = craete_huffman(shared.frequency);
	descompressed_data = decompress(shared.compressed, *shared.size);
	decoded_data = decoder(var.tree, descompressed_data);
	printf("%s \n", decoded_data);

	free(decoded_data);
	free(descompressed_data);
	destroy_huffman(&var);
	detach_memory(&shared);
	destroy_memory();
}