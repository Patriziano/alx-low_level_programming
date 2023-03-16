#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
*_realloc - reallocates a memory block using malloc and free
*@ptr: pointer to the memory previously used
*@old_size: bytes of the allocated size
*@new_size: bytes of the new memory block
*
*Return: Always 0
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
		ptr = malloc(new_size);

	if (new_size == old_size)
		return (ptr);

	free(ptr);
	ptr = malloc(new_size);

	return (ptr);
}

