#include <encoder.h>

uchar	*read_file(uchar  *txt)
{
	uchar	*buffer;
	FILE	*file;
	size_t	buffer_size;

	buffer_size = 0;
	file = fopen((const char *)txt, "r");
	if (file == NULL)
	{
		printf("Error: File not found\n");
		return (NULL);
	}
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	while (fread(buffer + buffer_size, 1, BUFFER_SIZE, file) > 0)
	{
		buffer_size += BUFFER_SIZE;
		buffer = realloc(buffer, buffer_size + BUFFER_SIZE);
	}
	fclose(file);
	return (buffer);
}
