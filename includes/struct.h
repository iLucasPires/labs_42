#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_node
{
	unsigned char		data;
	unsigned int		frequency;
	struct s_node		*left;
	struct s_node		*right;
}						t_node;

typedef struct s_huffman
{
	t_node				*tree;
	t_node				**nodes;
	uchar 				*buffer;
	uint				buffer_size;
	uchar 				**dictionary;
	uint				*frequency;
	uint				len_symbols;
}						t_huffman;

typedef struct s_shared
{
	uint				*frequency;
	uchar				*compressed;
	uint				*size;
}						t_shared;


#endif