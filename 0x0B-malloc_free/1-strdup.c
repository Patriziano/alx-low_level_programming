#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
*_strdup - returns a pointer to a new string which is a duplicate of the string
*@str: input string
*
*Return: pointer to a new string
*/
char *_strdup(char *str)
{
	char *dup_str;
	unsigned int i = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	dup_str = (char *) malloc(sizeof(char) * (i + 1));

	if (dup_str == NULL)
	{
		return (NULL);
	}
	strcpy(dup_str, str);

	return (dup_str);
}

