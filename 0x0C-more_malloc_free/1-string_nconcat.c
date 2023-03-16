#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
*string_nconcat - concatenates two strings
*@s1: first string
*@s2: second string
*@n: number of bytes
*
*Return: Always 0
*/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *result;
	unsigned int j, len1, len2, len;
	
	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (len1 = 0; s1[len1] != '\0'; len1++)
		;

	for (len2 = 0; s2[len2] != '\0'; len2++)
		;

	if (n > len2)
		n = len2;

	len = len1 + n;

	result = malloc(len + 1);

	if (result == NULL)
		return (NULL);

	for (j = 0; j < len; j++)
		if (j < len1)
			result[j] = s1[j];
		else
			result[j] = s2[j - len1];

	result[j] = '\0';

	return (result);
}

