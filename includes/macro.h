#ifndef VARIABLE_MAGIC_H
# define VARIABLE_MAGIC_H

# define MAX_CHAR 256
# define ERROR -1
# define SUCCESS 0
# define BUFFER_SIZE 1024

/**
 * @brief BYTE_LEN
 * get the number of bytes needed to store x bits
 */
# define BYTE_LEN(x) ((x + CHAR_BIT - 1) / CHAR_BIT)

/**
 * @brief MASK
 * get the mask of the bit at position x
 */
# define MASK(x) (1 << (x % CHAR_BIT))

#endif