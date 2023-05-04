#include "main.h"
#include <stdlib.h>

/**
*get_bit - function that returns the value of a bit
*at a given index
*@n: unsigned long int
*@index: index from 0 of the expected bit
*
*Return: value of the bit at index
*/
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int close;

	close = 1UL << index;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	if ((n & close) == 0)
	{
		return (0);
	}

	else
	{
		return (1);
	}
}

