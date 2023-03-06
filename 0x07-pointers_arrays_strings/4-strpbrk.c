#include "main.h"

/**
*_strpbrk - searches a string for any of a set of byte
*@s: first string of memory
*@accept: second string of memory
*
*Return: a pointer in s that matches accept otherwise return '\0'
*/
char *_strpbrk(char *s, char *accept)
{
	char *p;

	while (*s != '\0')
	{
		for (p = accept; *p != '\0'; ++p)
		{
			if (*s == *p)
			{
			return (s);
			}
		}
	++s;
	}

	return ('\0');
}
