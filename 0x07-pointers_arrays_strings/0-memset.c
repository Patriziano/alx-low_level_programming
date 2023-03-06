#include "main.h"

/**
*_memset - a function that fills memory with a constant byte
*@n: number of byte
*@s: memory area
*@b: constant byte
*
*Return: s
*/

char *_memset(char *s, char b, unsigned int n)
{
	char *ptr = s;

	while (n--)
	{
	*ptr++ = b;
	}
	return (s);
}


