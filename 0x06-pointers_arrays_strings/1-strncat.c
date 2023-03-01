#include "main.h"

/**
 * _strncat - concatenates two strings with n bytes,
 * @dest: destination
 * @src: source code
 * @n: memory
 * Return: the pointer to dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	char *result = dest;

	while (*dest)
	{
	dest++;
	}
	while (*src && n--)
	{
	*dest++ = *src++;
	}
	*dest = '\0';
	return (result);
}
