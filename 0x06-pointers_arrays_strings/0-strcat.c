#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination
 * @src: source
 * Return: a pointer to dest destination
 */
char *_strcat(char *dest, char *src)
{
	char *result = dest;

	while (*dest)
	{
	dest++;
	}
	while (*src)
	{
	*dest++ = *src++;
	}
	*dest = '\0';
	return (result);
}
