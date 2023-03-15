#include <encoder.h>

void	fill_dictionary(t_node *tree, uchar  **dictionary, uint level, uchar  *path)
{
	uchar 	path_left[level];
	uchar 	path_right[level];

	if (!tree->left && !tree->right)
		strcpy((char *)dictionary[tree->data], (char *)path);
	else
	{
		strcpy((char *)path_left, (char *)path);
		strcpy((char *)path_right, (char *)path);
		strcat((char *)path_left, "0");
		strcat((char *)path_right, "1");
		fill_dictionary(tree->left, dictionary, level, path_left);
		fill_dictionary(tree->right, dictionary, level, path_right);
	}
}

uchar 	**create_dictionary(t_node *tree, uint level)
{
	uint	index;
	uchar 	**dictionary;

	index = 0;
	dictionary = calloc(sizeof(uchar  *), MAX_CHAR);
	while (index < MAX_CHAR)
	{
		dictionary[index] = calloc(sizeof(uchar ), level + 1);
		index++;
	}
	fill_dictionary(tree, dictionary, level, (uchar  *)"");
	return (dictionary);
}

void	destroy_dictionary(uchar  **dictionary)
{
	int index;

	index = 0;
	while (index < MAX_CHAR)
	{
		free(dictionary[index]);
		index++;
	}
	free(dictionary);
}