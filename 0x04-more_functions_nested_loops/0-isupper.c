#include "main.h"

/**
 * _isupper - Prints 1 if the input value is uppercase
 * otherwise print 0
 *
 * @c: The character in ASCII table
 *
 * Return: 1 if uppercase, 0 if otherwise.
 */

int _isupper(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
