#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
*str_concat - concatenates two strings
*@s1: first string
*@s2: second string
*
*Return: NULL on failure
*/
char *str_concat(char *s1, char *s2)
{
	char *cat;
	unsigned int i, j, k, limit;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++)
		;

	for (j = 0; s2[j] != '\0'; j++)
		;

	cat = malloc(sizeof(char) * (i + j + 1));

	if (cat == NULL)
	{
		free(cat);
		return (NULL);
	}

	for (k = 0; k < i; k++)
		cat[k] = s1[k];

	limit = j;
	for (j = 0; j <= limit; k++, j++)
		cat[k] = s2[j];

	return (cat);
}
