#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
*binary_to_uint - converts a binary to an unsigned int
*@b: pointer to a string of   and 1 chars
*
*Return: The converted number
*/
unsigned int binary_to_uint(const char *b)
{
	unsigned int output;
	int i;

	output = 0;

	if (b == NULL)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] == '0')
		{
			output = output << 1;
		}
		else if (b[i] == '1')
		{
			output = (output << 1) | 1;
		}
		else
		{
			return (0);
		}
	}
	return (output);
}
