#include "main.h"

/**
*clear_bit - function that sets the value of a bit to 0
*at a given index
*@n: unsigned long int input number
*@index: index starting from 0 of the expected bit
*
*Return: 1
*/
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int can;

	can = ~(1UL << index);

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	*n &= can;

	return (1);
}
