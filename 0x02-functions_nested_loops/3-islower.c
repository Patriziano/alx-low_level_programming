#include "main.h"

/**
 * _islower - prints 1 if the input is a lowercase or 0 if otherwise
 *
 * @c: The chararcter in ASCII code
 *
 * Return: 1 for lowercase character. 0 if otherwise.
 */
int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');
}
