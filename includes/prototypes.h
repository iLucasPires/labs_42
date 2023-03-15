#ifndef PROTOTYPES_H
# define PROTOTYPES_H

/**
 * @brief Create a node object
 * 
 * @param data 
 * @param frequency 
 * @return t_node* 
 */
t_node	*create_node(uchar data, uint frequency);

/**
 * @brief Create a nodes object
 * 
 * @param len 
 * @return t_node** 
 */
t_node	**create_nodes(uint *frequency);

/**
 * @brief swap_nodes
 * 	- Swaps two nodes
 * @param nodes
 * @param index of the first node
 */
void	swap_nodes(t_node **nodes, uint index);

/**
 * @brief sort_nodes
 * 	- Sorts the nodes by frequency
 * @param nodes
 * @param index of the first node
 */
void	update_nodes(t_node **nodes);

/**
 * @brief merge_nodes
 * 	- Merges two nodes
 * @param f_node
 * @param s_node
 * @return Pointer to the new node
*/
t_node	*merge_nodes(t_node *f_node, t_node *s_node);

/**
 * @brief Create a frequency table object
 * 
 * @param buffer 
 * @return uint* 
 */
uint	*create_frequency_table(uchar *buffer);

/**
 * @brief sort_nodes
 * 	- Sorts the nodes by frequency
 * @param nodes
 * @param len_symbols
 */
t_node	*create_tree(t_node **nodes, uint len_symbols);

/**
 * @brief destroy_tree
 * 	- Frees the tree
 * @param tree
 */
void	destroy_tree(t_node *tree);

/**
 * @brief create_dictionary
 * 	- Creates the dictionary
 * @param tree
 * @param level
 * @return Pointer to the dictionary
 */
uchar	**create_dictionary(t_node *tree, uint level);

/**
 * @brief destroy_dictionary
 * 	- Frees the dictionary
 * @param dictionary
 */
void	destroy_dictionary(uchar **dictionary);

/**
 * @brief sort_nodes
 * 	- Sorts the nodes by frequency
 * @param nodes
 * @param len
 */
void	sort_nodes(t_node **nodes, uint len);

/**
 * @brief get_level
 * 	- Gets the level of a node in a tree
 * @param tree
 * @return The level of the node
 */
uint	get_level(t_node *tree);

uint	get_size_symbols(uint *frequency);

/**
 * @brief encoder
 * 	- Encodes the data
 * @param dictionary
 * @param data
 * @return Pointer to the encoded data
 */
uchar	*encoder(uchar **dictionary, uchar *data);

/**
* @brief decoder
* - Decodes the encoded data
* @param tree
* @param encoded_data
* @return Pointer to the decoded data
 */
uchar	*decoder(t_node *tree, uchar *encoded_data);

/**
 * @brief attach_memory_block
 * - Attaches a memory block to a file
 * @param file
 * @param size
 * @param segment
 * @return Pointer to the memory block

 */
void	*attach_memory_block(char *file, uint size, uint segment);

/**
 * @brief detach_memory_block
 * - Detaches a memory block from a file
 * @param block
 * @return 0 if success, -1 if failure
 */
short	detach_memory_block(void *block);

/**
 * @brief destroy_memory_block
 * - Destroys a memory block
 * @param file
 * @param segment
 * @return 0 if success, -1 if failure
 */
short	destroy_memory_block(char *file, uint segment);

/**
 * @brief compress
 * 	- Compresses the data
 * @param encoded_data
 * @return Pointer to the compressed data
 */
uchar	*compress(uchar *encoded_data);

/**
 * @brief decompress
 * 	- Decompresses the data
 * @param compacted_data
 * @param len_bit
 * @return Pointer to the decompressed data
 */
uchar	*decompress(uchar *compacted_data, uint len_bit);

/**
 * @brief sharelloc
 * - Allocates a memory block in a shared memory
 * @param size
 * @param segment
 * @return Pointer to the memory block
 */
void	*sharelloc(uint size, uint segment);

/**
 * @brief read_file
 * - Reads a file
 * @param txt
 * @return Pointer to the file
 */
uchar	*read_file(uchar *txt);
#endif