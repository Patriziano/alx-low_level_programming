#include "main.h"

/**
 * _isdigit - checks for a digit from 0 through 9
 *
 * @c: input digit from Ascii table
 *
 * Return: 1 if c is a digit, otherwise 0
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
