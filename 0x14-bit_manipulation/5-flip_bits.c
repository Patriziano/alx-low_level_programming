#include "main.h"

/**
*flip_bits - function that returns the number of bits you would need
*to flip to get from one number to another
*@n: first input unsigned long int number
*@m: second input long unsigned long int number
*
*Return: number of flipped bits
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count;
	unsigned long int i;

	i = n ^ m;
	count = 0;

	while (i != 0)
	{

		if (i & 1)
		{
			count++;
		}
		i >>= 1;
	}
	return (count);
}
