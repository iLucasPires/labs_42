#include "../includes/encoder.h"

static int	get_shared_block(char *file, uint size, uint segment)
{
	key_t	key;

	key = ftok((char *)file, (int)segment);
	if (key == ERROR)
		return (ERROR);
	return (shmget(key, size, 0644 | IPC_CREAT));
}

void	*attach_memory_block(char *file, uint size, uint segment)
{
	int	shared_block_id;

	shared_block_id = get_shared_block(file, size, segment);
	if (shared_block_id == ERROR)
		return (NULL);
	return (shmat(shared_block_id, NULL, 0));
}

short	detach_memory_block(void *block)
{
	return (shmdt(block) != ERROR);
}

short	destroy_memory_block(char *file, uint segment)
{
	int	shared_block_id;

	shared_block_id = get_shared_block(file, 0, segment);
	if (shared_block_id == ERROR)
		return (0);
	return (shmctl(shared_block_id, IPC_RMID, NULL) != ERROR);
}

void	*sharelloc(uint size, uint segment)
{
	void *block;

	block = attach_memory_block("./memory", size, segment);
	if (block == NULL)
		return (NULL);
	return (block);
}