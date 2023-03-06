#include "main.h"

/**
*_memcpy - Copying memory area
*@n: number of bytes
*@dest: destination
*@src: source
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *dst_ptr = dest;
	const char *src_ptr = src;

	while (n-- > 0)
	{
	*dst_ptr++ = *src_ptr++;
	}

	return (dest);
}
