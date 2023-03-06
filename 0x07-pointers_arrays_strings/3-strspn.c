#include "main.h"

/**
*_strspn - gets the length of a prefix substring
*@s: first string
*@accept: second string
*
*Return: a pointer to the byte in s or '\0'
*/
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	char *p;

	for (; *s; s++)
	{
	for (p = accept; *p; p++)
	{
	if (*s == *p)
	{
	count++;
	break;
	}
	}
	if (!*p)
	return count;
	}

	return (count);
}







