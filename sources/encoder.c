#include <encoder.h>

uchar	*compress(uchar *encoded_data)
{
	uint	index;
	uint	len_bit;
	uint	mask;
	uint	encoded_len;
	uchar	*compacted_data;

	index = 0;
	encoded_len = strlen((char *)encoded_data);
	len_bit = BYTE_LEN(encoded_len);
	compacted_data = (uchar *)calloc(sizeof(uchar), len_bit);
	while (encoded_data[index] != '\0')
	{
		mask = MASK(index);
		if (encoded_data[index] == '1')
			compacted_data[index / CHAR_BIT] |= mask;
		else
			compacted_data[index / CHAR_BIT] &= ~mask;
		index++;
	}
	return (compacted_data);
}

uint	size_encoded_data(uchar **dictionary, uchar *data)
{
	uint	size;
	uint	index;

	size = 0;
	index = 0;
	while (data[index] != '\0')
	{
		size += strlen((char *)dictionary[data[index]]);
		index++;
	}
	return (size);
}

uchar	*encoder(uchar **dictionary, uchar *data)
{
	uint	index;
	uint	size;
	uchar	*encoded_data;

	index = 0;
	size = size_encoded_data(dictionary, data);
	encoded_data = calloc(sizeof(uchar), size + 1);
	while (data[index] != '\0')
	{
		strcat((char *)encoded_data, (char *)dictionary[data[index]]);
		index++;
	}
	return (encoded_data);
}