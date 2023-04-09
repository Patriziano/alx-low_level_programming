#include "main.h"

/**
*set_bit - function that sets the value of a bit to 1
* at a given index
*@n: input number unsigned long int
*@index: index starting from 0 of the expected bit
*
*/
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int can;

	can = 1UL << index;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	*n |= can;

	return (1);
}
