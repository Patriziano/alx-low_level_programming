#include "main.h"
#include <stddef.h>

/**
*binary_to_uint - function that converts binary to an unsigned int
*@b: pointer pointing to a string of 0 and 1 chars
*
*Return: The converted number
*/
unsigned int binary_to_uint(const char *b)
{
	unsigned int feed = 0;
	int j = 0;

	if (b == NULL)
	{
		return (0);
	}

	while (b[j] != '\0')
	{
		if (b[j] == '1')
		{
			feed = (feed << 1) | 1;
		}
		else if (b[j] == '0')
		{
			feed = feed << 1;
		}

		else
		{
			return (0);
		}
		j++;
	}
	return (feed);
}
