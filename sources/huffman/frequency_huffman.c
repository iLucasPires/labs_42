#include <encoder.h>

uint	*create_frequency_table(uchar  *buffer)
{
	uint	index;
	uint	*frequency;

	index = 0;
	frequency = (uint *)calloc(MAX_CHAR, sizeof(uint));
	while (buffer[index])
	{
		frequency[buffer[index]]++;
		index++;
	}
	return (frequency);
}
