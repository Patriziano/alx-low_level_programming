#include "main.h"

/**
*is_prime_number - prints prime number
*@n: input number
*
*Return: 1 if its an integer, otherwise 0
*/
int is_prime_number(int n)
{
	int i;

	if (n <= 1)
	{
		return (0);
	}
	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return (0);
		}
	}
	return (1);
}

