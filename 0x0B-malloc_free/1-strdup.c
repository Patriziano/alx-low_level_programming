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
	unsigned int i, j;

	if (str == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		;
	}
	dup_str = (char *) malloc(sizeof(char) * (i + 1));

	if (dup_str == NULL)
	{
		return (NULL);
	}
	for (j = 0; j <= i; j++)
		dup_str[j] =  str[j];

	return (dup_str);
}
